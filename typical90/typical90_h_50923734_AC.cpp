/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50923734
 * Submitted at: 2024-03-05 18:14:35
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_h
 * Result: AC
 * Execution Time: 9 ms
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
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; cin >> n >> s;
    static const string atcoder = "atcoder";
    vector dp(n+1,vector<mint>(atcoder.size()+1,0));
    dp[0][0] = 1;
    rep(i,n) rep(j,atcoder.size()) {
        dp[i+1][j] += dp[i][j];
        if( s[i] == atcoder[j] ) dp[i+1][j+1] += dp[i][j];
    }
    mint ans = 0;
    rep(i,n+1) ans += dp[i][atcoder.size()];
    cout << ans.val() << endl;
    
    return 0;
}