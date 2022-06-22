/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc215/submissions/32654962
 * Submitted at: 2022-06-22 16:13:28
 * Problem URL: https://atcoder.jp/contests/abc215/tasks/abc215_e
 * Result: AC
 * Execution Time: 120 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; string s; cin >> n >> s;
    vector<vector<vector<mint>>> dp(n+1,vector<vector<mint>>(1 << 10,vector<mint>(11,0)));
    dp[0][0][0] = 1;
    
    rep(i,n){
        rep(j,1<<10){
            rep(k,11){
                dp[i+1][j][k] += dp[i][j][k];
                if((j & (1LL << s[i]-'A')) && k != s[i]-'A'+1)continue;
                dp[i+1][j | (1LL << s[i]-'A')][s[i]-'A'+1] += dp[i][j][k];
            }
        }
    }

    mint ans = 0;
    rep(i,1<<10)rep(j,10)ans += dp[n][i][j+1];
    cout << ans.val() << endl;

    return 0;
}