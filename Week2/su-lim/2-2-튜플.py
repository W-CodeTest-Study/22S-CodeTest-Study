def solution(s):
    answer = []
    dict = {}
    
    s = s[1:len(s)-1] #맨 앞뒤 { } 제거
    
    for start in s.split('{'): #숫자로 변환
        if(not start): # 맨 처음 분기에서는 빈칸이 들어옴
            continue
        numbers = start.split('}')[0]
        
        values = []
        for number in numbers.split(','):
            values.append(int(number))
        dict[len(numbers.split(','))] = values
        # {원소갯수(키) : 원소리스트(값)} 쌍을 만듬
    
    answer += dict[1]
    for idx in range(1, len(dict)):
        answer += [x for x in dict[idx+1] if x not in dict[idx]]
    
    return answer