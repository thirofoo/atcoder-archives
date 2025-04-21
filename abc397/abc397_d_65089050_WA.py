/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65089050
 * Submitted at: 2025-04-21 22:47:15
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
 * Result: WA
 * Execution Time: 63 ms
 */

import sys
import math

# Read input
n = int(sys.stdin.readline())

# The C++ code iterates t from 1 up to a certain limit (1000005).
# This 't' in the C++ code corresponds to the difference (x - y), where x > y since n > 0.
# If x - y = t, then x = y + t. Substituting into x^3 - y^3 = n:
# (y + t)^3 - y^3 = n
# y^3 + 3y^2t + 3yt^2 + t^3 - y^3 = n
# 3y^2t + 3yt^2 + t^3 = n
# Rearranging: n - t^3 = 3y^2t + 3yt^2 = 3t(y^2 + ty)
# Let left = y^2 + ty = y(y+t). Then n - t^3 = 3t * left.
# This means left = (n - t^3) / (3t).
# The C++ code iterates through possible integer values for t (from 1 upwards).
# For each t, it calculates the required integer value for 'left' such that t^3 + 3t*left = n.
# Then, it checks if this 'left' can be expressed as y(y+t) for some integer y.

MAX_T = 1000005 # Corresponds to the upper limit in the C++ loop

for t in range(1, MAX_T + 1):
    t3 = t**3

    # The C++ code breaks the loop if t^3 > n.
    # If t = x-y and t^3 > n, it is still possible to have a solution if y is negative.
    # However, we are porting the C++ code as is, including this break condition.
    if t3 > n:
        break

    # Calculate the required value for 'left' based on t^3 + 3t*left = n.
    # left = (n - t^3) / (3t).
    # For 'left' to be an integer, (n - t^3) must be divisible by (3t).
    rem = n - t3

    # If rem is not divisible by 3*t, no integer 'left' exists satisfying the equation for this t.
    # The C++ binary search for 'left' would effectively fail to find an integer 'left' that satisfies the equality check t*t*t + 3*left*t == n.
    if rem % (3 * t) != 0:
        continue

    # Calculate the integer 'left'.
    left = rem // (3 * t)

    # Now we need to check if this integer 'left' can be written as y(y+t) for some integer y.
    # This is equivalent to solving the quadratic equation y^2 + ty - left = 0 for integer y.
    # The C++ code uses a specific calculation for y, derived from completing the square, but using integer division for t/2.
    # The equation y^2 + ty = left can be written as y^2 + ty + (t/2)^2 = left + (t/2)^2.
    # (y + t/2)^2 = left + (t/2)^2
    # y + t/2 = +/- sqrt(left + (t/2)^2)
    # y = -t/2 +/- sqrt(left + (t/2)^2)
    # The C++ code uses: y = floor(-t/2) + int(sqrt(floor(t/2)^2 + left))

    k = t // 2 # Integer division, equivalent to C++ (ll)(t/2)
    discriminant_base = k * k + left # Corresponds to floor(t/2)^2 + left

    # If the value inside the square root is negative, there is no real solution for y.
    if discriminant_base < 0:
        continue

    # Calculate the square root. Use math.sqrt for potentially non-integer results.
    m_float = math.sqrt(discriminant_base)

    # The C++ code casts the result of sqrt to long long (ll), which truncates the decimal part.
    # Python's int() does the same for non-negative numbers.
    m = int(m_float)

    # Calculate the candidate integer y using the C++ specific formula (corresponds to one of the two quadratic roots)
    y_cand = -k + m

    # Verify if this specific integer y_cand satisfies the condition y(y+t) == left.
    # This check is crucial. If it holds, and we calculated 'left' correctly,
    # then (y_cand + t)^3 - y_cand^3 = n is satisfied, and (x, y_cand) is an integer solution.
    if y_cand * (y_cand + t) == left:
        # If the check passes, we have found an integer y_cand.
        # The corresponding x is y_cand + t.
        x = y_cand + t

        # Output the solution (x, y) and terminate the program.
        print(x, y_cand)
        sys.exit()

# If the loop finishes without finding a solution in the checked range
print(-1)