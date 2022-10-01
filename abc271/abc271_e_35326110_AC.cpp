/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/35326110
 * Submitted at: 2022-10-02 00:57:49
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_e
 * Result: AC
 * Execution Time: 76 ms
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
    
    ll n,m,k; input(n,m,k);
    vector<T> edge;
    while(m--){
        ll a,b,c; input(a,b,c);
        a--; b--;
        edge.push_back(T(a,b,c));
    }
    vector<ll> dp(n,LLONG_MAX);
    dp[0] = 0;
    rep(i,k){
        ll e; input(e); e--;
        auto [a,b,c] = edge[e];
        if(dp[a] == LLONG_MAX)continue;
        dp[b] = min(dp[a]+c,dp[b]);
    }
    print(dp[n-1] == LLONG_MAX ? -1 : dp[n-1]);
    
    return 0;
}