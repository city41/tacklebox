const ACode = "A".charCodeAt(0);
const ZCode = "Z".charCodeAt(0);

const tinyFontMap = {
    "0": 0,
    "1": 1,
    "2": 2,
    "3": 3,
    "4": 4,
    "5": 5,
    "6": 6,
    "7": 7,
    "8": 8,
    "9": 9,
    " ": 10,
    "!": 37
};

for (let i = ACode; i <= ZCode; ++i) {
    tinyFontMap[String.fromCharCode(i)] = i - ACode + 11;
}

console.log("tinyFontMap", tinyFontMap);

module.exports = tinyFontMap;
