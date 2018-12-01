const RL1 = 0x40;
const RL2 = 0x80;

function rleCompress(data, runLength1, runLength2) {
    let i = 0;
    let compressedData = [];

    while(i < data.length) {
        if (data[i] >= RL2) {
            throw new Error('tile data goes beyond 0x3F, cant compress it');
        }

        let n = i;
        while (data[n] === data[i] && n < data.length) {
            ++n;
        }

        let currentRunLength = n - i;

        while (currentRunLength > runLength1) {
            compressedData.push(RL1 | data[i]);
            currentRunLength -= runLength1;
        }

        while (currentRunLength > runLength2) {
            compressedData.push(RL2 | data[i]);
            currentRunLength -= runLength2;
        }

        while (currentRunLength) {
            compressedData.push(data[i]);
            --currentRunLength;
        }

        i = n;

    }
    
    return compressedData;
}

const runLengths = [
    [20, 10],
    [10, 5],
    [16, 8],
    [12, 6],
    [10, 5],
    [8, 4],
    [6, 3],
    [5, 3],
    [5, 2]
];

module.exports = function buildMapArray(name, layer, tileSize) {
    const { data, width, height } = layer;

    const zeroBasedData = data.map(d => d - 1);

    let compressed;
    for (let i = 0; i < runLengths.length; ++i) {
        console.log('about to try', runLengths[i][0], runLengths[i][1]);
        compressed = rleCompress(zeroBasedData, runLengths[i][0], runLengths[i][1]);
        console.log('RL1', runLengths[i][0], 'RL2', runLengths[i][1]);
        console.log('compression percentage', (data.length - compressed.length) / data.length * 100);
    }

    compressed = rleCompress(zeroBasedData, 5, 3);

    const arrayLength = compressed.length;

    return `
const uint8_t RL1 = ${RL1};
const uint8_t RL2 = ${RL2};
const int8_t RL1_LENGTH = 5;
const int8_t RL2_LENGTH = 3;
const int16_t TILE_SIZE = 16;
const int16_t MAP_WIDTH_TILES = ${width};
const int16_t MAP_HEIGHT_TILES = ${height};
const int16_t MAP_WIDTH_PX = MAP_WIDTH_TILES * TILE_SIZE;
const int16_t MAP_HEIGHT_PX = MAP_HEIGHT_TILES * TILE_SIZE;
const int16_t WORLD_DATA_LENGTH = ${compressed.length};

const uint8_t PROGMEM ${name}_map[${compressed.length}] = {
    ${compressed.map(n => "0x" + n.toString(16)).join(", ")}
};`;
};
