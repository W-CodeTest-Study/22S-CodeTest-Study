#3-3 입국심사
def solution(n, times):
    answer = 0
    
    #걸리는 최소 시간
    left = min(times)
    #걸리는 최대 시간
    right = n*max(times)
    
    while left < right:
        mid = (left+right) // 2 #현재 탐색 시간
        complete = 0 #심사 완료한 사람들 수
        
        for time in times:
            complete += mid // time # 모든 심사관들이 mid시간 동안 심사 완료한 사람들 수
            
        # n명 모두 검사하기에 mid 시간이 충분함
        if complete>=n:
            right = mid # 최소 시간을 찾기 위해 max 갱신
            
        # n명 모두 검사하기에 mid 시간이 부족함
        else:
            left = mid+1
            
    answer = left # 최소 시간
    return answer
