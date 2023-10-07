/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc224/submissions/46269423
 * Submitted at: 2023-10-07 13:16:05
 * Problem URL: https://atcoder.jp/contests/abc224/tasks/abc224_f
 * Result: AC
 * Execution Time: 21 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    ll n = s.size();
    vector dp(n+1,vector<mint>(2,0));
    dp[1][1] = s[0]-'0';
    // dp[i][j] : j=0 ⇒ ?~i文字目が連続のものの総和
    //            j=1 ⇒ ↑出ないものの総和
    for(int i=1;i<n;i++) {
        dp[i+1][0] = dp[i][0]*2 + dp[i][1];
        dp[i+1][1] = dp[i][1]*10 + mint(2).pow(i)*(s[i]-'0');
    }
    cout << (dp[n][0]+dp[n][1]).val() << endl;
    
    return 0;
}