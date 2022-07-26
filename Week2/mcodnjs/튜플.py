def solution(s):
    answer = []
    s = s.lstrip("{{").rstrip("}}")  # input 문자열 앞뒤 "{{", "}}" 자르기
    s = s.split("},{") # "},{" 로 집합 나누기
    s = sorted(s, key=len)  # 원소 길이로 정렬

    for tup in s:
        tup = list(map(int,tup.split(","))) # ,로 나눠주고 string->int로 타입 변환
        for i in tup:
            if i not in answer:
                answer.append(i)
    return answer