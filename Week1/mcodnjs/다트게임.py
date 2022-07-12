def solution(dartResult):
    answer = 0
    num = [0,0,0] # 숫자
    operations = "" # 연산자 
    flag = 0 # 10 예외처리를 위한 변수
    n = 0

    for dart in dartResult: # 숫자와 연산자 나누는 로직

        if dart == "S" or dart == "D" or dart == "T" or dart == "*" or dart == "#":
            flag = 0
            operations = operations + dart

        else:
            if flag == 1 and dart == "0": # 10 예외처리
                dart == "0"
                num[n-1] = 10 
                continue

            num[n] = int(dart)
            n += 1
            flag = 1

    print(num, operations)

    n = 0
    for oper in operations:
        if oper == "S": 
            n = n + 1
        if oper == "D":
            num[n] = num[n] * num[n]
            n = n + 1
        elif oper == "T":
            num[n] = (num[n] * num[n] * num[n])
            n = n + 1
        elif oper == "*":
            if n-2 == -1: # 첫번째 기회 스타상 예외처리 
                num[n-1] = 2*num[n-1]
            else:
                num[n-2] = 2*num[n-2]
                num[n-1] = 2*num[n-1]
        elif oper == "#":
            num[n-1] = -num[n-1]
    
    answer = num[0] + num[1] + num[2]
    return answer

solution("1S2D*3T")
solution("1D2S#10S")
solution("1D2S0T")
solution("1S*2T*3S")
solution("1D#2S*3S")
solution("1T2D3D#")
solution("1D2S3T*")