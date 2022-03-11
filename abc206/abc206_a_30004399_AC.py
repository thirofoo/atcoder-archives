/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc206/submissions/30004399
 * Submitted at: 2022-03-11 19:08:54
 * Problem URL: https://atcoder.jp/contests/abc206/tasks/abc206_a
 * Result: AC
 * Execution Time: 71 ms
 */

n = int(input())
if n*1.08 < 206 :
    print("Yay!")
elif n*1.08 < 207 :
    print("so-so")
else :
    print(":(")