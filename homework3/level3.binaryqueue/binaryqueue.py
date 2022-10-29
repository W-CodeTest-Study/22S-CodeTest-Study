import heapq
def solution(operations):
    a= []
    answer =[]
    for b in operations:
        if b[0] == "I":
            heapq.heappush(a,int(b[2:]))
        elif b[2] == "-":
            if len(a)!=0:
                heapq.heappop(a)
        else:
            if len(a)!=0:
                a = heapq.nlargest(len(a), a)[1:]
                heapq.heapify(a)
    if len(a)==0:
        return([0,0])
    else:
        answer.append(max(a))
        answer.append(min(a))
        return answer
  