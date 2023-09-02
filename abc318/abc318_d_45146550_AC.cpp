/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/45146550
 * Submitted at: 2023-09-02 21:19:29
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_d
 * Result: AC
 * Execution Time: 14 ms
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
    vector<vector<ll>> d(n,vector<ll>(n));
    rep(i,n) for(ll j=i+1;j<n;j++) cin >> d[i][j];

    vector<ll> dp((1ll << n), 0);
    rep(i,(1ll << n)) {
        rep(j,n) {
            if( i & (1ll << j) ) continue;
            for(ll k=j;k<n;k++) {
                if( i & (1ll << k) ) continue;
                ll nj = min(j,k), nk = max(j,k);
                dp[i | (1ll << j) | (1ll << k)] = max(dp[i | (1ll << j) | (1ll << k)], dp[i] + d[nj][nk]);
            }
        }
    }
    ll ans = 0;
    rep(i,(1ll << n)) ans = max(ans,dp[i]);
    cout << ans << endl;
    
    return 0;
}