/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/43712690
 * Submitted at: 2023-07-18 12:17:45
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_d
 * Result: AC
 * Execution Time: 197 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct Ford_Fulkerson{
    struct Edge {
        int to;
        long long weight;
        int idx;
    };
    vector<vector<Edge>> Graph;

    Ford_Fulkerson(vector<vector<pair<int, long long>>> &_Graph){
        // Graph生成 ( 残りの流量の順方向辺 , 流量を削る逆方向辺 を追加 )
        Graph.resize(_Graph.size(),vector<Edge>{});
        for(int i = 0; i < _Graph.size(); i++){
            for(int j = 0; j < _Graph[i].size(); j++){
                // 順方向の辺の idx には、逆方向の辺の index
                // 逆方向の辺の idx には、順方向の辺の index を入れることで逆引き可能にする
                auto [to, weight] = _Graph[i][j];
                int size = (int)Graph[i].size();
                Graph[i].push_back( Edge{to, weight, (int)Graph[to].size()} );
                Graph[to].push_back( Edge{i, 0, size} );
            }
        }
    }
    
    inline long long maximum_flow(int s, int t){
        // dfsで流量の増加路を発見 → 増加路の流量から Graph を更新 → ... (繰り返し)
        long long ret = 0;
        while(true){
            vector<bool> visited(Graph.size(),false);
            vector<Edge> edges;
            dfs(s, t, edges, visited);

            // 増加路が存在しなければ終了
            if( edges.size() == 0 ) break;
            
            // 増加路の中でコスト最小の辺を探す
            ll mini = 1e16;
            for(int i = 0; i < edges.size(); i++) mini = min( mini, edges[i].weight );
            ret += mini;
            for(int i = 0; i < edges.size(); i++) {
                // 増加路更新
                Edge &t = Graph[edges[i].to][edges[i].idx];
                t.weight += mini; // 順方向辺更新
                Graph[t.to][t.idx].weight -= mini; // 逆方向辺更新
            }
        }
        return ret;
    }

    inline void dfs(int now, int t, vector<Edge> &edges, vector<bool> &visited){
        // 純粋なdfsを書いて経路を edges に確保
        visited[now] = true;
        if( now == t ) return;
        for(int i = 0; i < Graph[now].size(); i++){
            int to = Graph[now][i].to;
            long long weight = Graph[now][i].weight;

            // コスト正の辺だけを考慮
            if( visited[to] || weight <= 0 ) continue;

            edges.push_back( Graph[now][i] );
            dfs( to, t, edges, visited );
            if( edges.back().to == t ) return;
            edges.pop_back();
        }
    }
};

// 左上右下の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 最大流問題
    // 1. 1*2 を敷く → 市松模様の2部マッチング問題に帰着させる
    // 2. i+j の偶奇で2部マッチングにして最大流を流す
    // 3. 最大流を流した後の辺を見て、流れていたら s を更新

    ll n,m; cin >> n >> m;
    vector<vector<pair<int, long long>>> Graph(n*m + 2);
    vector<set<pair<int, long long>>> st(n*m + 2);
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    // start , goal を 超頂点みたいに管理
    int start = n*m, goal = n*m + 1;

    // N*N を 1列に直した時の index を取得する関数
    auto idx = [&](ll i, ll j){ return i*m+j; };

    rep(i,n){
        rep(j,m){
            if( s[i][j] == '#' ) continue;
            
            // 今回は i+j 奇数 → i+j 偶数 への辺を張る
            if( (i+j)%2 == 1 ){
                rep(d,4){
                    ll nx = i + dx[d], ny = j + dy[d];
                    if( outField(nx,ny,n,m) || s[nx][ny] == '#' ) continue;

                    // 2部マッチング問題を最大流で解く → 流量は 1
                    Graph[idx(i,j)].push_back( pair<int, long long>(idx(nx,ny), 1) );
                    st[idx(i,j)].insert( pair<int, long long>(idx(nx,ny), 1) );
                }
            }

            // start , goal を結ぶ辺を追加
            if( (i+j)%2 == 1 ) Graph[start].push_back( pair<int, long long>(idx(i,j), 1) );
            else Graph[idx(i,j)].push_back( pair<int, long long>(goal, 1) );
        }
    }

    Ford_Fulkerson ff(Graph);
    ll ans = ff.maximum_flow(start, goal);

    // タイル敷 part
    auto& Edges = ff.Graph;
    rep(i,Edges.size()){
        // 最大流が流れていない || start, goal への辺でる || 逆辺 → 考慮しない ( かなり雑実装 )
        // if( i == start ) continue;
        for(auto &e : Edges[i]){
            // cout << i << " " << e.to << " : " << e.weight << endl;
            if( e.to == goal || e.weight == 1 || !st[i].count(pair<int, long long>(e.to, 1)) ) continue;
            ll x1 = i/m, y1 = i%m;
            ll x2 = e.to/m, y2 = e.to%m;
            // cout << x1 << "," << y1 << " : " << x2 << "," << y2 << endl;
            if( x1 == x2 ){
                if( y1 < y2 ) {
                    s[x1][y1] = '>';
                    s[x2][y2] = '<';
                }
                else{
                    s[x1][y1] = '<';
                    s[x2][y2] = '>';
                }
            }
            else{
                if( x1 < x2 ) {
                    s[x1][y1] = 'v';
                    s[x2][y2] = '^';
                }
                else{
                    s[x1][y1] = '^';
                    s[x2][y2] = 'v';
                }
            }
        }
    }

    cout << ans << endl;
    rep(i,n) cout << s[i] << endl;
    
    return 0;
}