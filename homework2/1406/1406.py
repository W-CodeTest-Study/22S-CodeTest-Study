import sys
import collections
a = sys.stdin.readline()
n = int(sys.stdin.readline())
b = collections.deque(a)
b.pop()
answer = ''
c = collections.deque()
for i in range(n):
    read = sys.stdin.readline()
    if read[0] == 'L':
        if len(b) != 0:
            cnt = b.pop()
            c.appendleft(cnt)
    elif read[0] == 'D':
        if len(c) != 0:
            cnt = c.popleft()
            b.append(cnt)
    elif read[0] == 'B':
        if len(b) != 0:
            b.pop()
    elif read[0] == 'P':
        b.append(read[2])
print(''.join(list(b)+list(c)))
