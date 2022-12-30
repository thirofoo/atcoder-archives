/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/37632883
 * Submitted at: 2022-12-30 18:20:22
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_e
 * Result: AC
 * Execution Time: 19 ms
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
    
    ll n,m; input(n,m);
    vector<ll> a(n),b(m);
    rep(i,n)input(a[i]);
    rep(i,m)input(b[i]);

    // LISっぽい遷移 (Aから消す,Bから消す,AB一致時次に行く,の3つ)
    vector dp(n+1,vector<ll>(m+1,LLONG_MAX));
    dp[0][0] = 0;
    rep(i,n+1){
        rep(j,m+1){
            if(i < n && j < m){
                dp[i+1][j+1] = min(dp[i][j] + (a[i] != b[j]),dp[i+1][j+1]);
            }
            if(i < n)dp[i+1][j] = min(dp[i][j]+1,dp[i+1][j]);
            if(j < m)dp[i][j+1] = min(dp[i][j]+1,dp[i][j+1]);
        }
    }
    print(dp[n][m]);
    
    return 0;
}