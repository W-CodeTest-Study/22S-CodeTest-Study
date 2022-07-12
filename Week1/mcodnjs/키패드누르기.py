def solution(numbers, hand):

    answer = ''
    left = 10 # 임의의 숫자 지정: *
    right = 12 # 임의의 숫자 지정: #
    ldist = -1
    rdist = -1

    for number in numbers:

        if number == 1 or number == 4 or number == 7: # 1, 4, 7
            left = number
            answer += "L"
        elif number == 3 or number == 6 or number == 9: # 3, 6, 9
            right = number
            answer += "R"
        else: # 2, 5, 8, 0
            if number == 0: number = 11

            ldist = (abs(left + 1 - number))/3 + 1 # 오른쪽으로 한칸 이동 후 상하로 움직임
            rdist = (abs(right - 1 - number))/3 + 1 # 왼쪽으로 한칸 이동 후 상하로 움직임

            # 이미 2, 5, 8, 0에 있는 경우
            if left%3 == 2:     ldist = (abs(left - number))/3
            if right%3 == 2:    rdist = (abs(right - number))/3

            # 거리에 따른 left, right 선택
            if ldist == rdist:
                answer += hand[0].upper()
                if hand == "left":  left = number
                else:   right = number

            elif rdist > ldist:
                answer += "L"
                left = number

            elif ldist > rdist:
                answer += "R"
                right = number

    return answer