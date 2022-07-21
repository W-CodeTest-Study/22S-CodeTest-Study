def solution(s):
    answer = []
    s = s[2:-2]  # split('},{') 으로 할거여서 맨앞 ('{{') 맨뒤 ('}}')는 슬라이싱으로 빼고 시작
    s_str_list = list(
        map(lambda x: x.split(','), s.split('},{')))  # split('},{')으로 나누고, '2,1,3' 처럼 문자열로 이루어진 각 요소를 리스트로 변환
    s_str_list.sort(key=lambda x: len(x))  # 리스트 길이 기준 정렬

    for s_list in s_str_list:
        for s in s_list:
            if int(s) not in answer:  # 정렬되었기 때문에 없는 요소는 하나만 존재하고, 정답 리스트에 추가하면 됨 -> 순서 보장
                answer.append(int(s))  # 정수로 변환해서 넣어야 함

    return answer
