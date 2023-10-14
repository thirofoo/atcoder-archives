/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ttpc2023/submissions/46507993
 * Submitted at: 2023-10-14 13:44:08
 * Problem URL: https://atcoder.jp/contests/ttpc2023/tasks/ttpc2023_a
 * Result: AC
 * Execution Time: 61 ms
 */

N=int(input())
p=998244353
dp=[0 for _ in range(N)]
for i in range(1,N):
    dp[i]=dp[i-1]*2+1
    dp[i]%=p
print(sum(dp)%p)