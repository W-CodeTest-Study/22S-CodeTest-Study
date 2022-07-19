const parseSet = (s) => {
    return s
    .slice(1, s.length - 1) // 맨 앞, 맨 뒤의 {, }를 없앰
    .split('},') // },로 나눔 -> 숫자, 쉼표, { 만 남음
    .map((d) => d.match(/[\d\,]+/)[0]) // 숫자, 쉼표만 남김
    .sort((a, b) => a.length - b.length) // 길이 순으로 정렬 'a1', 'a1,a2', 'a1,a2,a3' 의 형태이기 때문
    .map((e) => e.split(',').map((digit) => parseInt(digit))); // 'a1,a2,a3' 의 형태를 [a1, a2, a3] 배열로 변환
}

const solution = (s) => {
    const parsedString = parseSet(s);
    const answer = [];
    for (let i = 0; i < parsedString.length; i++) {
        if (!i) {
            answer.push(parsedString[i][0]); // 첫 인덱스는 배열의 길이가 1 -> 무조건 push
        } else {
            answer.push(parsedString[i].find((v) => !parsedString[i - 1].includes(v))); // 이전 인덱스에서 없는 값이 해당 위치의 값이므로 해당 값을 찾아서 push
        }
    }
    return answer;
}