/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc037/submissions/34672282
 * Submitted at: 2022-09-07 19:14:52
 * Problem URL: https://atcoder.jp/contests/arc037/tasks/arc037_b
 * Result: WA
 * Execution Time: 8 ms
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
    vector<vector<ll>> Graph(n);
    vector<ll> dig(n,0);
    rep(i,m){
        ll u,v; input(u,v); u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        dig[u]++; dig[v]++;
    }
    
    ll ans = 0;
    rep(i,n)if(dig[i] == 0)ans++;
    
    //サイクル検出
    vector<bool> cycle(n,false);
    queue<ll> todo;
    rep(i,n){
        if(dig[i] == 1){
            todo.push(i);
            dig[i]--;
        }
    }
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        cycle[now] = true;
        for(auto to:Graph[now]){
            if(dig[to] == 0)continue;
            dig[to]--;
            if(dig[to] == 0)todo.push(to);
        }
    }

    //サイクル内の頂点列挙 => bfs
    vector<bool> visited(n,false);
    rep(i,n)if(!cycle[i])todo.push(i);
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = true;
        for(auto to:Graph[now])todo.push(to);
    }
    rep(i,n){
        if(visited[i])continue;
        todo.push(i);
        while(!todo.empty()){
            ll now = todo.front(); todo.pop();
            if(visited[now])continue;
            visited[now] = true;
            for(auto to:Graph[now])todo.push(to);
        }
        ans++;
    }
    print(ans);
    
    return 0;
}
