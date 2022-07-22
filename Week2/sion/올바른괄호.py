def solution(s):
    stack = []
    for i in s:
        if i == ')':  # ')' 일 때, stack의 최상단 요소가 '(' 이 아니면 잘못된 괄호
            if not stack or stack[-1] == ')':  # 스택이 비어있을 때 ')' 올 수 있으므로 not stack 조건 추가
                return False
            else:  # 최상단 요소인 ( 제거
                stack.pop()
        else:
            stack.append(i)
    if stack:  # for문에서 짝 맞춰서 뺐는데 스택이 남아있으면 잘못된 괄호
        return False

    return True
