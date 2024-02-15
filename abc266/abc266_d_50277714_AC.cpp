/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/50277714
 * Submitted at: 2024-02-15 10:25:23
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_d
 * Result: AC
 * Execution Time: 23 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> cost(100005, vector<ll>(5,0));
    rep(i,n) {
        ll t, x, a; cin >> t >> x >> a;
        cost[t][x] += a;
    }
    vector dp(100005, vector<ll>(5,-1));
    dp[0][0] = 0;
    rep(i,100004) {
        rep(j,5) {
            if( dp[i][j] == -1 ) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + cost[i+1][j]);
            if( j != 0 ) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + cost[i+1][j-1]);
            if( j != 4 ) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + cost[i+1][j+1]);
        }
    }
    ll ans = 0;
    rep(i,5) ans = max(ans, dp.back()[i]);
    cout << ans << endl;
    
    return 0;
}