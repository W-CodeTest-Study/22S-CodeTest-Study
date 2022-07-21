import math
import collections


# 배포할 작업이 몇 개인지 세는 함수
def count_nr_release(days):
    for i in range(1, len(days)):
        if days[i] > 0:  # days[0] 은 항상 0이기 때문, 자기보다 큰 게 있으면 스탑.
            return i
    return len(days)  # 자기보다 큰 게 없으면 배포할 것은 모두.. 따라서, days 전체 개수만큼


def solution(progresses, speeds):
    answer = []
    days = []
    for i in range(len(progresses)):
        day = math.ceil((100 - progresses[i]) / speeds[i])  # 배포까지 남은 일수 계산
        days.append(day)

    while days:  # 큐가 빌 때까지 반복
        days = collections.deque(map(lambda x: x - days[0], days))  # 앞에서부터 빼줘야 하기 때문에 deque로 변환
        nr_release = count_nr_release(days)
        answer.append(nr_release)
        for _ in range(nr_release):
            days.popleft()

    return answer
