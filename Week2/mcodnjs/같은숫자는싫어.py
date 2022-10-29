def solution(arr):
    answer = []
    temp = arr[0]
    answer.append(temp)
    for i in arr[1:]:
        if i != temp:
            answer.append(i)
        temp = i
    return answer

solution([1,1,3,3,0,1,1])
solution([4,4,4,3,3])