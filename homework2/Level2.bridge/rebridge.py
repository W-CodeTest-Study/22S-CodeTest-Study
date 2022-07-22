import collections
def solution(bridge_length, weight, truck_weights):
    answer = 1
    truck_weights.reverse()
    bridge = collections.deque([0]*bridge_length)
    bridge[-1]=truck_weights.pop()
    sum = bridge[-1]
    while(len(bridge)!=0):
        sum-=bridge[0]
        bridge.popleft()
        if len(truck_weights)!=0:
            if sum+truck_weights[-1]>weight:
                bridge.append(0)
            else:
                bridge.append(truck_weights.pop())
                sum+=bridge[-1]
        answer+=1
    return answer