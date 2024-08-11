/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56593465
 * Submitted at: 2024-08-11 15:56:11
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_f
 * Result: WA
 * Execution Time: 1974 ms
 */

N,K=map(int,input().split())
dp=[[0 for _ in range(K+1)] for _ in range(N+1)]
lis=[]
for _ in range(N):
    A,B=map(int,input().split())
    lis.append([A/B,A,B])
lis.sort()
dp[0][0]=1
for i in range(N):
    d,a,b=lis[i]
    for j in range(K+1):
        if j!=K:
            dp[i+1][j+1]=max(dp[i+1][j+1],a*dp[i][j]+b)
        dp[i+1][j]=max(dp[i+1][j],dp[i][j])
print(dp[-1][K])