/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc207/submissions/30004267
 * Submitted at: 2022-03-11 19:01:30
 * Problem URL: https://atcoder.jp/contests/abc207/tasks/abc207_a
 * Result: AC
 * Execution Time: 70 ms
 */

a,b,c = map(int,input().split())
s = [a+b,b+c,c+a]
print(max(s))