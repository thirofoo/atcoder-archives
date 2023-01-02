/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc021/submissions/37693141
 * Submitted at: 2023-01-02 18:15:23
 * Problem URL: https://atcoder.jp/contests/abc021/tasks/abc021_c
 * Result: AC
 * Execution Time: 7 ms
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

ll a,b;
vector<mint> ans;
vector<vector<ll>> Graph2;
mint dfs(ll now){
    if(ans[now] != 0)return ans[now];
    for(auto to:Graph2[now]){
        ans[now] += dfs(to);
    }
    return ans[now];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,a,b,m);
    a--; b--;
    vector Graph1(n,vector<ll>{});
    Graph2.assign(n,{});
    ans.assign(n,0);
    rep(i,m){
        ll x,y; input(x,y);
        x--; y--;
        Graph1[x].push_back(y);
        Graph1[y].push_back(x);
    }

    queue<T> todo;
    todo.push(T(0,a,-1));
    vector<ll> visited(n,LLONG_MAX);
    while(!todo.empty()){
        auto [c,now,pre] = todo.front(); todo.pop();
        if(visited[now] < c)continue;
        if(visited[now] == c){
            Graph2[now].push_back(pre);
            continue;
        }
        visited[now] = c;
        if(pre != -1)Graph2[now].push_back(pre);

        for(auto to:Graph1[now]){
            if(visited[to] != LLONG_MAX)continue;
            todo.push(T(c+1,to,now));
        }
    }

    ans[a] = 1;
    print(dfs(b).val());
    
    return 0;
}