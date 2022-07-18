def solution(s):
    answer = True
    left = 0  # ( 갯수를 left라고 놓음
    right = 0  # ) 갯수를 right라고 놓음

    for i in range(len(s)):
        if s[i] == '(':
            left += 1
            if left < right:
                return False
        elif s[i] == ')':
            right += 1
            if left < right:
                return False

    if left == right:
        return True
    else:
        return False
