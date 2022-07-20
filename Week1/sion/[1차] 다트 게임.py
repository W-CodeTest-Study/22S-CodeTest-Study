def solution(dartResult):
    empty_option = 0

    dic = {
        'score': [],
        'bonus': [],
        'option': []
    }
    option_flag = False  # 옵션 생략 됐을 때 예외처리하기 위한 플래그
    tmp = ''
    for i in dartResult:
        # 옵션이 없을 때, 0 추가
        if option_flag:
            option_flag = False
            if i.isdigit():
                dic['option'].append(empty_option)

        if i.isalpha():
            dic['score'].append(int(tmp))
            dic['bonus'].append(i)
            tmp = ''
            option_flag = True
        elif i.isdigit():
            tmp += i
        else:
            dic['option'].append(i)
    # 반복문에서 마지막 옵션 생략 시에는 확인 불가하므로 for문 이후에 추가해주기
    if len(dic['option']) == 2:
        dic['option'].append(empty_option)

    # print(dic)
    cals = []  # 문자열 한 세트마다 계산한 값을 저장하기 위한 리스트 (총 3세트)
    for i in range(3):
        bonus = dic['bonus'][i]
        score = dic['score'][i]
        option = dic['option'][i]
        tmp = 0
        # 보너스 S, D, T에 따른 계산
        if bonus == 'S':
            tmp = score
        elif bonus == 'D':
            tmp = pow(score, 2)
        else:
            tmp = pow(score, 3)
        # 옵션에 따른 계산
        if option == '*':
            tmp *= 2
            if i > 0:  # 0이 아닐 때는 이전 계산식에도 2 곱해주기
                cals[i - 1] *= 2
        elif option == '#':
            tmp *= -1
        cals.append(tmp)
    # print(cals)

    return sum(cals)