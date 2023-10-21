/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc325/submissions/46797102
 * Submitted at: 2023-10-21 21:05:19
 * Problem URL: https://atcoder.jp/contests/abc325/tasks/abc325_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> w(n), x(n);
    rep(i,n) cin >> w[i] >> x[i];
    ll ans = 0;
    rep(i,24) {
        ll cand = 0;
        rep(j,n) if( 9 <= (i+x[j])%24 && (i+x[j])%24 < 18 ) cand += w[j];
        ans = max(ans, cand);
    }
    cout << ans << endl;
    
    return 0;
}