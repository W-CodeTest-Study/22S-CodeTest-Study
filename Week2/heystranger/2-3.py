def solution(progresses, speeds):
    day = []  # 작업 처리소요 기간
    out = []  # 배포되는 날
    answer = []

    for i in range(len(progresses)):
        if (100 - progresses[i]) % speeds[i] != 0:
            day.append((100 - int(progresses[i])) / int(speeds[i]) + 1)
        else:
            day.append((100 - int(progresses[i])) / int(speeds[i]))

    for k in range(len(progresses)):
        if k == 0:
            out.append(int(day[i]))
        else:
            if int(out[k - 1]) < int(day[k]):
                out.append(int(out[k]) + 1)
            else:
                out.append(int(day[k]))

    for j in range(len(out)):
        if j == 0:
            answer.append(1)

        else:
            if answer[j - 1] == out[j]:
                answer[j] = (int(answer[j - 1]) + 1)
            else:
                answer.append(1)

    return answer