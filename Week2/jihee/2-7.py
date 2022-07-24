# 에디터
from collections import deque
import sys

def solution():
    answer = ""
    # 커서 왼쪽에 있는 문자열 저장
    left = list(sys.stdin.readline().rstrip())
    # 커서 오른쪽에 있는 문자열 저장
    right = deque()

    n = int(sys.stdin.readline().rstrip())

    # 각 명령어 수행
    for i in range(n):
        command = sys.stdin.readline().split()
        if command[0] == "L":
            if left:
                right.appendleft(left.pop())
        elif command[0] == "D":
            if right:
                left.append(right.popleft())
        elif command[0] == "B":
            if left:
                left.pop()
        else:
            left.append(command[1])
    
    # left, right join하여 answer에 저장
    answer = "".join(left)
    answer = answer + "".join(right)
    return answer

if __name__ == "__main__":
    answer = solution()
    print(answer)