/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50924288
 * Submitted at: 2024-03-05 18:36:59
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_i
 * Result: WA
 * Execution Time: 740 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ld, ld>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    // p_j 全探索 ⇒ 偏角 sort っぽい ?
    vector<P> p;
    rep(i,n) {
        ld x, y; cin >> x >> y;
        p.emplace_back(P(x, y));
    }
    ld ans = 0.0;
    rep(pj,n) {
        vector<ld> angle;
        auto [xj, yj] = p[pj];
        rep(i,n) {
            if( i == pj ) continue;
            auto [xi, yi] = p[i];
            angle.emplace_back( atan2(xj-xi,yj-yi) );
        }
        sort( angle.begin(), angle.end() );
        rep(i,n) {
            // 位相が π 先に近いやつが候補
            ld n_angle = angle[i] + (angle[i] <= M_PI ? M_PI : -M_PI);
            auto itr = lower_bound(angle.begin(), angle.end(), n_angle);
            ld cand = abs( ( itr == angle.end() ? *angle.begin() : *itr ) - angle[i] );
            cand = min(2*M_PI - cand, cand);
            ans = max(ans, cand);

            cand = abs( ( itr == angle.begin() ? *angle.rbegin() : *(itr-1) ) - angle[i] );
            cand = min(2*M_PI - cand, cand);
            ans = max(ans, cand);
        }
    }
    cout << setprecision(10) << fixed;
    cout << 180.0 * ans / M_PI << endl;
    
    return 0;
}