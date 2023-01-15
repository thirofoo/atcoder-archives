/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/38065083
 * Submitted at: 2023-01-15 21:55:10
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_e
 * Result: AC
 * Execution Time: 165 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n+1,0);
    rep(i,n)input(a[i+1]);
    for(ll i=1;i<=n;i++)a[i] += a[i-1];
    
    vector<vector<ll>> dp(n,vector<ll>(n+1,-1));
    dp[0][0] = 0;
    rep(i,n-1){
        rep(j,n){
            if(dp[i][j] == -1)continue;
            // 明日が平日
            dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
            // 明日が休日
            ll w;
            if(j == 0)w = 0;
            else if(j%2 == 0)w = a[j/2]*2;
            else w = a[j/2+1]*2 - (a[j/2+1]-a[j/2]);
            dp[i+1][0] = max(dp[i+1][0],dp[i][j] + w);
        }
    }

    ll ans = -1;
    rep(i,n){
        if(i == 0)ans = max(ans,dp[n-1][i]);
        else if(i%2 == 0)ans = max(ans,dp[n-1][i]+a[i/2]*2);
        else ans = max(ans,dp[n-1][i]+a[i/2+1]*2 - (a[i/2+1]-a[i/2]));
    }
    print(ans);
    
    return 0;
}