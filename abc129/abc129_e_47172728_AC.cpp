/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc129/submissions/47172728
 * Submitted at: 2023-11-03 14:52:05
 * Problem URL: https://atcoder.jp/contests/abc129/tasks/abc129_e
 * Result: AC
 * Execution Time: 6 ms
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
    
    // 桁dp
    // dp[i][j] : i文字目, 総和がLになれるか否か(j) の時の場合の数
    string l; cin >> l; ll n = l.size();
    vector dp(n+1,vector<mint>(2,0));
    dp[0][1] = 1;
    rep(i,n) {
        if( l[i] == '1' ) {
            dp[i+1][0] = dp[i][0]*3 + dp[i][1];
            dp[i+1][1] = dp[i][1]*2;
        }
        else {
            dp[i+1][0] = dp[i][0]*3;
            dp[i+1][1] = dp[i][1];
        }
    }
    cout << (dp[n][0]+dp[n][1]).val() << endl;

    
    return 0;
}