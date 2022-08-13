import heapq
def solution(scoville, K):
    answer = 0
    scoville=sorted(scoville)
    heapq.heapify(scoville)
    while scoville[0]<K:
        if len(scoville)==1:
            answer=-1
            break
        else:
            a=heapq.heappop(scoville)
            b=heapq.heappop(scoville)
            heapq.heappush(scoville,a+b*2)
            answer+=1
    return answer