# 위장
def solution(clothes):
    answer = 1
    dictionary = {}
    # dictionary에 어떤 clothes 종류 들어왔는지 저장
    for i in range(len(clothes)):
        dictionary[clothes[i][1]] = 0
    # dictionary에 clothes 종류 개수 저장
    for i in range(len(clothes)):
        dictionary[clothes[i][1]] += 1
    # 가능한 가짓수 계산
    for key in dictionary:
        answer *= (dictionary[key] + 1)
    
    answer -= 1

    return answer


if __name__ == "__main__":
    clothes = [["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]
    answer = solution(clothes)
    print(answer)