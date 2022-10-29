#3-2 더 맵게
import heapq

def solution(scoville, K):
    answer = 0
    
    #기존 리스트 -> 힙으로 변환
    heapq.heapify(scoville)
    
    while scoville[0] < K and len(scoville)> 1: 
        first = heapq.heappop(scoville) #가장 작은 스코프 지수 -> 힙에서 삭제
        second = heapq.heappop(scoville) #두번재로 작은 스코프 지수 -> 힙에서 삭제

        #섞은 스코빌 지수-> 힙에 추가
        heapq.heappush(scoville, first + second*2) 
        #섞은 횟수
        answer+=1
        
    #제한 사항
    if scoville[0] < K :
        return -1
    
    return answer
