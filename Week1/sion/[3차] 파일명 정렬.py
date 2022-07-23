def solution(files):
    answer = []
    tmps = []  # (파일명, HEAD, NUMBER) 튜플 저장 리스트
    for file in files:
        tmp_number = ''
        tmp_head = ''
        digit_flag = False
        # HEAD, NUMBER 추출하기
        for idx, i in enumerate(file):
            if i.isdigit():
                tmp_number += i
                digit_flag = True
                # 숫자로 끝날 때, 마지막 인덱스 요소까지 number에 추가해주기 위한 처리
                if idx == len(file) - 1:
                    tmp_tuple = (file, tmp_head.lower(), int(tmp_number))
                    tmps.append(tmp_tuple)
            elif not digit_flag:
                tmp_head += i
            elif digit_flag:
                tmp_tuple = (file, tmp_head.lower(), int(tmp_number))
                tmps.append(tmp_tuple)
                break

    # print('HEAD: ', list(map(lambda x: x[1], tmps)))
    # print('NUMBER: ', list(map(lambda x: x[2], tmps)))
    # 1. HEAD 정렬 / 2. NUMBER 정렬
    sorted_files = sorted(tmps, key=lambda x: (x[1], x[2]))

    return list(map(lambda x: x[0], sorted_files)) # 파일명으로 리스트 변환하여 반환