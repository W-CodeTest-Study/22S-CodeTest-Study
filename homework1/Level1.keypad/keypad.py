def solution(numbers, hand):
    answer = ''
    positionL = 10
    positionR = 12
    for i in range(0,len(numbers)):
        if int(numbers[i])%3 ==1:
            answer +='L'
            positionL=int(numbers[i])
        elif int(numbers[i])%3==0 or int(numbers[i]!=0):
            answer +='R'
            positionR=int(numbers[i])
        else:
            if int(numbers[i])==0:
                numbers[i]=11
            L=abs(int(numbers[i])-positionL)
            R=abs(int(numbers[i])-positionR)
            divL=sum(divmod(L,3))
            divR=sum(divmod(R,3))
            if divL>divR:
                answer+='R'
                positionR=int(numbers[i])
            elif divL==divR:
                if hand =="right":
                    answer+='R'
                    positionR=int(numbers[i])
                else:
                    answer+='L'
                    positionL=int(numbers[i])
            else:
                answer+='L'
                positionL=int(numbers[i])
    return answer
a=input()
b=input()
print(solution(a,b))