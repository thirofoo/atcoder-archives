/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc317/submissions/44957360
 * Submitted at: 2023-08-26 21:27:19
 * Problem URL: https://atcoder.jp/contests/abc317/tasks/abc317_d
 * Result: AC
 * Execution Time: 24 ms
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
    
    ll n; cin >> n;
    ll t_seki = 0, total = 0;
    vector<T> rest;
    rep(i,n) {
        ll x,y,z; cin >> x >> y >> z;
        if( x > y ) t_seki += z;
        else rest.push_back(T(x,y,z));
        total += z;
    }
    if( t_seki >= (total+1)/2 ) {
        cout << 0 << endl;
        return 0;
    }
    ll size = (total+1)/2 - t_seki;
    vector<vector<ll>> dp(rest.size()+1,vector<ll>(size+1,1e16));
    dp[0][0] = 0;
    rep(i,rest.size()) {
        auto [x,y,z] = rest[i];
        ll need = (x+y)/2 + 1 - x;
        rep(j,size+1) {
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            dp[i+1][min(size,j+z)] = min(dp[i+1][min(size,j+z)],dp[i][j]+need);
        }
    }
    cout << dp[rest.size()].back() << endl;
    
    return 0;
}