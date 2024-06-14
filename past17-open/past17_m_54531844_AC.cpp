/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54531844
 * Submitted at: 2024-06-15 00:25:23
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_m
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cout << setprecision(10) << fixed;
    
    ll p1, q1, r1, s1, u1, v1, p2, q2, r2, s2, u2, v2;
    cin >> p1 >> q1 >> r1 >> s1 >> u1 >> v1 >> p2 >> q2 >> r2 >> s2 >> u2 >> v2;

    u2 -= u1;
    v2 -= v1;
    u1 = v1 = 0;

    auto normalize = [](ll& a, ll& b, ll& c, ll& d, ll factor) {
        if (factor < 0) {
            factor = -factor;
            a = -a; b = -b; c = -c; d = -d;
            swap(a, b);
            swap(c, d);
        }
        return factor;
    };

    u2 = normalize(p1, r1, p2, r2, u2);
    v2 = normalize(q1, s1, q2, s2, v2);

    p1 -= p2; q1 -= q2; r1 -= p2; s1 -= q2;
    r2 -= p2; s2 -= q2; p2 = q2 = 0;

    if (u2 == 0 && (r1 == p2 || r2 == p1)) {
        cout << 0.0 << endl;
        return 0;
    }
    if (v2 == 0 && (s1 == q2 || s2 == q1)) {
        cout << 0.0 << endl;
        return 0;
    }

    double t1 = (v2 == 0 ? -INF : static_cast<double>(q1 - s2) / v2);
    double t2 = (u2 == 0 ? -INF : static_cast<double>(p1 - r2) / u2);
    if ((r2 + u2 * t1 < p1 || r1 < p2 + u2 * t1) && (s2 + v2 * t2 < q1 || s1 < q2 + v2 * t2)) {
        cout << 0.0 << endl;
        return 0;
    }

    double t3 = (v2 == 0 ? INF : static_cast<double>(s1 - q2) / v2);
    double t4 = (u2 == 0 ? INF : static_cast<double>(r1 - p2) / u2);
    if ((r2 + u2 * t3 < p1 || r1 < p2 + u2 * t3) && (s2 + v2 * t4 < q1 || s1 < q2 + v2 * t4)) {
        cout << 0.0 << endl;
        return 0;
    }

    double start_t = max({t1, t2, 0.0});
    double end_t = min(t3, t4);

    if (start_t > end_t) {
        cout << 0.0 << endl;
        return 0;
    }
    
    cout << end_t - start_t << endl;
    return 0;
}
