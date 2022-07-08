cnt = int(input())#첫째 줄 : 단어 개수 입력
s_list = [input() for _ in range(cnt)] #문자열 여러 개 입력받기
s_list = list(set(s_list))#list를 set으로 변환하여 중복값 제거 후 다시 list로 변환
s_list.sort(key=lambda x: (len(x),x))#1st: 길이 짧은 것, 2nd: 오름차순

for i in s_list:
    print(i)#한줄에 하나의 요소 출력
