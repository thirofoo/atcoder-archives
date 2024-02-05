/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/50040079
 * Submitted at: 2024-02-05 21:48:11
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_f
 * Result: AC
 * Execution Time: 498 ms
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
    
    ll n, m; cin >> n >> m;
    // dp[i][j][k][l] : i 番目まで見て, LIS = {j,k,l} の場合の数
    vector dp(n+1,vector(m+1,vector(m+1,vector<mint>(m+1,0))));
    dp[0][0][0][0] = 1;
    rep(i,n) {
        rep(j,m+1) rep(k,m+1) rep(l,m+1) {
            for(ll to=1; to<=m; to++)  {
                // 最長増加部分列が 4 以上になるケースをシャットアウト
                vector<ll> LIS;
                LIS.emplace_back((j == 0 ? 1LL << 60 + 0 : j));
                LIS.emplace_back((k == 0 ? 1LL << 60 + 1 : k));
                LIS.emplace_back((l == 0 ? 1LL << 60 + 2 : l));
                bool f = true;
                rep(p,2) f &= (LIS[p] < LIS[p+1]);
                if( !f ) continue;
                ll idx = lower_bound(LIS.begin(), LIS.end(), to) - LIS.begin();
                if( idx == 3 ) continue;
                ll nj = (idx == 0 ? to : j), nk = (idx == 1 ? to : k), nl = (idx == 2 ? to : l);
                dp[i+1][nj][nk][nl] += dp[i][j][k][l];
            }
        }
    }
    mint ans = 0;
    rep(j,m+1) rep(k,m+1) for(ll l=1; l<=m; l++) ans += dp[n][j][k][l];
    cout << ans.val() << endl;
    
    return 0;
}