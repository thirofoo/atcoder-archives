/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc169/submissions/36748090
 * Submitted at: 2022-11-24 11:04:48
 * Problem URL: https://atcoder.jp/contests/abc169/tasks/abc169_f
 * Result: AC
 * Execution Time: 77 ms
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
    
    ll n,s; input(n,s);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<vector<mint>> dp(n+1,vector<mint>(s+1,0));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,s+1){
            // Tに含まれるときの遷移
            if(j+a[i] <= s)dp[i+1][j+a[i]] += dp[i][j];
            dp[i+1][j] += dp[i][j];

            // Tに含まれない時の遷移
            dp[i+1][j] += dp[i][j];
        }
    }
    print(dp[n][s].val());
    
    return 0;
}