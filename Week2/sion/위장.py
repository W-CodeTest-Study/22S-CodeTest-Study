# 테스트케이스 1번 시간초과로 96.4점에서 벗어나지 못함,,

import collections
import itertools
import math


def solution(clothes):
    answer = 0
    cl_dict = collections.defaultdict(int)
    for cl in clothes:
        cl_name, cl_type = cl[0], cl[1]
        cl_dict[cl_type] += 1  # defaultdict 사용으로 없는 키 바로 접근 가능

    nr_cl = list(cl_dict.values())  # 종류에 따른 의상 개수만 리스트로 변환

    for i in range(1, len(nr_cl) + 1):
        if i == 1:  # 1일 때의 경우의 수는 각 요소끼리 합
            answer += sum(nr_cl)
        else:  # r일 때의 경우의 수는 nCr의 조합 가능. 조합끼리 곱하여 더해준다.
            answer += sum([math.prod(cl) for cl in itertools.combinations(nr_cl, i)])

    return answer