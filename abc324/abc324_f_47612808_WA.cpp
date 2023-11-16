/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/47612808
 * Submitted at: 2023-11-16 15:59:31
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_f
 * Result: WA
 * Execution Time: 114 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ld, ld>;
using T = tuple<ld, ld, ld>;
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
        ll u, v; ld b, c; cin >> u >> v >> b >> c;
        u--; v--;
        Graph[u].emplace_back(T(v,b,c));
    }
    vector<P> dp(n,P(0,0));
    rep(i,n-1) {
        auto [t1, c1] = dp[i];
        for(auto [to,b,c]:Graph[i]) {
            auto &&[t2, c2] = dp[to];
            ld v1 = (t1+b)*c2, v2 = t2*(c1+c);
            if( c2 == 0 || v1 > v2 || (v1 == v2) && c1+c <= c2 ) {
                dp[to] = P(t1+b, c1+c);
            }
        }
    }
    // rep(i,n) cerr << dp[i].first << " " << dp[i].second << endl;
    auto &&[lt,lc] = dp[n-1];
    cout << lt/lc << endl;
    
    return 0;
}