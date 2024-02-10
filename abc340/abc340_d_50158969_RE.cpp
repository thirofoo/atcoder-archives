/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/50158969
 * Submitted at: 2024-02-10 21:23:34
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_d
 * Result: RE
 * Execution Time: 109 ms
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
    vector<ll> a(n), b(n), x(n), deg(n);
    vector<vector<ll>> Graph(n);
    rep(i,n-1) {
        cin >> a[i] >> b[i] >> x[i]; x[i]--;
        Graph[i].emplace_back(x[i]);
        deg[x[i]]++;
    }
    // トポロジカルソート
    queue<ll> que;
    rep(i,n) if( deg[i] == 0 ) que.push(i);
    vector<ll> p;
    while( !que.empty() ) {
        ll v = que.front(); que.pop();
        p.emplace_back(v);
        for( auto nv : Graph[v] ) {
            if( deg[nv] == 0 ) continue;
            deg[nv]--;
            if( deg[nv] == 0 ) que.push(nv);
        }
    }

    vector<ll> dp(n, 1e16);
    dp[0] = 0;
    rep(i,n-1) {
        ll ni = p[i];
        dp[i+1] = min(dp[i+1], dp[i]+a[i]);
        dp[x[ni]] = min(dp[x[ni]], dp[ni]+b[ni]);
    }
    cout << dp[n-1] << endl;
    
    return 0;
}