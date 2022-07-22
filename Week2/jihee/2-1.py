# 같은숫자는 싫어
def solution(arr):
    answer = []
    # stack을 이용해 바로 앞의 원소와 같다면 answer에 저장하지 않고,
    # 같지 않다면 answer에 저장
    for i in range(len(arr)):
        if answer: 
            tmp = answer.pop()
            # 바로 앞의 원소와 같지 않다면 answer에 저장
            if tmp != arr[i]:
                answer.append(tmp)
                answer.append(arr[i])
            # 바로 앞의 원소와 같다면 저장 x
            else:
                answer.append(tmp)
        else:
            answer.append(arr[i])

    return answer
    

if __name__ == "__main__":
    arr = [1,1,3,3,0,1,1]
    answer = solution(arr)
    print(answer)