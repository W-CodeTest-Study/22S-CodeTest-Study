import re
def solution(dartResult):
    num= re.findall('[0-9]+',dartResult)
    bonus = re.findall('[A-Z,*,#]',dartResult)
    answer=[]
    cnt=0
    for i in range(len(bonus)):
        if bonus[i]=='S':
            answer.append(int(num[cnt]))
            cnt+=1
        elif bonus[i]=='D':
            answer.append(int(num[cnt])**2)
            cnt+=1
        elif bonus[i]=='T':
            answer.append(int(num[cnt])**3)
            cnt+=1
        elif bonus[i]=='*':
            if i==1:
                answer[-1]=2*answer[-1]
            else:
                answer[-1]=2*answer[-1]
                answer[-2]=2*answer[-2]
        elif bonus[i]=='#':
            answer[-1]=-answer[-1]
    return sum(answer)