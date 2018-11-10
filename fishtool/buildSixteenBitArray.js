const encoding = require("../stringtool/encoding");
const { getMinX, getMaxX } = require("./getMinMaxXFromHabitats");

function buildActualSixteenBitArray(fishes) {
    const entries = fishes.map(fish => {
        return `
    // ${fish.name}
    ${getMinX(fish.habitats)}, // min X
    ${getMaxX(fish.habitats)}, // max X
    ${fish.name}_string`;
    });

    return `const int16_t PROGMEM fish_templates_16t[] = {
${entries.join("\n")}
};\n`;
}

function buildNames(fishes) {
    const nameArrays = fishes.map(fish => {
        const values = fish.name.split("").map(c => encoding[c]);
        return `const uint8_t ${fish.name}_string[${fish.name.length +
            1}] PROGMEM = {
    ${values.join(", ")}
};`;
    });

    return nameArrays.join("\n\n");
}

module.exports = function buildSixteenBitArray(fishes) {
    const names = buildNames(fishes);
    const sixteenBitArray = buildActualSixteenBitArray(fishes);

    return names + "\n\n" + sixteenBitArray;
};
