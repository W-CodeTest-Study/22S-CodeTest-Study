import math
def solution(progresses, speeds):
    day=[]
    answer=[]
    cnt=1
    for i in range(len(progresses)):
        day.append(math.ceil((100-int(progresses[i]))/int(speeds[i])))
    max=day[0]
    for i in range(1,len(day)):
        if day[i]<=max:
            cnt+=1
        elif day[i]>max:
            answer.append(cnt)
            max=day[i]
            cnt=1
    answer.append(cnt)
    return answer