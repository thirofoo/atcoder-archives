/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc113/submissions/31503681
 * Submitted at: 2022-05-08 11:42:35
 * Problem URL: https://atcoder.jp/contests/abc113/tasks/abc113_d
 * Result: AC
 * Execution Time: 21 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

string to2(int n){
    string ans = "";
    while(n){
        ans += to_string(n%2);
        n /= 2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int h,w,k; cin >> h >> w >> k;
    vector<vector<mint>> dp(h+1,vector<mint>(w,0));
    dp[0][0] = 1;
    rep(i,h){
        for(int l=0;l<(1 << w-1);l++){
            string tmp = to2(l);
            if(tmp.find("11") != tmp.npos)continue;
            rep(j,w){
                if(j != w-1 && l & (1 << j))dp[i+1][j+1] += dp[i][j];
                else if(j != 0 && l & (1 << j-1))dp[i+1][j-1] += dp[i][j];
                else dp[i+1][j] += dp[i][j];
            }
        }
    }
    cout << dp[h][k-1].val() << endl;
    return 0;
}