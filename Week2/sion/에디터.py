import sys

edits = input()
n = int(input())

# 스택 두 개로 왔다갔다, 두 개의 스택이 커서 역할을 수행함
e1 = list(edits)
e2 = list()  # 대신 e2는 거꾸로 봐야 함

for _ in range(n):
    cmd = sys.stdin.readline().strip().split(' ')
    if cmd[0] == 'L' and e1:  # e1 마지막 요소를 e2로 옮기기
        e2.append(e1.pop())
    elif cmd[0] == 'D' and e2:  # e2 마지막 요소를 e1에 옮기기
        e1.append(e2.pop())
    elif cmd[0] == 'B' and e1:
        e1.pop()
    elif cmd[0] == 'P':
        e1.append(cmd[1])
print(''.join(e1 + list(reversed(e2))))  # e2는 뒤집어서 e1과 concatenation
