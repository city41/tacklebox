
program
    .version(packageJson.version)
    .option(
        "-s, --src <fish file>",
        "The json file containing the fish data"
    )
    .option(
        "-o, --dest <dest directory>",
        "The directory to write the header files to"
    )
    .parse(process.argv);

if (!program.src) {
    console.error(
        "usage: node ./fishtool/ -s <fish json file> -o <header output directory>"
    );
    process.exit(1);
}

const fishJson = require(program.src);

const eightBitData = buildEightBitArray(fishJson);
const sixteenBitData = buildSixteenBitArray(fishJson);



