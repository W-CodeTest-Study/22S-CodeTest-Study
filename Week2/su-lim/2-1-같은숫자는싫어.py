def solution(arr):
    answer = []
    answer.append(arr[0])
    
    # 현재 자료구조에 들어있는 값에서 맨끝과 일치하지 않으면 새로운 값을 추가
    for char in arr[1:]:
        if answer[-1] != char:
            answer.append(char)

    return answer