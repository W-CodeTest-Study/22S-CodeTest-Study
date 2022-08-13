n = 6
times = [7,10]

left = 1
right = max(times)*n
answer = 0
while left <= right:
    mid = (left+right)//2
    people = 0
    for time in times:
        people += mid//time

        if people >=n:
            break
    if people >=n:
        answer = mid
        right = mid -1

    elif people<n:
        left=mid+1
print(answer)