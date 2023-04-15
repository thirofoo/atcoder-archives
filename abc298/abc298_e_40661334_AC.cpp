/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/40661334
 * Submitted at: 2023-04-15 21:55:44
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_e
 * Result: AC
 * Execution Time: 102 ms
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
    
    ll n,a,b,p,q; input(n,a,b,p,q);
    vector dp(2*n+5,vector<vector<mint>>(n+1,vector<mint>(n+1,0)));
    dp[0][a][b] = 1;
    mint ans = 0, total = 1;
    rep(i,2*n+2){
        if(i%2 == 0)total *= p;
        else total *= q;
        rep(j,n){
            rep(k,n){
                if(i%2 == 0){
                    // takahashi
                    for(ll l=1;l<=p;l++){
                        dp[i+1][min(j+l,n)][k] += dp[i][j][k];
                        if(min(j+l,n) == n){
                            ans += dp[i][j][k] * (1/total);
                        }
                    }
                }
                else {
                    // aoki
                    for(ll l=1;l<=q;l++){
                        dp[i+1][j][min(k+l,n)] += dp[i][j][k];
                    }
                }
            }
        }
    }
    print(ans.val());
    
    return 0;
}