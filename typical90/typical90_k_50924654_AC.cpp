/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50924654
 * Submitted at: 2024-03-05 18:53:48
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_k
 * Result: AC
 * Execution Time: 127 ms
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
    vector<ll> d(n), c(n), s(n);
    rep(i,n) cin >> d[i] >> c[i] >> s[i];
    // 区間スケジューリング順で dp っぽい？
    vector<ll> p(n,0);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](ll i, ll j) {
        return d[i] < d[j];
    });

    // dp[i][j] : i 番目の仕事まで見て時刻 j の時の最大報酬
    vector dp(n+1,vector<ll>(5005,-1e16));
    dp[0][0] = 0;
    rep(i,n) rep(j,5005) {
        // 仕事をしない場合
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        // 仕事をする場合
        if( j+c[p[i]] <= d[p[i]] ) {
            dp[i+1][j+c[p[i]]] = max(dp[i+1][j+c[p[i]]], dp[i][j]+s[p[i]]);
        }
    }
    ll ans = 0;
    rep(i,5005) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    
    return 0;
}