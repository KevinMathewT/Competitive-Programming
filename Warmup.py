T = int(input())
dp = [0] * 10000010
dp[1] = 0
dp[2] = 1
dp[3] = 1

for i in range(4, 10000001):
    dp[i] = (dp[i - 2] + dp[i - 3]) % 1000000007

for _ in range(0, T):
    N = int(input())
    print(dp[N])
    