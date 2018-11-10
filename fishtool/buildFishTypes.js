module.exports = function buildFishTypes(fishes) {
    const entries = fishes.map((fish, index) => {
        return `    ${fish.name} = ${index}`;
    });

    entries.unshift("    UNSET = -1");
    entries.push(`    NUM_FISH = ${fishes.length}`);

    return `#pragma once

enum class FishType: int8_t {
${entries.join(",\n")}
};`;
};
