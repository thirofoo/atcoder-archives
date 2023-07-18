/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/43716300
 * Submitted at: 2023-07-18 15:19:44
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_d
 * Result: AC
 * Execution Time: 16 ms
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
    mf_graph<ll> mf(n*m+2);
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
                    mf.add_edge( idx(i,j), idx(nx,ny), 1 );
                }
            }
            // start , goal を結ぶ辺追加
            if( (i+j)%2 == 1 ) mf.add_edge( start, idx(i,j), 1);
            else mf.add_edge( idx(i,j), goal, 1 );
        }
    }
    ll ans = mf.flow( start, goal);

    // タイル敷 part
    const auto &Edges = mf.edges();
    rep(i,Edges.size()){
        // 最大流が流れていない || start, goal への辺でる || 逆辺 → 考慮しない
        if( Edges[i].flow <= 0 || Edges[i].to == goal || Edges[i].from == start ) continue;
        
        ll x1 = Edges[i].from/m, y1 = Edges[i].from%m;
        ll x2 = Edges[i].to/m, y2 = Edges[i].to%m;

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

    cout << ans << endl;
    rep(i,n) cout << s[i] << endl;
    
    return 0;
}