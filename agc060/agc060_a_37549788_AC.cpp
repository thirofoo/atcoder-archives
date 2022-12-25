/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc060/submissions/37549788
 * Submitted at: 2022-12-26 00:20:13
 * Problem URL: https://atcoder.jp/contests/agc060/tasks/agc060_a
 * Result: AC
 * Execution Time: 147 ms
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
    vector<vector<mint>> dp(n,vector<mint>(26*26,0));
    rep(i,26*26){
        ll pp = i/26,p = i%26;
        if(pp == p)continue;
        if((s[0] == '?' || s[0]-'a' == pp) && (s[1] == '?' || s[1]-'a' == p)){
            dp[1][i] = 1;
        }
    }

    for(int i=2;i<n;i++){
        rep(j,26*26){
            ll pp = j/26,p = j%26;
            if(pp == p)continue;
            if(s[i] == '?'){
                rep(k,26){
                    if(k != pp && k != p){
                        dp[i][26*p+k] += dp[i-1][j];
                    }
                }
            }
            else{
                if(s[i]-'a' != pp && s[i]-'a' != p){
                    dp[i][26*p+(s[i]-'a')] += dp[i-1][j];
                }
            }
        }
    }
    mint ans = 0;
    rep(i,26*26)ans += dp[n-1][i];
    print(ans.val());
    
    return 0;
}