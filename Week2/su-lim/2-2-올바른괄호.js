// comment : for in 문이 느린 것 같아서, 
//           for(;;)으로 바꿧더니 되네요..
function solution(s){
    var top = -1 // 스택을 선언하지 않고 개념을 빌려와서 top만 사용

    // 입력으로 들어온 문자열을 처음부터 훑으며
    // ( 일때는 +, )일 때는 -를 해줌
    for(var idx=0; idx < s.length; idx++) {
        if(s[idx] === '('){
            top++;
        }else{ // if ')'
            if(top < 0){
                return false;
            }
            top--;
        }
    }
    
    // 비어있지 않을 경우
    if(top !== -1){
        return false;
    }
    return true;
}