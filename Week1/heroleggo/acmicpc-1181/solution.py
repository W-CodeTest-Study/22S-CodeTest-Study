# 숫자 받기
N = int(input())

# 단어를 저장할 list
words = []

for i in range(N):
    words.append(input())

# list(set(list))를 통해 중복 제거하기
words = list(set(words))

# 길이, 사전순 배열을 조건 순서로 정렬
words.sort(key=lambda x: (len(x), x))

# 출력
for i in words:
    print(i)