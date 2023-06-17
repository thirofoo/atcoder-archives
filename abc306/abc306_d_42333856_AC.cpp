/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc306/submissions/42333856
 * Submitted at: 2023-06-17 21:12:03
 * Problem URL: https://atcoder.jp/contests/abc306/tasks/abc306_d
 * Result: AC
 * Execution Time: 74 ms
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
    vector<vector<ll>> dp(n+1,vector<ll>(3,0));
    dp[0][0] = 0;
    rep(i,n){
        ll x,y; input(x,y);
        dp[i+1][0] = max(dp[i+1][0],dp[i][0]);
        dp[i+1][1] = max(dp[i+1][1],dp[i][1]);
        if(x == 0){
            dp[i+1][0] = max(dp[i+1][0],dp[i][0]+y);
            dp[i+1][0] = max(dp[i+1][0],dp[i][1]+y);
        }
        else{
            dp[i+1][1] = max(dp[i+1][1],dp[i][0]+y);
        }
    }
    print( max(dp[n][0],dp[n][1]) );
    
    return 0;
}