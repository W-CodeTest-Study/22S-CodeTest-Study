# 파일명 정렬
def solution(files):
    answer = []
    new = []
    
    for i in range(len(files)):
        k=0
        tmp = files[i][k]
        # 숫자 전까지 head에 저장
        while not tmp.isdigit():
            k += 1
            tmp = files[i][k]
        head = files[i][0:k].lower()
        index_digit = k
        # number 부분 저장
        while tmp.isdigit():
            k += 1
            if len(files[i])<=k:
                break
            tmp = files[i][k]
        number = int(files[i][index_digit:k])
        # 파일의 입력 순서 저장
        tail = i
        # 새로운 list new에 head, number, 입력 순서가 담긴 tuple 저장
        new.append((head, number, tail))

    # head, number, 입력순서 순의 우선순위로 정렬
    sorting = sorted(new, key = lambda x: (x[0], x[1], x[2]))
    
    # 정렬된 순서대로 answer에 원래의 file 명 apppend
    for i in range(len(files)):
        answer.append(files[sorting[i][2]])

    return answer

if __name__ == "__main__":
    files = ["MUZI02", "muzi1"]
    answer = solution(files)
    print(answer)