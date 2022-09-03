/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc267/submissions/34553969
 * Submitted at: 2022-09-03 21:37:25
 * Problem URL: https://atcoder.jp/contests/abc267/tasks/abc267_d
 * Result: AC
 * Execution Time: 41 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector dp(n+1,vector<ll>(m+1,-LLONG_MAX));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,m+1){
            if(dp[i][j] == -LLONG_MAX)continue;
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j != m)dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+a[i]*(j+1));
        }
    }
    print(dp[n][m]);
    
    return 0;
}