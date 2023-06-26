/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/42983518
 * Submitted at: 2023-06-26 21:31:36
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_p
 * Result: AC
 * Execution Time: 56 ms
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
typedef tuple<ll, ll, ll> T;
typedef modint1000000007 mint;
typedef pair<mint, mint> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<vector<ll>> Graph(n);
    rep(i,n-1){
        ll x,y; input(x,y);
        x--; y--;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    // dp[i] : 頂点iの P(black,white)
    vector<P> dp(n,P(0,0));
    vector<bool> visited(n,false);

    auto dfs = [&](auto self, ll now){
        if( visited[now] )return dp[now];
        visited[now] = true;
        mint black = 1, white = 1;
        for(auto to:Graph[now]){
            if( visited[to] )continue;
            auto [b,w] = self(self, to);
            black *= w;
            white *= b+w;
        }
        return (dp[now] = P(black,white));
    };

    auto [b,w] = dfs(dfs, 0);
    print( (b+w).val() );
    
    return 0;
}