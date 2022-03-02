/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc014/submissions/29801333
 * Submitted at: 2022-03-02 11:38:08
 * Problem URL: https://atcoder.jp/contests/abc014/tasks/abc014_4
 * Result: AC
 * Execution Time: 311 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct Edge {
    ll to;
};
using Graph = vector<vector<Edge>>;
/* LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
    query(u,v): u と v の LCA を求める。計算量 O(logn)
    前処理: O(nlogn)時間, O(nlogn)空間
*/
struct LCA {
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
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
    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e.to != p) dfs(G, e.to, v, d + 1);
        }
    }
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
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
    int n; cin >> n;
    Graph g(n);
    rep(i,n-1){
        ll x,y; cin >> x >> y;
        x--; y--;
        g[x].push_back({y});
        g[y].push_back({x});
    }
    LCA l(g,0);
    int q; cin >> q;
    rep(i,q){
        int a,b; cin >> a >> b;
        a--; b--;
        cout << l.dist[a]+l.dist[b]-2*l.dist[l.query(a,b)]+1 << endl;
    }
    return 0;
}