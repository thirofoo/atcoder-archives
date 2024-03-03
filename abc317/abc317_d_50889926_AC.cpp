/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc317/submissions/50889926
 * Submitted at: 2024-03-04 08:43:15
 * Problem URL: https://atcoder.jp/contests/abc317/tasks/abc317_d
 * Result: AC
 * Execution Time: 51 ms
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
    vector<T> vote;
    ll z_total = 0;
    rep(i, n) {
        ll x, y, z; cin >> x >> y >> z;
        vote.emplace_back(x, y, z);
        z_total += z;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(100005, 1e16));
    dp[0][0] = 0;
    // dp[i][j] : i 個目の選挙区まで見て j 議席獲得時の鞍替え数
    rep(i,n) {
        auto [a, b, c] = vote[i];
        ll rest = max(0LL, (b-a+1)/2);
        rep(j,100005) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j+c] = min(dp[i+1][j+c], dp[i][j] + rest);
        }
    }
    ll ans = 1e16;
    reps(i,z_total/2+1,100005) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    
    return 0;
}