/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/50671567
 * Submitted at: 2024-02-27 10:18:02
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_c
 * Result: WA
 * Execution Time: 36 ms
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
    
    ll n; cin >> n;
    vector<ll> f(n), s(n);
    rep(i,n) cin >> f[i] >> s[i];
    ll max_s = 0, max_i = 0;
    rep(i,n) {
        if( max_s < s[i] ) {
            max_s = s[i];
            max_i = i;
        }
    }
    ld ans = 0;
    rep(i,n) {
        if( i == max_i ) continue;
        ans = max(ans, (ld)s[max_i] + (ld)s[i] / (f[i] == f[max_i] ? 2.0 : 1.0));
    }
    cout << setprecision(4) << fixed << ans << endl;
    
    return 0;
}