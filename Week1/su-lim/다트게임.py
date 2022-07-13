def solution(dartResult):
    answer = 0
    
    # idx : dartResult를 순서대로 참조할 인덱스 변수
    #       텍스트에서의 커서 이동과 같은 개념으로 사용
    idx = 0     
    i = len(dartResult) # 반복할 횟수를 임시로 지정
    dic_bonus = { # 보너스 기준
        'S': 1,
        'D': 2,
        'T': 3,
    }
    
    stack = [] # 각 라운드의 계산 결과를 스택으로 저장
    
    while( len(stack)!=3 ):
        number = 0
        bonus = 0
        option = ''

        # 1. 숫자 처리
        if dartResult[idx].isdigit(): # 숫자인 경우
            if dartResult[idx+1].isdigit(): #10인 경우
                idx += 2
                number = 10
            else:
                number = int(dartResult[idx])
                idx += 1
        
        # 2. 보너스 처리
        bonus = dic_bonus[dartResult[idx]]
        idx += 1
        
        # 3. 옵션 처리
        if len(dartResult) == idx:
            stack.append(number ** bonus)
            break;
            
        if dartResult[idx] == '*':
            # 이전 결과
            if len(stack): 
                tmp = stack.pop()*2
                stack.append(tmp)

            # 현재 결과
            stack.append(number ** bonus * 2)
            idx += 1
        elif dartResult[idx] == '#':
            # 현재 결과
            stack.append(number ** bonus * (-1))
            idx += 1
        else:
            stack.append(number ** bonus )
            
    answer = sum(stack)
    return answer