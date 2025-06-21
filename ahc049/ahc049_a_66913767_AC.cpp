/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc049/submissions/66913767
 * Submitted at: 2025-06-21 15:33:29
 * Problem URL: https://atcoder.jp/contests/ahc049/tasks/ahc049_a
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ---- 定数 ---- */
constexpr int H        = 5;                 // スタック高さ上限
constexpr int DX[4]    = {-1, 1, 0, 0};
constexpr int DY[4]    = { 0, 0,-1, 1};
constexpr char DC[4]   = {'U','D','L','R'};

/* ------------------------------------------------------------------ */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ---- 入力 ---- */
    int N; if(!(cin>>N)) return 0;
    vector<vector<int>>  W(N, vector<int>(N));
    vector<vector<ll >>  D(N, vector<ll >(N));
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin>>W[i][j];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin>>D[i][j];

    /* ---- 未搬出フラグ ---- */
    vector<vector<char>> alive(N, vector<char>(N,1));
    alive[0][0]=0;

    /* ---- 優先度付きオーダー作成 ---- */
    struct P{int i,j; long double score;};
    vector<P> order; order.reserve(N*N-1);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) if(i||j){
        long double dist2 = 1.0L*i*i + 1.0L*j*j;
        long double s     = dist2;
        order.push_back({i,j,s});
    }
    sort(order.begin(), order.end(),
         [](const P& a, const P& b){ return a.score > b.score; });

    /* ---- 出力コマンド格納 ---- */
    vector<char> ops; ops.reserve(2*N*N*N);

    auto mv = [&](int& x,int& y,int dir){
        x += DX[dir]; y += DY[dir]; ops.push_back(DC[dir]); };

    /* ---- メインループ ---- */
    int curX = 0, curY = 0;
    for(const auto& start : order){
        int si=start.i, sj=start.j;
        if(!alive[si][sj]) continue;

        /* (0,0) → (si,sj) */
        while(curX < si) mv(curX,curY,1);
        while(curY < sj) mv(curX,curY,3);
        while(curX > si) mv(curX,curY,0);
        while(curY > sj) mv(curX,curY,2);

        /* 出発箱 pick */
        ops.push_back('1');
        alive[si][sj]=0;

        ll  margin = D[si][sj] / (si+sj);    // cap  (weightAbove = 0)
        int dist   = si+sj;                  // 残り歩数
        int height = 1;

        /* 帰路で積めるだけ積む (Up→Left のみ移動) */
        int x=si, y=sj;
        while(x>0 || y>0){
            if(x>0){ mv(x,y,0); --dist; }
            else   { mv(x,y,2); --dist; }

            if(!alive[x][y] || height==H) continue;

            int w  = W[x][y];
            ll cap = (dist>0) ? D[x][y] / dist : 0;   // dist=0 では拾わない

            if(margin - w < 0)       continue;        // 既存箱が耐えない
            ll newMargin = min<ll>(cap, margin - w);
            if(newMargin < 0)        continue;        // 新箱自身が耐えない

            /* 安全に積載できる */
            ops.push_back('1');
            alive[x][y]=0;
            margin = newMargin;
            ++height;
        }

        /* (0,0) へ戻る */
        while(x>0){ mv(x,y,0); }
        while(y>0){ mv(x,y,2); }
        curX = curY = 0;                 // 毎回入口で荷下ろし (自動)
    }

    /* ---- 出力 ---- */
    for(char c: ops) cout<<c << '\n';
    return 0;
}
