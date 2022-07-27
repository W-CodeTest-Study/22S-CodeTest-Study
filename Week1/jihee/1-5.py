# 키패드
def solution(numbers, hand):
    answer = ''
    # 더 가까운 손가락을 계산해야 하는 숫자에 대해서
    # 미리 거리별로 grouping하여 list에 저장
    two = [[2], [1,3,5], [4,6,8],[7,9,0],['*','#']]
    five = [[5],[2,4,6,8],[1,3,7,9,0],['*','#']]
    eight = [[8],[5,7,9,0],[2,4,6,'*','#'],[1,3]]
    zero = [[0],[8,'*','#'],[5,7,9],[4,6,2],[1,3]]
    L = '*'
    R = '#'
    # 오른손잡이인지 왼손잡이인지 저장
    if hand == 'right':
        hand = 'R'
    else:
        hand = 'L'
    for i in range(len(numbers)):
        # 1, 4, 3일시 왼손 사용 후 왼손의 위치 변경
        if numbers[i]==1 or numbers[i]==4 or numbers[i]==7:
            answer += 'L'
            L = numbers[i]
        # 3, 6, 9일시 오른손 사용 후 오른손의 위치 변경
        elif numbers[i]==3 or numbers[i]==6 or numbers[i]==9:
            answer += 'R'
            R = numbers[i]
        # 그 외 경우 더 가까운 손 사용 후 사용한 손 위치 변경
        else:
            if numbers[i] == 2:
                tmp = distance(two, L, R, hand)
                if tmp == 'R':
                    answer += 'R'
                    R = numbers[i]
                else:
                    answer += 'L'
                    L = numbers[i]
            elif numbers[i] == 5:
                tmp = distance(five, L, R, hand)
                if tmp == 'R':
                    answer += 'R'
                    R = numbers[i]
                else:
                    answer += 'L'
                    L = numbers[i]
            elif numbers[i] == 8:
                tmp = distance(eight, L, R, hand)
                if tmp == 'R':
                    answer += 'R'
                    R = numbers[i]
                else:
                    answer += 'L'
                    L = numbers[i]
            else:
                tmp = distance(zero, L, R, hand)
                if tmp == 'R':
                    answer += 'R'
                    R = numbers[i]
                else:
                    answer += 'L'
                    L = numbers[i]
        
    return answer

def distance(dist, L, R, hand):
    # dist list에서 각 손의 위치가 어떤 index에 있는지 저장
    for i in range(len(dist)):
        if L in dist[i]:
            left = i
        if R in dist[i]:
            right = i
    # 손의 위치 index가 더 작은 손을 사용하도록 하고
    # 같을 시엔 hand 사용하도록 함
    if left > right:
        return 'R'
    elif left < right:
        return 'L'
    else:
        return hand

if __name__ == "__main__":
    numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
    hand = 'right'
    answer = solution(numbers, hand)
    print(answer)