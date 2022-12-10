/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37149389
 * Submitted at: 2022-12-10 21:12:25
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_d
 * Result: AC
 * Execution Time: 16 ms
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
    
    ll n,k,d; input(n,k,d);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(d,vector<ll>(k+1,-1)));
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,d){
            rep(l,k+1){
                if(dp[i][j][l] == -1)continue;
                if(l != k)dp[i+1][(j+a[i])%d][l+1] = max(dp[i+1][(j+a[i])%d][l+1],dp[i][j][l]+a[i]);
                dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]);
            }
        }
    }
    print(dp[n][0][k]);
    
    return 0;
}