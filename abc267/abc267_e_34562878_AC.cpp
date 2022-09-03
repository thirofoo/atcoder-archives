/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc267/submissions/34562878
 * Submitted at: 2022-09-03 21:58:26
 * Problem URL: https://atcoder.jp/contests/abc267/tasks/abc267_e
 * Result: AC
 * Execution Time: 205 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll u,v; input(u,v); u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    priority_queue<P,vector<P>,greater<P>> todo;
    vector<ll> c(n);
    rep(i,n){
        ll cost = 0;
        for(auto to:Graph[i])cost += a[to];
        c[i] = cost;
        todo.push(P(cost,i));
    }

    ll ans = -LLONG_MAX;
    vector<bool> visited(n,false);
    while(!todo.empty()){
        auto [cost,i] = todo.top(); todo.pop();
        if(visited[i])continue;
        visited[i] = true;
        ans = max(ans,cost);
        for(auto to:Graph[i]){
            c[to] -= a[i];
            if(!visited[to])todo.push(P(c[to],to));
        }
    }
    print(ans);
    
    return 0;
}