N = int(input())
words = []
for _ in range(N):
    words.append(input())

words = list(set(words)) # 중복제거
words = sorted(sorted(words), key=len)

for word in words:  
    print(word)