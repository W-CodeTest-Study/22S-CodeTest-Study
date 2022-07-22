# 튜플
def solution(s):
    answer = []
    set = []
    dictionary = {}
    
    tmp=""
    for i in range(len(s)):
        # 숫자일시 tmp에 저장
        if s[i].isdigit():
            tmp = tmp + s[i]
        # 숫자가 아니고
        else:
            # tmp가 empty 상태가 아니라면
            if tmp != "":
                # set에 tmp를 저장
                set.append(int(tmp))
                # dictionary에 key가 tmp이고 value가 0으로 저장
                dictionary[int(tmp)] = 0
                tmp=""
    # set에 담긴 숫자의 개수를 세줌
    for i in range(len(set)):
        dictionary[set[i]] = dictionary[set[i]] + 1
    # 숫자의 개수대로 정렬
    sdict = dict(sorted(dictionary.items(), key= lambda x: -x[1]))
    answer = list(sdict.keys())
    
    return answer

if __name__ == "__main__":
    s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"
    answer = solution(s)
    print(answer)