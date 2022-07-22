from collections import deque
from sys import stdin

# 초기 입력
text = stdin.readline()[:-1]
num = int(stdin.readline()[:-1])

# num만큼 들어오는 명령에 따라 에디터 기능 수행
left_stack = deque(text)
right_stack = deque()
for _ in range(num):
	commands = stdin.readline()[:-1]

	if commands[0] == 'L': # 커서 이동 L 
		if len(left_stack) != 0:
			right_stack.appendleft(left_stack.pop())

	elif commands[0] == 'D': # 커서 이동 R
		if len(right_stack) != 0:
			left_stack.append(right_stack.popleft())

	elif commands[0] == 'B': # 삭제 기능
		if len(left_stack) != 0:
			# cursor 왼쪽 값을 포함하지 않은채로 새로운 문자열로 저장 
			left_stack.pop()

	elif commands[0] == 'P': # 문자 추가
		# cursor 사이에 문자(commands[2]) 추가
		left_stack.append(commands[2])

# 결과 출력
text = ''.join(left_stack + right_stack)
print(text)