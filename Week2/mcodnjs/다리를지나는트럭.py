from collections import deque

def solution(bridge_length, weight, truck_weights):

    answer, truck = 0, -1 # answer == time, i == 대기트럭의 index
    stack = deque() # 현재 다리 위에 있는 트럭 스택 
    time_stack = deque() # 현재 다리 위에 있는 트럭의 시간 스택 
    stack_weight = 0 # 현재 다리 위에 있는 트럭들의 무게

    while True:

        answer += 1 # 시간 +1 
        for i in range(len(time_stack)):  # 매초마다 다리 위에 있는 트럭들의 시간 스택도 증가
            time_stack[i] += 1
            
        if truck < len(truck_weights)-1 and len(stack) < bridge_length and stack_weight+truck_weights[truck+1] <= weight:
            # 3가지 조건: 1) 아직 다리를 건너가지 않은 트럭이 있을 때 2) 브릿지 길이가 채워지지 않았을 때 3) 브릿지 무게가 아직 다 채워지지 않았을 때
            truck += 1
            stack.append(truck_weights[truck])
            time_stack.append(1) 
            stack_weight += truck_weights[truck]

        if time_stack[0] >= bridge_length: # 브릿지 길이 만큼 타임 스택이 채워졌을 때 한 타임당 하나의 트럭씩 pop
            stack_weight -= stack.popleft()
            time_stack.popleft()

        if truck >= len(truck_weights)-1 and not stack and not time_stack:   return answer + 1
        # 모든 트럭이 다리를 다 건넜을 때 종료

solution(2, 10, [7,4,5,6])
solution(100, 100, [10])
solution(100, 100, [10,10,10,10,10,10,10,10,10,10])