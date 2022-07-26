from collections import deque

def solution(s):
    queue = deque()
    for i in s:
        if i == "(": 
            queue.append("(")

        elif i == ")":
            if not queue:   return False
            queue.popleft()
    
    if queue:   return False
    return True
