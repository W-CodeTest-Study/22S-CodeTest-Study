#해시-위장
def solution(clothes):
    dict = {}
    answer = 1
    
    for name, type in clothes:#의상 이름(name), 의상 종류(type)
        if type not in dict:
            dict[type]=1#의상 종류 -> key, 종류별 의상 개수 -> value
        else:
            dict[type]+=1
            
    for key, value in dict.items():
        answer *= (value+1)
    return answer-1
