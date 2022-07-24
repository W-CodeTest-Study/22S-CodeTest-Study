const solution = (arr) => {
    // 정답을 담을 배열
    const answer = [];
    for (let i = 0; i < arr.length; i++) {
        if (i === 0) { // 첫번째 인덱스일경우 무조건 push
            answer.push(arr[i]);
        } else if(arr[i] === arr[i-1]) { // 이전 인덱스와 같은 값일 경우
            continue;
        } else { // 이전 인덱스와 다른 값일 경우 push
            answer.push(arr[i]);
        }
    }
    return answer;
}