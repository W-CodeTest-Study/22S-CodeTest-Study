def solution(triangle):
    dp=[]
    for i in range(len(triangle)):
        cnt = len(triangle[i])
        dp.append([0]*cnt)
    dp[0][0] = triangle[0][0]
    dp[1][0] = triangle[0][0] + triangle[1][0]
    dp[1][1] = triangle[0][0] + triangle[1][1]
    for i in range(2,len(dp)):
        for j in range(len(dp[i])):
            if j==0:
                dp[i][j] = triangle[i][j] + dp[i-1][j]
            elif j== len(dp[i])-1:
                dp[i][j] = triangle[i][j] + dp[i-1][len(dp[i])-2]
            else:
                dp[i][j] = max(triangle[i][j] + dp[i-1][j], triangle[i][j] + dp[i-1][j-1])
    return max(dp[-1])