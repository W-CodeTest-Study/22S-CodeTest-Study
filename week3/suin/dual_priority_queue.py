#3-3. 이중우선순위 큐

import heapq

def solution(operations):
    answer = []
    
    for opt in operations:
        cmd, data = opt.split(" ") #명령어, 데이터 분리
        
        #삽입
        if cmd == "I":
            heapq.heappush(answer, int(data))
        #삭제
        else:
            if len(answer)==0:#빈 큐
                pass
            else:
                #최솟값 삭제
                if data == "-1":
                    heapq.heappop(answer)
                #최댓값 삭제
                elif data == "1":
                    answer.pop(answer.index(heapq.nlargest(1,answer)[0]))#nlargest로 최댓값 추출 가능
    
    if len(answer)==0:
        return [0,0]
    
    #최댓값, 최솟값 출력
    return [heapq.nlargest(1,answer)[0], heapq.heappop(answer)]
