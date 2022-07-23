def solution(arr):
    a=[]
    for i in arr:
        print("{},{}".format(a[-1:],[i]))
        if a[-1:] == [i]: continue
        a.append(i)
    return a