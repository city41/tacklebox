#include "fish.h"
#include "fishTemplates.h"
#include "fishType.h"
#include "baitType.h"

void Fish::loadFish(FishType fishType, Fish& fish) {
    fish.type = fishType;

    const uint8_t* offset = fish_templates_u8t + static_cast<int8_t>(fishType) * NUM_U8T_PROPS;
    fish.minHour = pgm_read_byte(offset);
    fish.maxHour = pgm_read_byte(offset + 1);

    fish.baitPreferences[static_cast<int8_t>(BaitType::WORM)] = pgm_read_byte(offset + 2);
    fish.baitPreferences[static_cast<int8_t>(BaitType::GRUB)] = pgm_read_byte(offset + 3);
    fish.baitPreferences[static_cast<int8_t>(BaitType::SHRIMP)] = pgm_read_byte(offset + 4);
    fish.baitPreferences[static_cast<int8_t>(BaitType::MEAT)] = pgm_read_byte(offset + 5);

    fish.ratio = pgm_read_byte(offset + 6);
    fish.value = pgm_read_byte(offset + 7);

    const int16_t* offset16 = fish_templates_16t + static_cast<int8_t>(fishType) * NUM_16T_PROPS;

    fish.minX = pgm_read_word(offset16);
    fish.maxX = pgm_read_word(offset16 + 1);

    fish.nameString = reinterpret_cast<const uint8_t*>(pgm_read_word(offset16 + 2));
    fish.bmp = reinterpret_cast<const uint8_t*>(pgm_read_word(offset16 + 3));
}
