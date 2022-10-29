/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/36077330
 * Submitted at: 2022-10-30 00:10:53
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_f
 * Result: AC
 * Execution Time: 635 ms
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    // dp[i][j][k] : i項目までの総和がjでi項目がk(1なら採用)の時の操作回数の最小値
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(m+1,vector<ll>(2,1e14)));
    dp[0][0][1] = 0;
    rep(i,n){
        rep(j,m+1){
            rep(k,2){
                ll next = j+(k ? a[i] : 0);
                if(next > m)continue;
                if(dp[i][j][0] != LLONG_MAX){
                    dp[i+1][next][k] = min(dp[i+1][next][k],dp[i][j][0]+k);
                }
                if(dp[i][j][1] != LLONG_MAX){
                    dp[i+1][next][k] = min(dp[i+1][next][k],dp[i][j][1]);
                }
            }
        }
    }
    rep(i,m){
        ll t1 = dp[n][i+1][0] + 1;
        ll t2 = dp[n][i+1][1];
        if(t1 > 3000 && t2 > 3000)print(-1);
        else print(min(t1,t2));
    }
    
    return 0;
}