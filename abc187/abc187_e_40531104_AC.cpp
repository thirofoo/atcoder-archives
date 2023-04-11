/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/40531104
 * Submitted at: 2023-04-11 15:21:16
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_e
 * Result: AC
 * Execution Time: 223 ms
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

struct Edge {
    ll to;
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
        //parent[i][j] : 2^i先の親
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
    vector<P> edge;
    Graph graph(n);
    rep(i,n-1){
        ll a,b; input(a,b);
        a--; b--;
        graph[a].push_back({b});
        graph[b].push_back({a});
        edge.push_back(P(a,b));
    }
    LCA lca(graph);

    ll q; input(q);
    vector<ll> ans(n,0);
    while(q--){
        ll t,e,x; input(t,e,x);
        e--;
        auto [a,b] = edge[e];
        if(t == 2)swap(a,b);
        if(lca.query(a,b) == b){
            ans[a] += x;
        }
        else{
            ans[0] += x;
            ans[b] -= x;
        }
    }
    queue<P> todo;
    todo.push(P(0,-1));
    while(!todo.empty()){
        auto [now,pre] = todo.front(); todo.pop();
        if(pre != -1)ans[now] += ans[pre];
        for(auto next:graph[now]){
            if(next.to == pre)continue;
            todo.push(P(next.to,now));
        }
    }
    rep(i,n)print(ans[i]);
    
    return 0;
}