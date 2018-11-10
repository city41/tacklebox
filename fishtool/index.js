const fs = require("fs");
const path = require("path");
const program = require("commander");
const packageJson = require("./package.json");
const buildEightBitArray = require("./buildEightBitArray");

program
    .version(packageJson.version)
    .option("-s, --src <fish file>", "The json file containing the fish data")
    .option(
        "-o, --dest <dest file path>",
        "The file path to write the header file to"
    )
    .parse(process.argv);

if (!program.src) {
    console.error(
        "usage: node ./fishtool/ -s <fish json file> -o <header output file path>"
    );
    process.exit(1);
}

const fishJson = require(path.join(process.cwd(), program.src));

const eightBitData = buildEightBitArray(fishJson.fish);
// const sixteenBitData = buildSixteenBitArray(fishJson.fish);

const fileData = "#pragma once\n\n" + eightBitData;

const outDir = program.dest ? path.join(process.cwd(), program.dest) : null;

if (outDir) {
    const destPath = path.join(process.cwd(), "fishTemplates.h");
    fs.writeFileSync(destPath, fileData);
    console.log("wrote: ", destPath);
} else {
    console.log(fileData);
}
