/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/44229392
 * Submitted at: 2023-08-04 18:36:57
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_e
 * Result: AC
 * Execution Time: 32 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    // 解説AC
    // 最適行動の為、上位桁から愚直しても下位桁でまくられることが多々
    // → 終了条件が満たされた時に開始条件が満たされてるかで DP !!

    ll n; string x,s; cin >> n >> s >> x;
    vector<bool> dp(7,false), ndp;
    dp[0] = true;
    reverse(s.begin(),s.end());
    reverse(x.begin(),x.end());
    ll r = 1;
    rep(i,n) {
        // for(auto ele:dp)cout << ele << " ";
        // cout << endl;
        ndp.assign(7,false);
        // j : 1桁上がった時に Takahashi が勝つ桁の数字
        if( x[i] == 'A' ) {
            rep(j,7) for(auto ele:dp) if( dp[j] && dp[(j+(s[i]-'0')*r)%7] ) ndp[j] = true;
        }
        else {
            rep(j,7) for(auto ele:dp) if( dp[j] || dp[(j+(s[i]-'0')*r)%7] ) ndp[j] = true;
        }
        swap(dp, ndp);
        r *= 10;
        r %= 7;
    }
    cout << (dp[0] ? "Takahashi" : "Aoki") << endl;
    
    return 0;
}