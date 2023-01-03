/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc060/submissions/37710201
 * Submitted at: 2023-01-03 16:36:58
 * Problem URL: https://atcoder.jp/contests/agc060/tasks/agc060_a
 * Result: WA
 * Execution Time: 255 ms
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
    
    ll n; string s; input(n,s);
    // dp[i][now][pre]
    vector dp(n,vector<vector<mint>>(26,vector<mint>(26,0)));
    if(s[0] == '?'){
        rep(i,26){
            if(s[1] == '?')rep(j,26)dp[1][j][i]++;
            else dp[1][s[1]-'a'][i]++;
        }
    }
    else{
        if(s[1] == '?')rep(i,26)dp[1][i][s[0]-'a']++;
        else dp[1][s[1]-'a'][s[0]-'a']++;
    }

    for(ll i=2;i<n;i++){
        if(s[i] == '?'){
            // ?の全探索
            rep(l,26){
                // 前の場面の全探索
                rep(j,26){
                    rep(k,26){
                        if(l == j || l == k || j == k)continue;
                        dp[i][l][j] += dp[i-1][j][k];
                    }
                }
            }
        }
        else{
            rep(j,26){
                rep(k,26){
                    if(s[i]-'a' == j || s[i]-'a' == k || j == k)continue;
                    dp[i][s[i]-'a'][j] += dp[i-1][j][k];
                }
            }
        }
    }
    mint ans = 0;
    rep(i,26)rep(j,26)ans += dp[n-1][i][j];
    print(ans.val());
    
    return 0;
}