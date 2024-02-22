/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/50515389
 * Submitted at: 2024-02-22 20:27:39
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_v
 * Result: AC
 * Execution Time: 130 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// EDPC-V Subtree : https://atcoder.jp/contests/dp/tasks/dp_v
template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>
struct RerootingDP {
    // https://trap.jp/post/1702/
    struct edge {
        int to, idx, xdi;
    };
    RerootingDP(int n_ = 0) : n(n_), inner_edge_id(0) {
        outs.resize(n);
        es.resize(2*n-2);
        start.resize(2*n-2);
        if( n == 1 ) es_build();
    }
    void add_edge(int u, int v, int idx, int xdi){
        start[inner_edge_id] = u;
        es[inner_edge_id++] = {v, idx, xdi};
        start[inner_edge_id] = v;
        es[inner_edge_id++] = {u, xdi, idx};
        if( inner_edge_id == 2*n-2 ) es_build();
    }
    vector<V> build(int root_ = 0){
        root = root_;
        vector<V> subdp(n);
        subdp[0] = put_vertex(e(),0);
        
        vector<int> geta(n+1,0);
        for (int i = 0; i < n; i++) geta[i+1] = start[i+1] - start[i] - 1;
        geta[root+1]++;
        for (int i = 0; i < n; i++) geta[i+1] += geta[i];
        auto dfs = [&](auto self, int v, int f) -> void {
            E val = e();
            for (int i=start[v]; i<start[v+1]; i++){
                if( es[i].to == f ) swap(es[start[v+1]-1], es[i]);
                if( es[i].to == f ) continue;
                self(self, es[i].to, v);
                E nval = put_edge(subdp[es[i].to], es[i].idx);
                outs[geta[v]++] = nval;
                val = merge(val,nval);
            }
            subdp[v] = put_vertex(val, v);
        };
        dfs(dfs,root,-1);
        return subdp;
    }
    vector<V> reroot(){
        vector<E> reverse_edge(n);
        reverse_edge[root] = e();
        vector<V> answers(n);
        auto dfs = [&](auto self, int v) -> void {
            int le = outs_start(v);
            int ri = outs_start(v+1);
            int siz = ri - le;
            vector<E> rui(siz+1);
            rui[siz] = e();
            for (int i = siz-1; i >= 0; i--){
                rui[i] = merge(outs[le+i],rui[i+1]);
            }
            answers[v] = put_vertex(merge(rui[0],reverse_edge[v]),v);
            E lui = e();
            for (int i = 0; i < siz; i++){
                V rdp = put_vertex(merge(merge(lui,rui[i+1]),reverse_edge[v]),v);
                reverse_edge[es[start[v]+i].to] = put_edge(rdp,es[start[v]+i].xdi);
                lui = merge(lui,outs[le+i]);
                self(self, es[start[v]+i].to);
            }
        };
        dfs(dfs, root);
        return answers;
    }
    private:
    int n, root, inner_edge_id;
    vector<E> outs;
    vector<edge> es;
    vector<int> start;
    int outs_start(int v){
        int res = start[v] - v;
        if (root < v) res++;
        return res;
    }
    void es_build(){
        vector<edge> nes(2*n-2);
        vector<int> nstart(n+2,0);
        for (int i=0; i < 2*n-2; i++) nstart[start[i]+2]++;
        for (int i=0; i < n; i++) nstart[i+1] += nstart[i];
        for (int i=0; i < 2*n-2; i++) nes[nstart[start[i]+1]++] = es[i];
        swap(es,nes);
        swap(start,nstart);
    }
};

// RerootingDP 更新式
// f(u,v) : u = par(v) とした時の dp[v] ( 自分が子となる辺とノードを対応 )
// f(u,v) = put_vertex( ⨁_{c ∈ child(u,v)} put_edge(f(v,c),idx(v,c)), u ) 
// ※ 子の答えに辺 (v,c) を付加 ⇒ 自身の v を付加してる感じ

using E = mint;
using V = mint;
E merge(E a, E b) { // merge : ⨁  ← こいつ
    return a*b;
}
E e() { // 単位元 (merge が E,E の為 E)
    return mint(1);
}
E put_edge(V v, int i) { // 辺 i の追加演算
    // ※ (v1+1)*(v2+1) = v1*v2 + 1*v1 + 1*v2 + 1*1
    //    v1*v2 : 両黒, 1*v1 : 左黒右白, v2*1 : 左白右黒, 1*1 : 両白
    return v+1;
}
V put_vertex(E e, int v) { // 頂点 v の追加演算 
    return e;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, m; cin >> n >> m;
    mint::set_mod(m);
    RerootingDP<E,V,merge,e,put_edge,put_vertex> reroot(n);
    rep(i,n-1) {
        ll x, y; cin >> x >> y; x--; y--;
        reroot.add_edge(x, y, i, i);
    }
    reroot.build();
    vector<V> ans = reroot.reroot();
    rep(i,n) cout << ans[i].val() << endl;
    
    return 0;
}
