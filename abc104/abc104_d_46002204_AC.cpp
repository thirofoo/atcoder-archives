/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc104/submissions/46002204
 * Submitted at: 2023-09-28 14:22:25
 * Problem URL: https://atcoder.jp/contests/abc104/tasks/abc104_d
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    vector dp(s.size()+1,vector<mint>(4,0));
    dp[0][0] = 1;
    rep(i,s.size()) {
        rep(j,4) {
            if( s[i] == '?' ) {
                if( j != 3 ) dp[i+1][j+1] += dp[i][j];
                dp[i+1][j] += 3*dp[i][j];
            }
            else {
                if( s[i]-'A' == j ) dp[i+1][j+1] += dp[i][j];
                dp[i+1][j] += dp[i][j];
            }
        }
    }
    cout << dp[s.size()][3].val() << endl;
    
    return 0;
}