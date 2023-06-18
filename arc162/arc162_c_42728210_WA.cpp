/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc162/submissions/42728210
 * Submitted at: 2023-06-18 22:57:33
 * Problem URL: https://atcoder.jp/contests/arc162/tasks/arc162_c
 * Result: WA
 * Execution Time: 5 ms
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
    
    ll t; input(t);
    queue<ll> todo;

    while(t--){
        ll n,k; input(n,k);
        vector<ll> p(n,-1),a(n),dig(n,0);
        Graph graph(n);
        rep(i,n-1){
            input(p[i+1]);
            p[i+1]--;
            dig[i+1]++;
            dig[p[i+1]]++;
            graph[i+1].push_back(Edge{p[i+1]});
            graph[p[i+1]].push_back(Edge{i+1});
        }
        LCA lca(graph);
        ll cnt = 0, part = -1;
        rep(i,n){
            input(a[i]);
            if(a[i] != -1 && a[i] < k){
                cnt++;
                if(part == -1)part = i;
                else part = lca.query(part,i);
            }
        }

        // 基本bobの方が有利そう...?
        // Aliceの勝利条件
        // 1. part == -1 && k == 0 && 葉が2つ以上
        // 2. part == -1 && k == 0 && 葉が1つ && それが埋まってない
        // 3. part == -1 && k == 1 && 埋まってない葉が存在
        // 4. part.size() == k && k未満コンプリート
        // 5. part.size() == k && k未満1個抜け && 葉が1個空いてる
        // 6. part.size() == k+1 && コンプリート && kが無い
        // 7. part.size() == k-1 && 1個抜きコンプリート && 親が空いてる

        if(k == n){
            print("Alice");
            continue;
        }
        if(part == -1){
            vector<ll> leaf;
            for(ll i=1;i<n;i++){
                if(dig[cnt] == 1)leaf.push_back(i);
            }
            if(k == 0 && leaf.size() >= 2){
                print("Alice");
                continue;
            }
            if(k == 0 && leaf.size() == 1 && a[leaf[0]] == -1){
                print("Alice");
                continue;
            }
            if(k == 1){
                bool f = false;
                for(auto ele:leaf){
                    f &= (a[ele] == -1);
                    if(f)break;
                }
                if(f){
                    print("Alice");
                    continue;
                }
            }
            print("Bob");
        }
        else{
            todo.push(part);
            ll part_size = 0, num_cnt = 0, k_ex = 0, no = 0;
            vector<bool> visited(n,false);
            while(!todo.empty()){
                ll now = todo.front(); todo.pop();
                if(visited[now])continue;
                visited[now] = true;
                part_size++;
                if(a[now] != -1 && a[now] < k)num_cnt++;
                if(a[now] == k)k_ex++;
                if(a[now] == -1)no++;
                for(auto to:graph[now]){
                    if(to.to == p[now])continue;
                    todo.push(to.to);
                }
            }
            if(part_size == k && num_cnt == k){
                print("Alice");
                continue;
            }
            if(part_size == k && num_cnt == k-1 && no == 1){
                print("Alice");
                continue;
            }
            if(part_size == k+1 && num_cnt == k && k_ex == 0){
                print("Alice");
                continue;
            }
            if(part_size == k-1 && num_cnt == k-1 && a[p[part]] == -1){
                print("Alice");
                continue;
            }
            print("Bob");
        }
    }
    
    return 0;
}