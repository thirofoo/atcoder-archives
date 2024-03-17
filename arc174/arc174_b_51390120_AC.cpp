/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc174/submissions/51390120
 * Submitted at: 2024-03-17 21:37:55
 * Problem URL: https://atcoder.jp/contests/arc174/tasks/arc174_b
 * Result: AC
 * Execution Time: 7 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--) {
        vector<ll> a(5), p(5);
        ll total_a = 0, cnt = 0;
        rep(i,5) {
            cin >> a[i];
            cnt += a[i];
            total_a += a[i] * (i+1);
        }
        rep(i,5) cin >> p[i];
        if( total_a >= cnt * 3 ) {
            cout << 0 << '\n';
            continue;
        }
        // ★ 4 or 5 で平均★ 3 にしないといけない
        ll rest = cnt * 3 - total_a;
        ll ans = 0;
        if( p[3]*2 <= p[4] ) ans += (rest/2) * p[3]*2;
        else ans += (rest/2) * p[4];
        rest %= 2;
        if( p[3] <= p[4] ) ans += rest * p[3];
        else ans += rest * p[4];
        cout << ans << '\n';
    }
    
    return 0;
}