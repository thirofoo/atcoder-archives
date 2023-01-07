/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/37779434
 * Submitted at: 2023-01-07 12:16:02
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_e
 * Result: AC
 * Execution Time: 48 ms
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
    
    ll n; string s,x; input(n,s,x);

    // 解説AC (未知の集合を逆算して求めていく)
    // 最終的に 集合dp[i] の要素になるには
    // Si = 'T' の時は 10r in dp[i+1] or  10r+Si in dp[i+1] (mod7)となるrが前の集合
    // Si = 'A' の時は 10r in dp[i+1] and 10r+Si in dp[i+1] (mod7)となるrが前の集合
    // => dp[n]を{0}とした時に 0 in dp[0] (startが含まれる)なら Takahashi Win.

    vector<vector<ll>> dp(n+1);
    dp[n].push_back(0);
    for(ll i=n-1;i>=0;i--){
        // dp[i-1]にrが含まれるか全探索
        rep(r,10){
            bool f1 = false,f2 = false;
            if(x[i] == 'T'){
                for(auto ele:dp[i+1]){
                    if( (10*r)%7 == ele )f1 = true;
                    if( (10*r+s[i]-'0')%7 == ele )f2 = true;
                }
                if(f1 || f2)dp[i].push_back(r);
            }
            else{
                for(auto ele:dp[i+1]){
                    if( (10*r)%7 == ele )f1 = true;
                    if( (10*r+s[i]-'0')%7 == ele )f2 = true;
                }
                if(f1 && f2)dp[i].push_back(r);
            }
        }
    }
    print(count(dp[0].begin(),dp[0].end(),0) ? "Takahashi" : "Aoki");
    
    return 0;
}