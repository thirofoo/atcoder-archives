/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41928306
 * Submitted at: 2023-06-03 17:06:38
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_am
 * Result: AC
 * Execution Time: 54 ms
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

ll n;
vector<ll> part;
vector<vector<ll>> Graph;

ll dfs1(ll now, ll pre){
    part[now]++;
    for(auto to:Graph[now]){
        if(to == pre)continue;
        part[now] += dfs1(to,now);
    }
    return part[now];
}

ll ans = 0;
void dfs2(ll total, ll now, ll pre){
    ans += total;
    for(auto to:Graph[now]){
        if(to == pre)continue;
        dfs2(total - part[to] + (n-part[to]), to, now);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n);
    // 部分木の大きさを前計算 → 差分更新で隣接頂点における距離の総和がO(1)
    Graph.assign(n,{});
    rep(i,n-1){
        ll a,b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    part.assign(n,0);
    dfs1(0,-1);

    vector<ll> visited(n,0);
    queue<P> todo;
    todo.push(P(0,1));
    while(!todo.empty()){
        auto [now,t] = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = t;
        for(auto to:Graph[now]){
            if(visited[to])continue;
            todo.push(P(to,t+1));
        }
    }
    ll total = -n;
    rep(i,n)total += visited[i];

    dfs2(total,0,-1);
    print(ans/2);
    
    return 0;
}