from itertools import combinations
import math
def func(answer, value_list, temp):

    answer += temp
    if not value_list:  return answer 

    for i, v in enumerate(value_list):
        answer = func(answer, value_list[i+1:], temp*v)
    return answer

def solution(clothes):

    answer = 0
    dict_clothes = {} # dictionary 형태의 clothes
    for cloth in clothes: # key-value 쌍으로 만드는 과정 
        if cloth[1] in dict_clothes.keys():
            dict_clothes[cloth[1]].append(cloth[0])
        else:
            dict_clothes[cloth[1]] = []
            dict_clothes[cloth[1]].append(cloth[0])

    value_list = [] # key에 따른 value의 개수 리스트
    # dict_clothes = {"headgear": ["aaa", "bbb", "ccc"], "eyewear": ["ddd", "eee"]}
    # value_list = [3, 2]
    for value in dict_clothes.values():
        value_list.append(len(value))

    if len(set(value_list)) == 1 and value_list[0] == 1: # 시간초과 예외케이스: key에 해당하는 value 값이 모두 1일 경우 
        return math.pow(2, len(value_list))-1 # nC1 + nC2 + nC3 + ... nCn = 2^n - 1

    for i in range(len(value_list)): # 1번째 방법 - 조합 사용
        for combi in list(combinations(value_list, i+2)): # i+2 -> nC1 경우 제외 
            number = 1
            for c in combi:
                number = number * c
            answer += number
    answer += sum(value_list) # nC1의 경우
    
    answer = 0
    for i, v in enumerate(value_list): # 2번째 방법 - 재귀함수 사용 (2배 이상 빠름)
        answer = func(answer, value_list[i+1:], v)
    return answer