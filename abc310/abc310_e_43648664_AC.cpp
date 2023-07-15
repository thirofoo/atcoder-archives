/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43648664
 * Submitted at: 2023-07-15 23:43:15
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_e
 * Result: AC
 * Execution Time: 94 ms
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
    
    ll n; string s; input(n,s);
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    rep(i,n) dp[ i ][ s[i]-'0' ]++;
    rep(i,n-1){
        if(s[i+1] == '0'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] += dp[i][1];
        }
        else{
            dp[i+1][1] += dp[i][0];
            dp[i+1][0] += dp[i][1];
        }
    }

    ll ans = 0;
    rep(i,n) ans += dp[i][1];
    print( ans );
    
    return 0;
}