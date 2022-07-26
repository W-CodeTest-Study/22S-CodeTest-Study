import math
def solution(progresses, speeds):
    answer = []
    
    while progresses:
        day = math.ceil((100 - progresses[0]) / speeds[0]) # 필요한 day 수 

        for i in range(len(progresses)): # 위에서 구한 day를 나머지 progress에도 적용
            progresses[i] = progresses[i] + speeds[i]*day
            
        progress = 0
        while progresses:      
            if progresses[0] < 100:  break
            if progresses[0] >= 100: # 100 넘으면 answer ++ 
                progresses = progresses[1:]
                speeds = speeds[1:]
                progress += 1
        answer.append(progress)

solution([93, 30, 55], [1, 30, 5])
solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1])