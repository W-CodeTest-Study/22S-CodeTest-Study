#기능개발
import math
def solution(progresses, speeds):
    answer = []
    period = []
    front = 0 #가장 오랜 시간이 소요되는 기능의 인덱스 저장
    
    #남은 작업 기간
    period = [math.ceil((100-r)/s) for r,s in zip(progresses,speeds)]
        
#    for i in range(1,len(period)):
#        if period[i-1]>=period[i]: #앞에 있는 기능이 더 늦게 개발될 때
#            count += 1
#        else:
#            answer.append(count)
#            count = 1 #초기화
    
    for i in range(len(period)):
        if period[i]>period[front]:
            answer.append(i-front)#배포
            front=i
        
    answer.append(len(period)-front)
    return answer
