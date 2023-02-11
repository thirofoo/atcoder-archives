/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/38815085
 * Submitted at: 2023-02-11 22:34:48
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_e
 * Result: WA
 * Execution Time: 225 ms
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
    
    ll t; input(t);
    while(t--){
        ll n,m; input(n,m);
        vector<ll> c(n);
        rep(i,n)input(c[i]);
        vector<vector<ll>> Graph(n);
        rep(i,m){
            ll u,v; input(u,v);
            u--; v--;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        if(c[0] == c.back()){
            print(-1);
            continue;
        }
        vector<vector<ll>> dp(n,vector<ll>(n,LLONG_MAX));
        queue<T> todo;
        todo.push(T(0,0,n-1));
        while(!todo.empty()){
            auto [c,p1,p2] = todo.front(); todo.pop();
            if(dp[p1][p2] <= c)continue;
            dp[p1][p2] = c;
            for(auto to1:Graph[p1]){
                for(auto to2:Graph[p2]){
                    if(to1 == to2 || dp[to1][to2] <= c+1)continue;
                    todo.push(T(c+1,to1,to2));
                }
            }
        }
        print(dp[n-1][0] == LLONG_MAX ? -1 : dp[n-1][0]);
    }
    
    return 0;
}