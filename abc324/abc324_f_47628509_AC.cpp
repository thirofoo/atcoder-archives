/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/47628509
 * Submitted at: 2023-11-17 09:00:07
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_f
 * Result: AC
 * Execution Time: 474 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n, m; cin >> n >> m;
    vector<vector<T>> Graph(n);
    rep(i,m) {
        ll u, v, b, c; cin >> u >> v >> b >> c;
        u--; v--;
        Graph[u].emplace_back(T(v,b,c));
    }
    ld left = 0.0, right = 1e14;
    while( right-left > 1e-10 ) {
        ld mid = (right+left) / 2;
        vector<ld> dp(n,-1e14);
        dp[0] = 0.0;
        // b-mid*c を辺の重みとして DP
        rep(now,n) {
            for(auto &&[to,b,c]:Graph[now]) {
                dp[to] = max(dp[to], dp[now]+b-mid*c);
            }
        }
        if( dp[n-1] >= 0 ) left = mid;
        else right = mid;
    }
    cout << left << endl;
    
    return 0;
}