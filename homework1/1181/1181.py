n = int(input())
answer=[]
for i in range(n):
    a=input()
    if a not in answer:
       answer.append(a)
answer=sorted(answer,key=lambda x:(len(x),x))
for j in range(len(answer)):
    print(answer[j])