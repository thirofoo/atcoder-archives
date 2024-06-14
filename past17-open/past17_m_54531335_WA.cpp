/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54531335
 * Submitted at: 2024-06-14 23:59:50
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_m
 * Result: WA
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll p1, q1, r1, s1, u1, v1, p2, q2, r2, s2, u2, v2;
    cin >> p1 >> q1 >> r1 >> s1 >> u1 >> v1 >> p2 >> q2 >> r2 >> s2 >> u2 >> v2;
    // - 相対速度に直して矩形 1 が止まっていると考える
    // - 同時に矩形 2 の左下のスタートが (0,0) になるように平行移動
    // - 　〃　相対速度ベクトルが (+,+) になるように符号反転
    u2 -= u1, v2 -= v1;
    u1 = v1 = 0;
    if(u2 < 0) {
        u2 *= -1;
        p1 *= -1, r1 *= -1;
        p2 *= -1, r2 *= -1;
        swap(p1, r1);
        swap(p2, r2);
    }
    if(v2 < 0) {
        v2 *= -1;
        q1 *= -1, s1 *= -1;
        q2 *= -1, s2 *= -1;
        swap(q1, s1);
        swap(q2, s2);
    }
    p1 -= p2, q1 -= q2, r1 -= p2, s1 -= q2;
    r2 -= p2, s2 -= q2, p2 = q2 = 0;

    // 矩形 2 の上辺で接するか、右辺で接するかで場合分け
    // 上辺で接する場合 ⇒ (q1 - s2) / u2 が初めて接する可能性がある時間
    // 右辺で接する場合 ⇒ (p1 - r2) / u2 が初めて接する可能性がある時間
    ld t1 = (v2 == 0 ? -INF : (ld)(q1 - s2) / v2);
    ld t2 = (u2 == 0 ? -INF : (ld)(p1 - r2) / u2);
    // cerr << t1 << " " << t2 << endl;
    // 1 秒も接しない場合は例外処理
    if((r2 + u2*t1 <= p1 || r1 <= p2 + u2*t1) && (s2 + v2*t2 <= q1 || s1 <= q2 + v2*t2)) {
        cout << (ld)0.0 << endl;
        return 0;
    }

    // 矩形 2 の下辺で接し終わるか、左辺で接し終わるかで場合分け
    // 下辺で接し終わる場合 ⇒ (s1 - q2) / v2 が最後に接する可能性がある時間
    // 左辺で接し終わる場合 ⇒ (r1 - p2) / u2 が最後に接する可能性がある時間
    ld t3 = (v2 == 0 ? INF : (ld)(s1 - q2) / v2);
    ld t4 = (u2 == 0 ? INF : (ld)(r1 - p2) / u2);
    // cerr << t3 << " " << t4 << endl;
    // 1 秒も接しない場合は例外処理
    if((r2 + u2*t3 <= p1 || r1 <= p2 + u2*t3) && (s2 + v2*t4 <= q1 || s1 <= q2 + v2*t4)) {
        cout << (ld)0.0 << endl;
        return 0;
    }

    ld start_t = max({t1, t2, (ld)0.0});
    ld end_t = min(t3, t4);
    // cerr << start_t << " " << end_t << endl;
    
    if(start_t > end_t) {
        cout << (ld)0.0 << endl;
        return 0;
    }
    cout << end_t - start_t << endl;
    
    return 0;
}