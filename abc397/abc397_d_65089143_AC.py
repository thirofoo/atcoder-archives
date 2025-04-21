/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65089143
 * Submitted at: 2025-04-21 22:50:16
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
 * Result: AC
 * Execution Time: 66 ms
 */

import sys
import math

n = int(sys.stdin.readline())
MAX_T = 1000005

for t in range(1, MAX_T + 1):
    t3 = t**3
    if t3 > n:
        break

    rem = n - t3

    if rem % (3 * t) != 0:
        continue

    left = rem // (3 * t)
    k = t // 2
    discriminant_base = k * k + left

    if discriminant_base < 0:
        continue
    
    m_float = math.sqrt(discriminant_base)
    m = int(m_float)
    y_cand = -k + m

    if y_cand * (y_cand + t) == left:
        x = y_cand + t
        if y_cand <= 0:
            continue
        print(x, y_cand)
        sys.exit()

print(-1)