def solution(clothes):
    clo = dict()
    answer =1
    for i in clothes : 
        if i[1] in clo:
            clo[i[1]] +=1
        else:
            clo[i[1]]=1
    cnt = list(clo.values())
    for i in cnt:
        answer *= i+1
    return answer-1