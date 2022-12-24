/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/37522800
 * Submitted at: 2022-12-24 22:51:43
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_e
 * Result: WA
 * Execution Time: 72 ms
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
    
    ll h,w; input(h,w);
    vector<vector<ll>> field(h,vector<ll>(w));
    rep(i,h)rep(j,w)input(field[i][j]);
    vector<vector<ll>> dp(h,vector<ll>(2,-1));
    vector<vector<vector<bool>>> ok(h,vector<vector<bool>>(2,vector<bool>(w,false)));
    rep(i,h){
        rep(j,w){
            if(j != 0   && !ok[i][0][j])ok[i][0][j] = (field[i][j] == field[i][j-1]);
            if(j != w-1 && !ok[i][0][j])ok[i][0][j] = (field[i][j] == field[i][j+1]);
            ok[i][1][j] = ok[i][0][j];
        }
    }
    dp[0][0] = 0,dp[0][1] = 1;
    for(ll i=1;i<h;i++){
        rep(b,2){
            if(dp[i-1][b] == -1)continue;
            rep(a,2){
                bool f = true;
                rep(j,w){
                    if(ok[i-1][b][j])continue;
                    if(field[i-1][j]^b != field[i][j]^a){
                        f = false;
                        break;
                    }
                }
                if(f && dp[i-1][b]+a > dp[i][a]){
                    dp[i][a] = dp[i-1][b]+a;
                    rep(j,w){
                        if(ok[i][a][j])continue;
                        ok[i][a][j] = (field[i-1][j]^b == field[i][j]^a);
                    }
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    if(dp[h-1][0])ans = min(ans,dp[h-1][0]);
    if(dp[h-1][1])ans = min(ans,dp[h-1][1]);
    print(ans == LLONG_MAX ? -1 : ans);

    return 0;
}