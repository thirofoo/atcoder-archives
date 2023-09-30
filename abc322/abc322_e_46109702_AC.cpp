/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc322/submissions/46109702
 * Submitted at: 2023-09-30 22:04:03
 * Problem URL: https://atcoder.jp/contests/abc322/tasks/abc322_e
 * Result: AC
 * Execution Time: 340 ms
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
    
    ll n, k, p; cin >> n >> k >> p;
    vector<ll> c(n);
    vector<vector<ll>> a(n,vector<ll>(k));
    rep(i,n) {
        cin >> c[i];
        rep(j,k) cin >> a[i][j];
    }
    vector<map<vector<ll>,ll>> dp(n+1);
    vector<ll> tmp(k,0);
    dp[0][tmp] = 0;
    rep(i,n) {
        for(auto &&[vec, v]:dp[i]) {
            if( dp[i+1].count(vec) ) dp[i+1][vec] = min(dp[i+1][vec],v);
            else dp[i+1][vec] = v;

            vector<ll> next(k,0);
            rep(j,k) next[j] = min(vec[j] + a[i][j], p);

            if( dp[i+1].count(next) ) dp[i+1][next] = min(dp[i+1][next],v + c[i]);
            else dp[i+1][next] = v + c[i];
        }
    }
    tmp.assign(k,p);
    cout << ( dp[n].count(tmp) ? dp[n][tmp] : -1 ) << endl;
    
    return 0;
}