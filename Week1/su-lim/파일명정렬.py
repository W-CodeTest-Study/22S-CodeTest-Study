def solution(files):
    answer = []
    
    # 'IMG01.png'라면 ['IMG', 1, 'IMG01.png]로 저장하는 리스트
    file_info = [ ['','',''] for i in range(len(files))] 
    
    # 각 파일명들을 head와 number로 나누어서 저장
    for idx, file in enumerate(files):
        i = 0
        # head 저장
        for i in range(len(file)):
            if file[i].isdigit():
                file_info[idx][0] = file[0:i]
                break
        # number 저장
        for j in range(len(file)-i):
            try:
                if not file[i+j+1].isdigit():
                    file_info[idx][1] = int(file[i:i+j+1])
                    break
            except: # 맨끝까지 숫자일 경우
                if file_info[idx][1] == '':
                    file_info[idx][1] = int(file[i:])
        file_info[idx][2] = file
    
    # head와 number 기준으로 정렬
    file_info.sort(key=lambda x : (x[0].lower(), x[1]))
    
    for _, _, file in file_info:
        answer.append(file)
    return answer
