def sol(n, m):
    if(dp[n][m]):
        return dp[n][m]
    dp[n][m] = sol(n-1, m-1) + sol(n-1, m)
    return dp[n][m]

temp=input().split()
n=int(temp[0])
m=int(temp[1])
dp=list(list() for _ in range(n+1))
for a in dp:
    for _ in range(n+1):
        a.append(0)
for i in range(1, n+1):
    dp[i][0] = dp[i][i] = 1;
if(m>n/2):
    m = n-m
print(sol(n, m))