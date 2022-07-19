const solution = (s) => {
    let length = 0; // stack의 역할을 할 변수
    let result = true;
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') { // 괄호 여는 부분이 들어왔을 때, length를 늘려줌 (스택에 push된 것)
            length++;
        } else {
            if (!length) { // 닫는 괄호를 length가 0일 때 받았을 경우 (잘못된 케이스)
                result = false;
                break;
            } else { // 정상적으로 닫힌 경우 (스택에서 pop)
                length--;
            }
        }
    }

    return result ? length === 0 : false; // result 변수가 변하지 않았을 경우, stack의 길이가 0이면 정상, 이외에는 모두 비정상
}