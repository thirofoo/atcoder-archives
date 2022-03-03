/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc202/submissions/29818534
 * Submitted at: 2022-03-03 11:53:58
 * Problem URL: https://atcoder.jp/contests/abc202/tasks/abc202_d
 * Result: WA
 * Execution Time: 4 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll a,b,k; cin >> a >> b >> k;
    vector<vector<ll>> dp(a+1,vector<ll>(b+1,0));
    dp[0][0] = 1;
    rep(i,a+1){
        rep(j,b+1){
            if(i != a)dp[i+1][j] += dp[i][j];
            if(j != b)dp[i][j+1] += dp[i][j];
        }
    }

    ll num = dp[a][b];
    string ans = "";
    while(b && a){
        if(k > num/2){
            ans += "b";
            k -= num/2;
            b--;
        }
        else{
            ans += "a";
            a--;
        }
        num = (num+1)/2;
    }
    while(a > 0){
        ans += 'a';
        a--;
    }
    while(b > 0){
        ans += 'b';
        b--;
    }
    cout << ans << '\n';
    return 0;
}