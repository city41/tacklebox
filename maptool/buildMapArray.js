module.exports = function buildMapArray(name, layer, tileSize) {
    const { data, width, height } = layer;

    const zeroBasedData = data.map(d => d - 1);
    const rectangleSpecs = divideMapIntoRectangles(zeroBasedData, width, height);

    const getTileAtSrc = buildGetTileAt(rectangleSpecs, name);


    const headerSrc = `
#pragma once

#include <Arduino.h>

const int16_t TILE_SIZE = 16;
const int16_t MAP_WIDTH_TILES = ${width};
const int16_t MAP_HEIGHT_TILES = ${height};
const int16_t MAP_WIDTH_PX = MAP_WIDTH_TILES * TILE_SIZE;
const int16_t MAP_HEIGHT_PX = MAP_HEIGHT_TILES * TILE_SIZE;

uint8_t ${name}_getTileAt(int16_t x, int16_t y);
`;

const cppSrc = `
#include "${name}.h"

${getTileAtSrc}
`;

return { headerSrc, cppSrc };
};

function groupRectangles(rectangleSpecs) {
    return rectangleSpecs.reduce((building, rs) => {
        const existingGroup = building.find(b => b.tileId === rs.tileId);

        if (existingGroup) {
            existingGroup.rects.push(rs);
        } else {
            building.push({
                tileId: rs.tileId,
                rects: [rs]
            });
        }

        return building;
    }, []);
}

function buildGetTileAt(rectangleSpecs, name) {
    const groupedRects = groupRectangles(rectangleSpecs);

    const ifs = groupedRects.map(rs => {
        const ors = rs.rects.map(r => {
        return `(x >= ${r.x} && x < ${r.x + r.width} && y >= ${r.y} && y < ${r.y + r.height})`;
        });

        return `    if (${ors.join(' || ')}) return ${rs.tileId};`;
    });

    return `uint8_t ${name}_getTileAt(int16_t x, int16_t y) {
${ifs.join('\n')}
}`;
}
function divideMapIntoRectangles(data, width, height) { const visited = new Array(height).fill(1, 0, height).map(_ => new Array(width).fill(false, 0, width)); const rectangleSpecs = [];

    function visit(x, y, visited) {
        const origX = x;
        const origY = y;
        const tileId = data[y * width + x];
        const { min, max } = Math;

        let heightIfGoWithX = Number.MAX_SAFE_INTEGER;

        while(x < width && data[y * width + x] === tileId && !visited[y][x]) {
            while(y < height && data[y * width + x] === tileId && !visited[y][x]) {
                ++y;
            }
            heightIfGoWithX = min(heightIfGoWithX, y - origY);
            ++x;
            y = origY;
        }

        const widthIfGoWithX = x - origX;

        x = origX;
        y = origY;

        let widthIfGoWithY = Number.MAX_SAFE_INTEGER;

        while(y < height && data[y * width + x] === tileId && !visited[y][x]) {
            while(x < width && data[y * width + x] === tileId && !visited[y][x]) {
                ++x;
            }

            widthIfGoWithY = min(widthIfGoWithY, x - origX);
            ++y;
            x = origX;
        }

        const heightIfGoWithY = y - origY;

        if (heightIfGoWithX * widthIfGoWithX > heightIfGoWithY * widthIfGoWithY) {
            return {
                x: origX,
                y: origY,
                width: widthIfGoWithX,
                height: heightIfGoWithX
            };
        } else {
            return {
                x: origX,
                y: origY,
                width: widthIfGoWithY,
                height: heightIfGoWithY
            };
        }
    }

    function dumpVisited(visited) {
        let str = '';
        for (let y = 0; y < height; ++y) {
            for (let x = 0; x < width; ++x) {
                let c = '-';
                if (visited[y][x]) {
                    c = String.fromCharCode(visited[y][x] + '0'.charCodeAt(0));
                }
                str += c;
            }
            str += '\n';
        }

        console.log(str);
    }

    function setAsVisited(rectangle, visited, specId) {
        console.log('setAsVisited', rectangle);

        for (let y = rectangle.y; y < rectangle.y + rectangle.height; ++y) {
            for (let x = rectangle.x; x < rectangle.x + rectangle.width; ++x) {
                if (visited[y][x]) {
                    dumpVisited(visited);
                    throw new Error(`marking a cell as visited, but it was already visited!, x: ${x}, y: ${y}`);
                }

                visited[y][x] = specId;
            }
        }
    }

    for (let y = 0; y < height; ++y) {
        for (let x = 0; x < width; ++x) {
            if (!visited[y][x]) {
                const rectangle = visit(x, y, visited);
                rectangleSpecs.push({
                    tileId: data[y * width + x],
                    ...rectangle
                });
                console.log('rectangleSpec', rectangleSpecs.length - 1, rectangleSpecs[rectangleSpecs.length - 1]);
                setAsVisited(rectangle, visited, rectangleSpecs.length);
            }
        }
    }

    dumpVisited(visited);
    return rectangleSpecs;
}
