/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/50057235
 * Submitted at: 2024-02-06 18:08:49
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_e
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, a, b, p, q; cin >> n >> a >> b >> p >> q;
    vector dp(n+1,vector(n+1,vector<mint>(2,0)));
    dp[a][b][0] = 1;
    mint p_rev = mint{1}/p, q_rev = mint{1}/q;
    rep(i,0,n) rep(j,0,n) rep(f,0,2) {
        rep(num,1,(f == 0 ? p+1 : q+1)) {
            ll ni = min(i + (f == 0 ? num : 0), n);
            ll nj = min(j + (f == 1 ? num : 0), n);
            dp[ni][nj][f==0] += dp[i][j][f] * (f == 0 ? p_rev : q_rev);
        }
    }
    mint ans = 0;
    rep(i,0,n) ans += dp[n][i][0] + dp[n][i][1];
    cout << ans.val() << endl;
    
    return 0;
}