# 올바른괄호
def solution(s):
    answer = True
    
    stack = []
    # 괄호는 짝 지어져야하기에 ( 나올때마다 stack에 넣고
    # ) 나올때마다 stack을 pop하여 도중에 stack에 빈 상황이 발생하지 않고
    # 최종적으로 검사를 마쳤을 때 stack이 비었으면 올바른 괄호 문자열
    for i in range(len(s)):
        # ( 나올 때마다 stack에 저장
        if s[i] == "(":
            stack.append(s[i])
        else:
            # 도중에 stack이 비었다면 올바르지 않음
            if not stack:
                answer = False
                break
            # ) 나올때마다 stack에서 pop
            else:
                stack.pop()
    # 최종적으로 검사 마쳤을 때 stack이 비어있지 않다면 올바르지 않음
    if stack:
        answer = False

    return answer


if __name__ == "__main__":
    s = "()()"
    answer = solution(s)
    print(answer)