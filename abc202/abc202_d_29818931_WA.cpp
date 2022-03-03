/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc202/submissions/29818931
 * Submitted at: 2022-03-03 12:30:21
 * Problem URL: https://atcoder.jp/contests/abc202/tasks/abc202_d
 * Result: WA
 * Execution Time: 6 ms
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

    string ans = "";
    while(a && b){
        //今の文字列になる際に、それがaを付けてなった場合。
        if(k <= dp[a-1][b]){
            ans += "a";
            //今の文字列は1個前からaを付けて出来た場合とbを付けて出来た場合がある為、後者の分を除く。
            k -= dp[a][b-1];
            a--;
        }
        else{
            ans += "b";
            //今の文字列は1個前からaを付けて出来た場合とbを付けて出来た場合がある為、前者の分を除く。
            k -= dp[a-1][b];
            b--;
        }
    }
    while(a){
        ans += "a"; a--;
    }
    while(b){
        ans += "b"; b--;
    }

    cout << ans << '\n';
    return 0;
}