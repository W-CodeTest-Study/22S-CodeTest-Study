#튜플 
import re

def solution(s):
    answer = []

    #전처리
    new_s = s[2:-2].split('},{')#숫자만 추출
    new_s.sort(key=lambda x: len(x))#문자열 길이에 대해 오름차순 정렬

    for i in new_s:
        numbers=re.findall('\d+',i)#슷자만 
        for j in numbers:
            if int(j) not in answer:
                answer.append(int(j))

    return answer
