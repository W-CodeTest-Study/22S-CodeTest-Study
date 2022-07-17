string = []
num = int(input())

# 리스트에 입력값 넣기
for _ in range(num):
	string.append(input())

# 중복 값 제거
string =list(set(string))

# 조건에 따라서 Lambda를 통해 정렬
string.sort(key=lambda x: (len(x), x))

# 결과 출력
for st in string:
	print(st)