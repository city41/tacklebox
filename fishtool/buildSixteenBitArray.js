const encoding = require("../stringtool/encoding");
const { getMinX, getMaxX } = require("./getMinMaxXFromHabitats");

function buildActualSixteenBitArray(fishes) {
    const entries = fishes.map(fish => {
        return `
    // ${fish.name}
    ${getMinX(fish.habitats)}, // min X
    ${getMaxX(fish.habitats)}, // max X
    reinterpret_cast<int16_t>(${fish.name}_string),`;
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
    ${values.join(", ")}, 0xFF
};`;
    });

    return nameArrays.join("\n\n");
}

function buildAllFishNameStrings(fishes) {
    const entries = fishes.map(f => `    ${f.name}_string`);

    return `const uint8_t* const PROGMEM allFishNameStrings[] = {
${entries.join(",\n")}
};`;
}

module.exports = function buildSixteenBitArray(fishes) {
    const names = buildNames(fishes);
    const allFishNameStrings = buildAllFishNameStrings(fishes);
    const sixteenBitArray = buildActualSixteenBitArray(fishes);

    return names + "\n\n" + allFishNameStrings + "\n\n" + sixteenBitArray;
};
