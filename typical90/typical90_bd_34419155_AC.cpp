/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34419155
 * Submitted at: 2022-08-28 14:46:31
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bd
 * Result: AC
 * Execution Time: 39 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,s; cin >> n >> s;
    vector<ll> a(n),b(n);
    rep(i,n)cin >> a[i] >> b[i];
    vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
    dp[0][0] = true;
    rep(i,n){
        rep(j,s){
            if(!dp[i][j])continue;
            if(j+a[i] <= s)dp[i+1][j+a[i]] = true;
            if(j+b[i] <= s)dp[i+1][j+b[i]] = true;
        }
    }

    if(!dp[n][s])return cout << "Impossible" << endl,0;
    string ans = ""; ll now = s;
    for(int i=n-1;i>=0;i--){
        if((now >= a[i]) && dp[i][now-a[i]]){
            ans += "A";
            now -= a[i];
        }
        else if((now >= b[i]) && dp[i][now-b[i]]){
            ans += "B";
            now -= b[i];
        }
        else return cout << "Impossible" << endl,0;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    
    return 0;
}