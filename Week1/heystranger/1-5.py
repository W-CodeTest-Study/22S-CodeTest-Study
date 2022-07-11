def solution(numbers, hand):
    answer = ''

    # 좌표 설정
    position = {'1': (0, 0), '2': (0, 1), '3': (0, 2),
                '4': (1, 0), '5': (1, 1), '6': (1, 2),
                '7': (2, 0), '8': (2, 1), '9': (2, 2),
                '*': (3, 0), '0': (3, 1), '#': (3, 2)}

    # 오른손 왼손 위치
    right = position['#']
    left = position['*']

    for i in numbers:
        if i == 1 or i == 4 or i == 7:
            answer += 'L'
            left = position[str(i)]

        elif i == 3 or i == 6 or i == 9:
            answer += 'R'
            right = position[str(i)]

        else:
            l_distance = abs(left[0] - position[str(i)][0]) + abs(left[1] - position[str(i)][1])
            r_distance = abs(right[0] - position[str(i)][0]) + abs(right[1] - position[str(i)][1])
            if l_distance < r_distance:
                answer += 'L'
                left = position[str(i)]

            elif l_distance > r_distance:
                answer += 'R'
                right = position[str(i)]
            else:
                if hand == 'left':
                    answer += 'L'
                    left = position[str(i)]
                else:
                    answer += 'R'
                    right = position[str(i)]

    return answer