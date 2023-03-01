/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/39326983
 * Submitted at: 2023-03-01 12:53:06
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_e
 * Result: WA
 * Execution Time: 123 ms
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
    
    ll n,m; input(n,m);
    vector<ll> height(n);
    rep(i,n)input(height[i]);
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    // 結局は上った分だけ楽しさが減るから、減少分の最小値をdijkstra
    vector<ll> c(n,1e16);
    priority_queue<P,vector<P>,greater<P>> todo;
    todo.push(P(0,0));
    while(!todo.empty()){
        auto [cost,now] = todo.top(); todo.pop();
        if(c[now] <= cost)continue;
        c[now] = cost;
        for(auto to:Graph[now]){
            ll nc = cost + max(height[to]-height[now],0LL);
            if(c[to] <= nc)continue;
            todo.push(P(nc,to));
        }
    }
    ll ans = LLONG_MAX;
    rep(i,n)ans = min(ans,-c[i]+height[i]);
    print(ans);
    
    return 0;
}