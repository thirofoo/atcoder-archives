/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc145/submissions/42240737
 * Submitted at: 2023-06-13 22:32:02
 * Problem URL: https://atcoder.jp/contests/abc145/tasks/abc145_e
 * Result: WA
 * Execution Time: 119 ms
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
    
    ll n,t; input(n,t);
    vector<P> cook;
    rep(i,n){
        ll a,b; input(a,b);
        cook.push_back(P(a,b));
    }
    vector<vector<ll>> dp(n+1,vector<ll>(6001,-1));
    dp[0][0] = 0;
    rep(i,n){
        auto &&[a,b] = cook[i];
        rep(j,6001){
            if(dp[i][j] == -1)continue;
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j < t)dp[i+1][j+a] = max(dp[i+1][j+a],dp[i][j]+b);
        }
    }
    ll ans = 0;
    rep(i,2*t+1)ans = max(ans,dp[n][i]);
    print(ans);
    
    return 0;
}