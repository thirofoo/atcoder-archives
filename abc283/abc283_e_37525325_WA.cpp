/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/37525325
 * Submitted at: 2022-12-24 23:46:51
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_e
 * Result: WA
 * Execution Time: 100 ms
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

ll h,w;
vector<vector<ll>> field;

inline bool inGrid(int x,int y){
    if(0 <= x && x < h && 0 <= y && y < w)return true;
    else return false;
}

inline bool check(ll x,ll y,ll b1,ll b2,ll a){
    bool f = false;
    if(inGrid(x+1,y) && field[x][y]^b2 == field[x+1][y]^a )f = true;
    if(inGrid(x-1,y) && field[x][y]^b2 == field[x-1][y]^b1)f = true;
    if(inGrid(x,y+1) && field[x][y]^b2 == field[x][y+1]^b2)f = true;
    if(inGrid(x,y-1) && field[x][y]^b2 == field[x][y-1]^b2)f = true;
    return f;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(h,w);
    field.assign(h,vector<ll>(w));
    rep(i,h)rep(j,w)input(field[i][j]);

    // dp[i][j][k] : i-1行目がj,i行目がkの時のmin (j,kで二つ持たないと全パターン試せない)
    vector dp(h,vector<vector<ll>>(2,vector<ll>(2,-1)));
    dp[0][0][0] = 0,dp[0][0][1] = 1;
    for(ll i=1;i<h;i++){
        // dp前列列挙part
        rep(b1,2){
            rep(b2,2){
                if(dp[i-1][b1][b2] == -1)continue;

                // 今の行の状態列挙part
                rep(a,2){
                    bool f = true;
                    rep(j,w)f &= check(i-1,j,b1,b2,a);

                    if(f){
                        // 最後列確認part
                        if(i == h-1){
                            bool ff = true;
                            if(ff)dp[i][b2][a] = dp[i-1][b1][b2]+a;
                        }
                        else dp[i][b2][a] = dp[i-1][b1][b2]+a;
                    }
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    rep(i,2)rep(j,2)if(dp[h-1][i][j] != -1)ans = min(ans,dp[h-1][i][j]);
    print(ans == LLONG_MAX ? -1 : ans);

    return 0;
}