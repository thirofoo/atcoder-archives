/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc307/submissions/42923791
 * Submitted at: 2023-06-24 22:21:00
 * Problem URL: https://atcoder.jp/contests/abc307/tasks/abc307_e
 * Result: AC
 * Execution Time: 85 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<vector<mint>> dp(n,vector<mint>(2,0));
    dp[0][1] = 1;
    rep(i,n-1){
        dp[i+1][0] += (m-2)*dp[i][0];
        dp[i+1][0] += (m-1)*dp[i][1];
        dp[i+1][1] += dp[i][0];
    }
    print( (dp[n-1][0]*m).val() );
    
    return 0;
}