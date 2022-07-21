import collections


def solution(bridge_length, weight, truck_weights):
    answer = 0
    len_init_waiting = len(truck_weights)
    crossed_trucks = []  # 다리를 지난 트럭 (append 만 하기때문에 리스트 사용)
    crossing_trucks = collections.deque()  # 다리를 건너는 트럭
    waiting_trucks = collections.deque(truck_weights)  # 대기 중인 트럭

    time_count = collections.deque()  # 다리를 건너는 트럭이 얼마동안 머물렀는지 카운트하는 큐
    while len(crossed_trucks) < len_init_waiting:
        # 1. 다 건너갔으면 crossing -> crossed 로 이동
        if time_count and time_count[0] == bridge_length:  #
            time_count.popleft()
            crossed_trucks.append(crossing_trucks.popleft())
        # 2. 올라가도 무게를 견딜 수 있고, 다리 길이를 넘지 않으면 대기 트럭 출발! (waiting -> crossing 로 이동)
        if waiting_trucks and waiting_trucks[0] + sum(crossing_trucks) <= weight and len(crossing_trucks) < bridge_length:
            crossing_trucks.append(waiting_trucks.popleft())
            time_count.append(0)

        for i in range(len(time_count)):  # 한 사이클 지나면 crossing 인 트럭 경과 시간 1초씩 더해주기
            time_count[i] += 1
        answer += 1

    return answer
