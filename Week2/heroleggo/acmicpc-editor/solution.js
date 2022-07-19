const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [ original, n, ...commands ] = input;

const originalData = original.split(''); // 원래 문자열을 배열로!
const stack = []; // 커서 오른쪽이 있을 배열

// originalData - 커서 - stack의 구조!

for (let i = 0; i < n; i++) {
    const [command, data] = commands[i].split(' ');
    switch(command) {
        case 'L':
            if (originalData.length) {
                stack.push(originalData.pop()); // 오른쪽에 왼쪽의 마지막 데이터 push
            }
            break;
        case 'D':
            if (stack.length) {
                originalData.push(stack.pop()); // 왼쪽에 오른쪽의 마지막 데이터 push
            }
            break;
        case 'B':
            if (originalData.length) {
                originalData.pop(); // 왼쪽의 마지막 데이터 지움
            }
            break;
        case 'P':
            originalData.push(data); // 왼쪽에 새 데이터 push
            break;
    }
}

// stack을 queue가 아니라 stack처럼 사용했기 때문에 원소가 반대로 박혀있음 -> reverse 해야함
console.log(originalData.concat(stack.reverse()).join('')); // 붙여서 반환