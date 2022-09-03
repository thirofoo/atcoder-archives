/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc267/submissions/34583843
 * Submitted at: 2022-09-04 00:49:03
 * Problem URL: https://atcoder.jp/contests/abc267/tasks/abc267_f
 * Result: RE
 * Execution Time: 209 ms
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

struct Edge {
    long long to;
};
using Graph = vector<vector<Edge>>;
struct LCA {
    vector<vector<int>> parent;
    vector<int> dist;
    LCA(const Graph &G, int root = 0) { init(G, root); }
    // 初期化
    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e.to != p) dfs(G, e.to, v, d + 1);
        }
    }
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        int K = parent.size();
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    Graph g(n);
    rep(i,n-1){
        ll a,b; input(a,b); a--; b--;
        g[a].push_back({b});
        g[b].push_back({a});
    }

    //木の直系を求めるpart
    vector<ll> d1(n+1,0),d2(n+1,0),d3(n+1,0);
    queue<P> todo;
    todo.push(P(0,n));
    while(!todo.empty()){
        auto [now,pre] = todo.front(); todo.pop();
        d1[now] = d1[pre]+1;
        for(auto to:g[now]){
            if(to.to != pre && d1[to.to] == 0)todo.push(P(to.to,now));
        }
    }
    ll idx1 = 0,maxd = 1;
    rep(i,n){
        if(d1[i] > maxd){
            maxd = d1[i];
            idx1 = i;
        }
    }
    todo.push(P(idx1,n));
    while(!todo.empty()){
        auto [now,pre] = todo.front(); todo.pop();
        d2[now] = d2[pre]+1;
        for(auto to:g[now]){
            if(to.to != pre && d2[to.to] == 0)todo.push(P(to.to,now));
        }
    }
    ll idx2 = 0; maxd = 1;
    rep(i,n){
        if(d2[i] > maxd){
            maxd = d2[i];
            idx2 = i;
        }
    }
    todo.push(P(idx2,n));
    while(!todo.empty()){
        auto [now,pre] = todo.front(); todo.pop();
        d3[now] = d3[pre]+1;
        for(auto to:g[now]){
            if(to.to != pre && d3[to.to] == 0)todo.push(P(to.to,now));
        }
    }

    vector<vector<ll>> d4(n),d5(n);
    rep(i,n)d4[d2[i]].push_back(i);
    rep(i,n)d5[d3[i]].push_back(i);
    ll q; input(q);
    while(q--){
        ll u,k; input(u,k); u--;
        if(d2[u]+k < n && !d4[d2[u]+k].empty())print(d4[d2[u]+k].back()+1);
        else if(d2[u]-k >= 0 && !d4[d2[u]-k].empty())print(d4[d2[u]-k].back()+1);
        else if(d3[u]+k < n && !d5[d3[u]+k].empty())print(d5[d3[u]+k].back()+1);
        else if(d3[u]-k >= 0 && !d5[d3[u]-k].empty())print(d5[d3[u]-k].back()+1);
        else print(-1);
    }
    
    return 0;
}