/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc153/submissions/40558162
 * Submitted at: 2023-04-12 15:55:49
 * Problem URL: https://atcoder.jp/contests/abc153/tasks/abc153_e
 * Result: AC
 * Execution Time: 76 ms
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
    
    ll h,n; input(h,n);
    vector<ll> a(n),b(n);
    rep(i,n)input(a[i],b[i]);
    vector<vector<ll>> dp(n+1,vector<ll>(h+1,1e18));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,h+1){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            dp[i][min(j+a[i],h)] = min(dp[i][min(j+a[i],h)],dp[i][j]+b[i]);
        }
    }
    print(dp[n][h]);

    return 0;
}