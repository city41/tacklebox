module.exports = function buildMapArray(name, layer, tileSize) {
    const { data, width, height } = layer;

    const zeroBasedData = data.map(d => d - 1);

    const arrayLength = zeroBasedData.length + 2;

    return `
const uint8_t PROGMEM ${name}_map[${arrayLength}] = {
    // map width, map height (in tiles)
    ${width}, ${height},
    // map data, ${zeroBasedData.length} bytes
    ${zeroBasedData.map(n => "0x" + n.toString(16)).join(", ")}
};`;
};
