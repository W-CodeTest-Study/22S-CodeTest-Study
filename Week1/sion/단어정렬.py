n = int(input())

words = []
for _ in range(n):
    w = input()
    # 알파벳만 필터링, 중복 방지 필터링
    if w.isalpha() and w not in words:
        words.append(w)

# 1. 문자열 길이 정렬 / 2. 사전식 정렬
for w in sorted(words, key=lambda x: (len(x), x)):
    print(w)