# 키패드에서 주어진 숫자가 어느 위치(i,j)에 있는지 확인하는 함수
def find_cur(keypad, n):
    pos = [(i, j) for i in range(4) for j in range(3) if keypad[i][j] == n]
    return pos[0]


def solution(numbers, hand):
    answer = ''
    left = [1, 4, 7]
    right = [3, 6, 9]
    keypad = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 0, 12]]  # 키패드를 2차원 리스트로 나타냄
    cur_l, cur_r = (3, 0), (3, 2)  # '*', '#' 위치를 좌표로 나타낸 것
    for n in numbers:
        if n in left:
            answer += 'L'
            cur_l = find_cur(keypad, n)
        elif n in right:
            answer += 'R'
            cur_r = find_cur(keypad, n)
        else:  # [2,5,8,0]일 때
            curr = find_cur(keypad, n)  # 현위치 좌표
            d_left = abs(curr[0] - cur_l[0]) + abs(curr[1] - cur_l[1])  # 현위치와 left와의 거리
            d_right = abs(curr[0] - cur_r[0]) + abs(curr[1] - cur_r[1])  # 현위치와 right와의 거리
            if d_left < d_right:
                cur_l = curr
                answer += 'L'
            elif d_right < d_left:
                cur_r = curr
                answer += 'R'
            else:  # 거리가 동일할 때는 hand 비교
                if hand == 'left':
                    cur_l = curr
                    answer += 'L'
                else:
                    cur_r = curr
                    answer += 'R'
    return answer
