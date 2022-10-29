#키패드 누르기
def distance(x,y):
    dic={
        1: [0, 0], 2: [0, 1], 3: [0, 2],
        4: [1, 0], 5: [1, 1], 6: [1, 2],
        7: [2, 0], 8: [2, 1], 9: [2, 2],
        '*':[3, 0], 0: [3, 1], '#': [3, 2]
    }
    x1,y1 = dic[x]
    x2,y2 = dic[y]
    
    return abs(x1-x2)+abs(y1-y2)
    
    
def solution(numbers, hand):
    answer = ''
    left_hand='*'
    right_hand='#'
    for num in numbers:
        if num in [1,4,7] :
            answer+='L'
            left_hand=num
        elif num in [3,6,9] :
            answer+='R'
            right_hand=num
        else:
            if distance(left_hand, num)<distance(right_hand,num):
                answer+='L'    
                left_hand=num
            elif distance(left_hand,num)>distance(right_hand,num):
                answer+='R'
                right_hand=num
            #왼손, 오른손 거리가 같은 경우
            else:
                if hand=='left':
                    answer+='L'
                    left_hand=num
                elif hand=='right':
                    answer+='R'
                    right_hand=num
    return answer
            
