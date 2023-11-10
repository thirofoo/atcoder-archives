/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/47417025
 * Submitted at: 2023-11-10 12:54:29
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_e
 * Result: AC
 * Execution Time: 29 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, x; cin >> n >> x;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];

    mint inv = mint{1} / n, ans = 0;
    vector<mint> dp(x+2,0);
    dp[0] = 1;
    rep(i,x+1) {
        rep(j,n) {
            if( j == 0 && min(x+1,i+t[j]) == x+1 ) ans += dp[i] * inv;
            else dp[min(x+1,i+t[j])] += dp[i] * inv;
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}