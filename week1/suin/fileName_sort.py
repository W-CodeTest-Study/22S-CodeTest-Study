def solution(files):
    answer = []
    
    for file in files:
        head, number, tail = '', '', ''
        
        for i in range(len(file)):#HEAD 구분
            if file[i].isdigit():
                head=file[:i]#숫자 기준 앞 = HEAD
                number=file[i:]
                
                for j in range(len(number)):
                    if not number[j].isdigit():
                        tail=number[j:]
                        number=number[:j]
                        break
                answer.append([head,number,tail])#하나의 배열로 만들어서 리스트의 요소로 삽입
                break
    
    #리스트 정렬
    answer = sorted(answer, key=lambda x:(x[0].lower(), int(x[1])))#1st=head, 2nd=number
    
    #문자열로 변환하여 반환 
    return [''.join(i) for i in answer]
