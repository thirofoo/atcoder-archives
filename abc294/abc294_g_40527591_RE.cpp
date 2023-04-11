/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc294/submissions/40527591
 * Submitted at: 2023-04-11 12:13:50
 * Problem URL: https://atcoder.jp/contests/abc294/tasks/abc294_g
 * Result: RE
 * Execution Time: 782 ms
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


// ↓~~~~~~~~~~ EulerTour ~~~~~~~~~~↓ //

// モノイド設定
using S = long long;
S Sum_e(){return 0;}
S Sum_op(S a,S b){return a+b;}

using U = pair<int,int>;
U Min_e(){return pair(1e9,1e9);}
U Min_op(U a,U b){return min(a,b);}

class EulerTour{
    public:
        EulerTour() : n(0),turn(0){}
        explicit EulerTour(const int &_n){
            n = _n;
            turn = 0;
            Graph.assign(n,{});
            vw.assign(n,0);
            finish.assign(n,0);
            discover.assign(n,0);
            vcost1 = segtree<S, Sum_op, Sum_e>(2*n+1);
            ecost1 = segtree<S, Sum_op, Sum_e>(2*n+1);
            vcost2 = segtree<S, Sum_op, Sum_e>(2*n+1);
            ecost2 = segtree<S, Sum_op, Sum_e>(2*n+1);
            depth_visit = segtree<U, Min_op, Min_e>(2*n+1);
        }

        inline void addEdge(const int &u, const int &v, const S &w){
            Graph[u].emplace_back(pair(v,w));
            Graph[v].emplace_back(pair(u,w));
            ew[pair(u,v)] = w;
            ew[pair(v,u)] = w;
        }

        inline void addVcost(const int &i,const int &w){vw[i] = w;}

        inline void changeEcost(int u, int v, const int &nw){
            // ※ Graph自体の更新はしていない
            if(discover[u] > discover[v])swap(u,v);
            // 辺は2回しか通らない → O(logN)で更新可
            ecost1.set(discover[v],nw);
            ecost2.set(discover[v],nw);
            ecost2.set(finish[v],-nw);
        }

        inline S distV(const int &u, const int &v){return rootV(u) + rootV(v) - 2*rootV(lca(u,v)) + vw[lca(u,v)];}
        inline S distE(const int &u, const int &v){return rootE(u) + rootE(v) - 2*rootE(lca(u,v))               ;}
        inline S partV(const int &root){return vcost1.prod(discover[root]  ,finish[root]+1);}
        inline S partE(const int &root){return ecost1.prod(discover[root]+1,finish[root]+1);}

        inline int lca(int u, int v){
            if(u == v)return u;
            if(discover[u] > finish[v]+1)swap(u,v);
            return depth_visit.prod(discover[u],finish[v]+1).second;
        }

        inline void prepare(){dfs(0,-1,0,0);}

    private:
        int n, turn;
        vector<vector<pair<int,long long>>> Graph;
        segtree<S, Sum_op, Sum_e> vcost1, ecost1, vcost2, ecost2;
        segtree<U, Min_op, Min_e> depth_visit;
        vector<S> vw, discover, finish;
        map<pair<int,int>,long long> ew;

        // 0 → v の頂点・辺cost
        inline S rootV(const int &v){return vcost2.prod(0,discover[v]+1);}
        inline S rootE(const int &v){return ecost2.prod(1,discover[v]+1);}

        void dfs(const int &now, const int &pre,const int &w, const int &d){
            // 行きがけ処理
            discover[now] = turn;
            depth_visit.set(turn,U(d,now));
            vcost1.set(turn,vw[now]);
            vcost2.set(turn,vw[now]);
            ecost1.set(turn,w);
            ecost2.set(turn,w);
            turn++;
            for(auto &&[next,nw]:Graph[now]){
                if(next == pre)continue;
                dfs(next,now,nw,d+1);
            }
            // 帰りがけ処理
            finish[now] = turn;
            if(pre != -1)depth_visit.set(turn,U(d-1,pre));
            vcost1.set(turn,0);
            ecost1.set(turn,0);
            vcost2.set(turn,-vw[now]);
            ecost2.set(turn,-w);
            turn++;
        }
};

// ↑~~~~~~~~~~ EulerTour ~~~~~~~~~~↑ //


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<P> edge;
    EulerTour et(n);
    rep(i,n-1){
        ll u,v,w; input(u,v,w);
        u--; v--;
        et.addEdge(u,v,w);
        edge.emplace_back(P(u,v));
    }
    et.prepare();

    ll q; input(q);
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll i,w; input(i,w); i--;
            auto &&[u,v] = edge[i];
            et.changeEcost(u,v,w);
        }
        else{
            ll u,v; input(u,v);
            u--; v--;
            print(et.distE(u,v));
        }
    }
    
    return 0;
}