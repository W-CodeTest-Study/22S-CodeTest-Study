def solution(s):
    cnt=[]
    answer={}
    ranswer=[]
    s=s.replace('{','').replace('}','')
    s=s.split(',')
    for i in range(len(s)):
        if s[i].isdigit():
            cnt.append(s[i])
    b=list(set(cnt))
    for i in range(len(b)):
        answer[b[i]]=cnt.count(b[i])
    answer=sorted(answer.items(),key=lambda x:x[1],reverse=True)
    for i in range(len(answer)):
        ranswer.append(int(answer[i][0]))
    return ranswer