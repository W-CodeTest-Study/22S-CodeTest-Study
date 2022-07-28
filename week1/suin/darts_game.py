#다트게임
def solution(dartResult):
    answer = 0
    s=[]
    #딕셔너리
    dic = {'S':1, 'D':2, 'T':3}
    
    #전처리
    rp_dartResult=dartResult.replace('10','a')#10 -> a로 변경
    
    #문자 하나씩 검사
    for i in rp_dartResult:
        if i.isdigit():
            s.append(i)
        elif i == 'a':
            s.append(10)
        elif i in dic.keys():
            num = s.pop()
            s.append(int(num)**dic.get(i))
            
        elif i == '*':
            if len(s)>1:
                num1 = s.pop()
                num2 = s.pop()
                s.append(int(num2)*2)
                s.append(int(num1)*2)
            else:#스타상이 첫 번째 기회에서 나오는 경우
                num = s.pop()
                s.append(int(num)*2)
        
        elif i == '#':
            num = s.pop()
            s.append(int(num)*(-1))
    
    answer = sum(s)#세 기회의 점수 합산
    return answer
