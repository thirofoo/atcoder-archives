/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/36162166
 * Submitted at: 2022-11-03 00:15:29
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_e
 * Result: AC
 * Execution Time: 17 ms
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
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,LLONG_MAX));
    rep(i,n+1)dp[i][0] = i;
    rep(i,m+1)dp[0][i] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min(dp[i][j],dp[i][j-1] + 1);
            dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
            dp[i][j] = min(dp[i][j],dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1));
        }
    }
    print(dp[n][m]);
    
    return 0;
}