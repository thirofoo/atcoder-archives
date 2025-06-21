/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc049/submissions/66913455
 * Submitted at: 2025-06-21 15:23:28
 * Problem URL: https://atcoder.jp/contests/ahc049/tasks/ahc049_a
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ---------- 定数 ---------- */
constexpr int H       = 5;        // スタック高さ上限
constexpr int DX[4]   = {-1,1,0,0};
constexpr int DY[4]   = {0,0,-1,1};
constexpr char DC[4]  = {'U','D','L','R'};

/* ---------- 箱 ---------- */
struct Box { int w; ll d; };

/* ---------- I/O ---------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; if(!(cin>>N)) return 0;
    vector<vector<int>>  W(N, vector<int>(N));
    vector<vector<ll >>  D(N, vector<ll >(N));
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin>>W[i][j];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin>>D[i][j];

    /* --------- まだ残っているか ---------- */
    vector<vector<char>> alive(N, vector<char>(N,1));
    alive[0][0]=0;

    /* --------- 重い→遠い 順に全マスを並べる ---------- */
    struct P{int i,j;};
    vector<P> order;
    order.reserve(N*N-1);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) if(i||j) order.push_back({i,j});
    sort(order.begin(), order.end(), [&](const P& a, const P& b){
        if(W[a.i][a.j] != W[b.i][b.j])
            return W[a.i][a.j] > W[b.i][b.j];          // 重い順
        return (a.i+a.j) > (b.i+b.j);                  // 同重量なら遠い順
    });

    /* --------- 出力コマンド格納 ---------- */
    vector<char> ops; ops.reserve(2*N*N*N);

    /* --------- 現在位置 ---------- */
    auto mv = [&](int& x,int& y,int dir){
        x += DX[dir]; y += DY[dir]; ops.push_back(DC[dir]); };

    /* --------- メインループ ---------- */
    int curX=0, curY=0;
    for(const auto& pTop : order){
        int si = pTop.i, sj = pTop.j;
        if(!alive[si][sj]) continue;          // 既に搬出済み

        /* --------- (0,0) → (si,sj) 移動 --------- */
        while(curX < si){ mv(curX,curY,1); }
        while(curY < sj){ mv(curX,curY,3); }
        while(curX > si){ mv(curX,curY,0); }  // （理論上無い）
        while(curY > sj){ mv(curX,curY,2); }

        /* --------- 出発箱 pick --------- */
        ops.push_back('1');
        alive[si][sj]=0;

        /* スタック情報 */
        ll totalW = W[si][sj];
        int lastW = W[si][sj];
        int height=1;
        int dist  = si+sj;
        ll margin = D[si][sj] / dist;         // cap − weightAbove(=0)

        /* --------- 帰路で可能な限り拾う --------- */
        int x=si, y=sj;
        while(x>0 || y>0){
            if(x>0){ mv(x,y,0); dist--; }     // Up
            else   { mv(x,y,2); dist--; }     // Left

            if(!alive[x][y] || height==H) continue;

            int w = W[x][y];
            if(w > lastW) continue;           // 重い→軽いの順守れず

            ll cap = D[x][y] / dist;          // この箱が耐えられる上載重量
            if(margin - w < 0) continue;      // 既存箱の余裕を潰す
            ll newMargin = min<ll>(cap, margin - w);
            if(newMargin < 0) continue;       // この箱自身壊れる

            /* --- 安全に積める --- */
            ops.push_back('1');
            alive[x][y]=0;
            totalW += w;
            height += 1;
            margin  = newMargin;
            lastW   = w;
        }

        /* --------- (0,0) へ到着 → 自動荷下ろし --------- */
        while(x>0){ mv(x,y,0); }
        while(y>0){ mv(x,y,2); }
        curX=curY=0;  /* もう (0,0) */
        /* 荷下ろし（スタックを忘れるだけで OK） */
    }

    /* --------- 行末に改行なしで良い (AtCoder 仕様) --------- */
    for(char c:ops) cout<<c<<'\n';
    return 0;
}
