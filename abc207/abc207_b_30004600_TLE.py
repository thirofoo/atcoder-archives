/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc207/submissions/30004600
 * Submitted at: 2022-03-11 19:20:00
 * Problem URL: https://atcoder.jp/contests/abc207/tasks/abc207_b
 * Result: TLE
 * Execution Time: 2207 ms
 */

import sys

a,b,c,d = map(int,input().split())
if b > c*d:
    print(-1)
    sys.exit()

cnt,tmp = 0,0
while a > tmp*d:
    a += b
    tmp += c
    cnt += 1
print(cnt)
