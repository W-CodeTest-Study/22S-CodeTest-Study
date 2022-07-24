def solution(n, info):
    score_apeach = []
    score_rion = []
    s_a = ''
    s_r = ''

    for i in info:
        score_apeach[i] += 1

    for j in reversed(range(11)):
        if score_apeach[j] < n
            score = score_apeach[j] + 1
        score_rion[j] = score
        n = score

    for k in range(11):
        if score_apeach[k] >= score_rion[k]:
            s_a += k
        else:
            s_r += k

    if s_r > s_a:
        return score_rion
    else:
        return [-1]