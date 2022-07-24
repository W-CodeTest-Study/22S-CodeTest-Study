# 다트게임
def solution(dartResult):
    answer = 0
    last_option = False
    list_result = []
    for i in range(len(dartResult)):
        list_result.append(dartResult[i])
    list_result.insert(0,'~')
    for i in range(3):
        # pop을 이용해 뒤에서 부터 확인
        last = list_result.pop()
        # 문자열이 * or # 일시 option 있음
        if last == '*' or last=='#':
            option = last
            bonus = list_result.pop()
        # 문자열이 * or # 아닐시 option 없음
        else:
            option = '~'
            bonus = last
        # 점수가 10점일때
        if list_result[-1]=='0' and list_result[-2]=='1':
            list_result.pop()
            list_result.pop()
            score = 10
        # 점수가 10점이 아닐 때
        else:
            tmp = list_result.pop()
            score = int(tmp)
        # 점수 계산
        answer += cal(option, bonus, score, last_option)
        # option이 *라면 앞 세트의 점수에도 영향을 미치므로 last_option을 변경
        if option == '*':
            last_option = True
        else:
            last_option = False

    return answer


def cal(option, bonus, score, last_option):
    answer = 1
    # last_option이 True일시 option이 *이므로 2배
    if last_option == True:
        answer = answer*2
    # option이 *일때 점수 2배
    if option == '*':
        answer = answer*2
    # option이 #일때 점수 마이너스
    elif option == '#':
        answer = answer*(-1)
    # bonus에 따른 점수 계산
    if bonus == 'T':
        answer = answer*(score**3)
    elif bonus == 'D':
        answer = answer*(score**2)
    else:
        answer = answer*score
    
    return answer

if __name__ == "__main__":
    dartResult = "1D2S3T*"
    answer = solution(dartResult)
    print(answer)