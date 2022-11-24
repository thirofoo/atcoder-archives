/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc175/submissions/36749610
 * Submitted at: 2022-11-24 13:33:55
 * Problem URL: https://atcoder.jp/contests/abc175/tasks/abc175_e
 * Result: AC
 * Execution Time: 884 ms
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
    
    ll r,c,k; input(r,c,k);
    vector<ll> item(r*c,0);
    rep(i,k){
        ll tr,tc,v; input(tr,tc,v);
        tr--; tc--;
        item[tr*c+tc] = v;
    }

    vector<vector<vector<ll>>> dp(r,vector<vector<ll>>(c,vector<ll>(4,0)));
    rep(i,r){
        rep(j,c){
            for(int l=3;l>=0;l--){
                // 次の行に行く遷移
                if(i != r-1){
                    dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][l]);
                    if(l != 3)dp[i+1][j][0] = max(dp[i+1][j][0],dp[i][j][l]+item[i*c+j]);
                }

                // 次の列に行く遷移
                if(j != c-1){
                    dp[i][j+1][l] = max(dp[i][j+1][l],dp[i][j][l]);
                    if(l != 3)dp[i][j+1][l+1] = max(dp[i][j+1][l+1],dp[i][j][l]+item[i*c+j]);
                }
            }
        }
    }
    
    ll ans = 0;
    rep(i,4){
        ans = max(ans,dp[r-1][c-1][i]+(i == 3 ? 0 : item[r*c-1]));
    }
    print(ans);
    
    return 0;
}