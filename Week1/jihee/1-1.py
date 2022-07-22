# 단어 정렬
def solution():
    words = []
    n = int(input())
    for i in range(n):
        words.append(input())
    # set을 이용해 중복 제거
    words_set = set(words)
    words = list(words_set)
    # sort() 함수를 이용해 사전순 정렬
    words.sort()
    # lambda 식을 이용해 길이순 정렬
    words = sorted(words, key= lambda x: len(x))
    answer = words
    return answer



if __name__ == "__main__":
    answer = solution()
    for i in range(len(answer)):
        print(answer[i])