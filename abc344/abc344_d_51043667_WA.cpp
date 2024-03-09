/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc344/submissions/51043667
 * Submitted at: 2024-03-09 21:14:20
 * Problem URL: https://atcoder.jp/contests/abc344/tasks/abc344_d
 * Result: WA
 * Execution Time: 2 ms
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
    
    string t; ll n; cin >> t >> n;
    vector<vector<string>> a;
    rep(i,n) {
        ll size; cin >> size;
        vector<string> tmp(size);
        rep(j,size) cin >> tmp[j];
        a.emplace_back(tmp);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(t.size()+1,1e16));
    dp[0][0] = 0;
    rep(i,n) rep(j,t.size()) {
        dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
        rep(l,a[i].size()) {
            if( j+a[i][l].size() > t.size() ) continue;
            bool flag = true;
            rep(k,a[i][l].size()) flag &= (t[j+k] == a[i][l][k]);
            if( flag ) dp[i+1][j+a[i][l].size()] = min(dp[i+1][j+a[i][l].size()],dp[i][j]+1);
        }
    }
    cout << (dp[n][t.size()] == 1e16 ? -1 : dp[n][t.size()]) << endl;
    
    return 0;
}