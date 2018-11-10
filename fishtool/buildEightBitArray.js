module.exports = function buildEightBitArray(fishes) {
    const entries = fishes.map(fish => {
        return `
    // ${fish.name}
    ${fish.activeHours[0]},  // minHour
    ${fish.activeHours[1]},  // maxHour
    ${fish.baitPreference.WORM},  // baitPreference WORM
    ${fish.baitPreference.GRUB},  // baitPreference GRUB
    ${fish.baitPreference.SHRIMP},  // baitPreference SHRIMP
    ${fish.baitPreference.MEAT},  // baitPreference MEAT
    ${fish.ratio},  // ratio
    ${fish.value},  // value`;
    });

    return `const uint8_t PROGMEM fish_templates_u8t[] = {
${entries.join("\n")}
};\n`;
};
