# 다리를 지나는 트럭
def solution(bridge_length, weight, truck_weights):
    answer = 0
    on = []
    # bridge_length 만큼 0으로 채우기
    for i in range(bridge_length):
        on.append(0)
    time = 0
    # list on의 index 0 자리를 pop한 후 가능하다면 truck을 append하고
    # 불가능하다면 0을 append 한 뒤 time을 증가
    while True:
        on.pop(0)
        if truck_weights:
            tmp = truck_weights.pop(0)
            if sum(on) + tmp <= weight:
                on.append(tmp)
                time = time + 1
            else:
                on.append(0)
                truck_weights.insert(0, tmp)
                time = time + 1
            #print(time, on)
        else:
            if sum(on)==0:
                time = time + 1
                break
            else:
                on.append(0)
                time = time + 1
            #print(time, on)

    answer = time
        
    return answer

if __name__ == "__main__":
    bridge_length, weight, truck_weights = 2, 10, [7,4,5,6]
    answer = solution(bridge_length, weight, truck_weights)
    print(answer)