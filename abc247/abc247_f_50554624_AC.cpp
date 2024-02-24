/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/50554624
 * Submitted at: 2024-02-24 18:14:53
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_f
 * Result: AC
 * Execution Time: 52 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    // dp[i][j] : i 個の辺を見た時に前の辺を用いたか j の場合の数
    vector dp1(n+1, vector<mint>(2, 0)), dp2(n+1, vector<mint>(2, 0));
    dp1[0][0] = 1, dp2[0][1] = 1;
    rep(i,n) {
        dp1[i+1][1] += dp1[i][0]; dp2[i+1][1] += dp2[i][0];
        dp1[i+1][0] += dp1[i][1]; dp2[i+1][0] += dp2[i][1];
        dp1[i+1][1] += dp1[i][1]; dp2[i+1][1] += dp2[i][1];
    }
    vector<mint> num(n+1, 0);
    rep(i,n+1) num[i] = dp1[i][1] + dp2[i][0] + dp2[i][1];
    // rep(i,n+1) cerr << num[i].val() << " ";
    // cerr << endl;

    dsu uf(n);
    rep(i,n) uf.merge(p[i]-1, q[i]-1);
    vector g = uf.groups();
    mint ans = 1;
    rep(i,g.size()) ans *= num[g[i].size()-1];
    cout << ans.val() << endl;
    
    return 0;
}