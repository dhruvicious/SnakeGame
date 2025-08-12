"use strict";

// Fast I/O using readline for input and process.stdout for output
const fs = require("fs");

let input = "";
let inputLines = [];
let currentLine = 0;

(function initIO() {
    if (process.env.ONLINE_JUDGE === undefined) {
        input = fs.readFileSync("input.txt", "utf-8");
        const output = fs.createWriteStream("output.txt", { flags: "w" });
        console.log = function (...args) {
            output.write(args.join(" ") + "\n");
        };
    } else {
        process.stdin.resume();
        process.stdin.setEncoding("utf-8");
        process.stdin.on("data", (chunk) => (input += chunk));
        process.stdin.on("end", () => {
            inputLines = input.trim().split("\n");
            main();
        });
        return;
    }
    inputLines = input.trim().split("\n");
    main();
})();

function readline() {
    return inputLines[currentLine++];
}

// Aliases
const ll = BigInt;
const all = (arr) => [...arr];
const endl = "\n";

// Main solve function
function solve() {
    // Implement logic here
}

// Driver function
function main() {
    let t = 1;
    // t = parseInt(readline());
    while (t--) {
        solve();
    }
}
