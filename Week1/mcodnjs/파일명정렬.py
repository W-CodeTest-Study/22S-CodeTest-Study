def solution(files):
    answer = []
    divs = []

    for f in files:
        divide = ["", "", ""] # HEAD, NUMBER, TAIL
        flag = 0 # HEAD = 0, NUMBER >= 1, TAIL = -1
       
        for i in f: # HEAD, NUMBER, TAIL로 나누는 알고리즘
            if i.isdigit() == True and flag != -1: # NUMBER
                if flag == 4:   flag = -1 # 5개가 넘어가면 TAIL로 만들어줌
                else: flag += 1
                divide[1] = divide[1] + i
                continue 

            if flag == 0: divide[0] = divide[0] + i # HEAD
            else: # TAIL 
                flag = -1
                divide[2] = divide[2] + i
        divs.append(divide)

    # 대소문자 구분 없이 HEAD 정렬, 0제외한 NUMBER 정렬
    divs.sort(key=lambda x:(x[0].lower(), int(x[1]))) 

    for div in divs:
        answer.append(''.join(s for s in div))
    return answer

solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"])
print("==============================================")
solution(["F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"])
print("==============================================")
solution(["abc123456.png", "abc00004.png", "abc00003.png"])
print("==============================================")
solution(["foo010bar020.zip", "foo9.txt", "F-15"])