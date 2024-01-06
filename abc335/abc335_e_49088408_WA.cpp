/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc335/submissions/49088408
 * Submitted at: 2024-01-06 21:28:52
 * Problem URL: https://atcoder.jp/contests/abc335/tasks/abc335_e
 * Result: WA
 * Execution Time: 90 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> Graph(n);
    rep(i,m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    vector<P> p;
    rep(i,n) p.push_back(P(a[i],i));
    sort(p.begin(),p.end());

    vector<ll> dp(n,0);
    rep(i,n) {
        auto [d, now] = p[i];
        // cerr << d << " " << now << endl;
        for(auto pre:Graph[now]) {
            if( a[now] > a[pre] ) {
                dp[now] = max(dp[now], dp[pre]+1);
            }
        }
    }
    // cerr << endl;
    // rep(i,n) cout << dp[i] << " ";
    // cout << endl;
    cout << (dp[n-1] == 0 ? 0 : dp[n-1]+1) << endl;
    
    return 0;
}