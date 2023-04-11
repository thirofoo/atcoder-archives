/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc294/submissions/40544989
 * Submitted at: 2023-04-11 23:21:19
 * Problem URL: https://atcoder.jp/contests/abc294/tasks/abc294_g
 * Result: WA
 * Execution Time: 300 ms
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

// ↓~~~~~~~~~~ Heavy-Light-Deconposition ~~~~~~~~~~↓ //
// モノイド設定
using S = long long;
S Sum_e(){return 0;}
S Sum_op(S a,S b){return a+b;}

class HLD{
    public:
        HLD() : n(0){}
        explicit HLD(const int _n){
            n = _n;
            part_size.assign(n,1);
            shallow.assign(n,0);
            parent.assign(n,0);
            Graph.assign(n,{});
            depth.assign(n,0);
            hld.assign(n,0);
            sg = segtree<S,Sum_op,Sum_e>(n);
        }

        inline void addEdge(int u, int v){
            Graph[u].emplace_back(v);
            Graph[v].emplace_back(u);
        }

        void prepare(){
            dfs(0,-1);            // parent & depth 算出
            HLDecomposition(0,0); // HL分解
        }

        long long query(int u, int v){
            if(u == v)return 0;
            long long res = 0;
            while(shallow[u] != shallow[v]){
                if(depth[shallow[u]] > depth[shallow[v]])swap(u,v);
                // 深いHLD要素を遡る
                res += sg.prod(hld[shallow[v]], hld[v]+1);
                v = parent[shallow[v]];
            }
            if(depth[u] > depth[v])swap(u,v);
            res += sg.prod(hld[u], hld[v]+1);
            return res;
        }

        inline void set(int idx, long long x){
	    	sg.set(hld[idx],x);
	    }
        inline void set(int u, int v, long long x){
            if(depth[u] > depth[v])swap(u,v);
	    	sg.set(hld[v],x);
	    }

    private:
        int n, child;
        // hld     : 元の頂点 → HLD要素
        // r_hld   : HLD要素 → 元の頂点
        // shallow : HLD要素の最も浅い頂点
        vector<int> part_size, r_hld, shallow, hld, depth, parent;
        vector<vector<int>> Graph;
        segtree<S,Sum_op,Sum_e> sg;

        inline void HLDecomposition(int v, const int a){
            hld[v] = r_hld.size();
            r_hld.emplace_back(v);
            shallow[v] = a;

            if( (Graph[v].size() == 1 && Graph[v][0] == parent[v]) || Graph[v].size() == 0 )return;

            int max_size = -1, max_idx = 0;
            for(int i=0;i<Graph[v].size();i++){
                child = Graph[v][i];
                if(child == parent[v])continue;
                if(max_size < part_size[child]){
                    max_size = part_size[child];
                    max_idx = i;
                }
            }
            HLDecomposition(Graph[v][max_idx],a);
            for(int i=0; i<Graph[v].size(); i++){
                child = Graph[v][i];
                if(child == parent[v])continue;
                if(i != max_idx){
                    HLDecomposition(child,child);
                }
            }
        }

        inline void dfs(const int &now, const int pre){
            if(pre == -1)depth[now] = 0;
            else depth[now] = depth[pre]+1;
            parent[now] = pre;
            for(auto to:Graph[now]){
                if(to == pre)continue;
                dfs(to,now);
                part_size[now] += part_size[to];
            }
        }
};
// ↑~~~~~~~~~~ Heavy-Light-Deconposition ~~~~~~~~~~↑ //

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<T> edge;
    HLD hld(n);
    rep(i,n-1){
        ll u,v,w; input(u,v,w);
        u--; v--;
        edge.push_back(T(u,v,w));
        hld.addEdge(u,v);
    }
    hld.prepare();
    rep(i,n-1){
        auto &&[u,v,w] = edge[i];
        hld.set(u,v,w);
    }

    ll q; input(q);
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll i,w; input(i,w);
            i--;
            auto &&[u,v,_] = edge[i];
            hld.set(u,v,w);
        }
        else{
            ll u,v; input(u,v);
            u--; v--;
            print(hld.query(u,v));
        }
    }
    
    return 0;
}