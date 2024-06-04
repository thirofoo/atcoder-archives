/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc330/submissions/54219035
 * Submitted at: 2024-06-04 14:11:56
 * Problem URL: https://atcoder.jp/contests/abc330/tasks/abc330_f
 * Result: AC
 * Execution Time: 949 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    
    ll n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    auto x_cnt = [&](ll l, ll len) -> ll {
        ll res = 0;
        rep(i, n) {
            if( l <= x[i] && x[i] <= l + len ) continue;
            res += min(abs(x[i] - l), abs(x[i] - (l + len)));
        }
        return res;
    };

    auto y_cnt = [&](ll l, ll len) -> ll {
        ll res = 0;
        rep(i, n) {
            if( l <= y[i] && y[i] <= l + len ) continue;
            res += min(abs(y[i] - l), abs(y[i] - (l + len)));
        }
        return res;
    };

    ll l1 = -1, r1 = INF, l2, r2, m1, m2, m3;
    while(r1 - l1 > 1) {
        m1 = (l1 + r1) / 2;
        ll op_num = 0;

        // x 軸方向の左端座標
        l2 = 0, r2 = INF;
        while(r2 - l2 > 2) {
            m2 = (l2 + r2) / 2, m3 = m2 + 1;
            ll cnt2 = x_cnt(m2, m1);
            ll cnt3 = x_cnt(m3, m1);
            if(cnt2 < cnt3) r2 = m3;
            else l2 = m2;
        }
        op_num += min(x_cnt(l2, m1), x_cnt(l2+1, m1));
        // y 軸方向の下端座標
        l2 = 0, r2 = INF;
        while(r2 - l2 > 2) {
            m2 = (l2 + r2) / 2, m3 = m2 + 1;
            ll cnt2 = y_cnt(m2, m1);
            ll cnt3 = y_cnt(m3, m1);
            if(cnt2 < cnt3) r2 = m3;
            else l2 = m2;
        }
        op_num += min(y_cnt(l2, m1), y_cnt(l2+1, m1));

        if(op_num <= k) r1 = m1;
        else l1 = m1;
    }
    cout << r1 << endl;
    
    return 0;
}