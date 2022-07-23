def solution(s):
    answer = True
    stack = []
    for i in s:
        if i=="(":
            stack.append(i)
        elif i==")":
            if stack==[]:
                return False
            else:
                stack.pop()
    return stack==[]