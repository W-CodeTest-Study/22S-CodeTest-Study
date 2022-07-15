#기능개발
import math
def solution(progresses, speeds):
    answer = []
    period = []
    count = 1 #배포하는 기능 개수
    
    #남은 작업 기간
    period = [math.ceil((100-r)/s) for r,s in zip(progresses,speeds)]
        
    for i in range(1,len(period)):
        if period[i-1]>=period[i]: #앞에 있는 기능이 더 늦게 개발될 때
            count += 1
        else:
            answer.append(count)
            count = 1 #초기화
    answer.append(count)
    return answer
