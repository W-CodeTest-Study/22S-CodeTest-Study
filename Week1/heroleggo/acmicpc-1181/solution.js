const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [length, ...data] = input;

const result = Array.from(new Set(data));

result.sort((a, b) => {
    if (a.length === b.length) {
        return a < b ? -1 : a > b ? 1 : 0;
    } else {
        return a.length - b.length;
    }
})

console.log(result.join('\n'));