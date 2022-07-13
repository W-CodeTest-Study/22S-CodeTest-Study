# 눌러야할 숫자 i, 현재 위치의 숫자 j
# i와 j의 거리를 맨하탄 거리 공식으로 값을 구하여 리턴
def distance(i, j):
    result = 0
    coordinate = {
        1 : (0,0),
        2 : (0,1),
        3 : (0,2),
        4 : (1,0),
        5 : (1,1),
        6 : (1,2),
        7 : (2,0),
        8 : (2,1),
        9 : (2,2),
        '*' : (3,0),
        0 : (3,1),
        '#' : (3,2),
    }
    result = abs(coordinate[i][0] - coordinate[j][0]) + abs(coordinate[i][1] - coordinate[j][1])
    
    return result

def solution(numbers, hand):
    answer = ''
    l_hand = '*' # left hand의 위치를 나타냄
    r_hand = '#' # right hand의 위치를 나타냄
    
    for i in numbers:
        
        # 1,4,7일 때 L로 누름
        if i in [1,4,7]:
            l_hand = i
            answer+='L'
            
        # 3,6,9일 때 R로 누름
        elif i in [3,6,9]:
            r_hand = i
            answer+='R'
            
        # 그외 상황에서는 거리를 비교하여 누름
        else:
            l_dis = distance(i, l_hand)
            r_dis = distance(i, r_hand)
            if l_dis < r_dis:
                l_hand = i
                answer+='L'
            if l_dis > r_dis:
                r_hand = i
                answer+='R'
            if l_dis == r_dis: # 거리 동일 할 경우 손잡이 방향으로 적용
                if hand == 'left':
                    l_hand = i
                    answer+='L'
                if hand == 'right':
                    r_hand = i
                    answer+='R'
    return answer
