# 기능개발
import math
def solution(progresses, speeds):
    answer = []
    queue = []
    # 각 기능별로 배포까지 필요한 day 계산
    for i in range(len(progresses)):
        day = math.ceil((100-progresses[i])/speeds[i])
        queue.append(day)
    print(queue)     

    if queue:
        pre = queue.pop(0)
        cnt = 1
        while True:
            # queue에 원소 없다면 현재 cnt 저장
            if not queue:
                answer.append(cnt)
                break
            else:
                tmp = queue.pop(0)
                # 현재 검사하는 원소가 pre 원소보다 작거나 같다면 cnt 증가
                if tmp <= pre:
                    cnt += 1
                # 현재 검사하는 원소가 pre 원소보다 크다면 현재 cnt 저장 후 pre에 현재 검사하는 원소 저장& cnt 1로 초기화
                else:
                    answer.append(cnt)
                    pre = tmp
                    cnt = 1 

    return answer

if __name__ == "__main__":
    progresses = [95, 90, 99, 99, 80, 99]
    speeds = [1, 1, 1, 1, 1, 1]
    answer = solution(progresses, speeds)
    print(answer)