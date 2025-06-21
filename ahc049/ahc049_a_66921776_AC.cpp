/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc049/submissions/66921776
 * Submitted at: 2025-06-21 18:54:16
 * Problem URL: https://atcoder.jp/contests/ahc049/tasks/ahc049_a
 * Result: AC
 * Execution Time: 102 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int H = 10;        // スタック上限
const ll  NEG  = -1;         // 無効 DP 値
const int MAX_PATHS = 1000;  // ランダムに試す経路本数

/* ---------- frontier ---------- */
inline bool frontier(int i,int j,const vector<vector<char>>& a){
    int N=a.size();
    for(int x=i;x<N;x++)for(int y=j;y<N;y++)
        if(a[x][y] && (x>i||y>j)) return false;
    return true;
}

/* ---------- DP on one path ---------- */
struct Result{
    int bestH;
    vector<char> pick;
};
Result solvePath(const vector<pair<int,int>>& cells,
                 const vector<char>& moves,
                 int si,int sj,
                 const vector<vector<int>>& W,
                 const vector<vector<ll>>& D,
                 const vector<vector<char>>& alive)
{
    const int L = cells.size();
    static ll dp[101][H+1];
    static uint8_t prevH[101][H+1], take[101][H+1];
    for(int i=0;i<=L;i++)for(int h=0;h<=H;h++) dp[i][h]=NEG;

    dp[0][1] = D[si][sj];                 // 基台のみ

    for(int idx=0; idx<L; ++idx){
        auto [x,y] = cells[idx];
        bool has = alive[x][y];
        int  w   = W[x][y];
        ll   d   = D[x][y];
        int dist_rem = L - idx - 1;

        for(int h=1; h<=H; ++h) if(dp[idx][h]!=NEG){
            ll m = dp[idx][h];

            /* skip */
            if(m > dp[idx+1][h]){
                dp[idx+1][h] = m;
                prevH[idx+1][h] = h;
                take[idx+1][h]  = 0;
            }
            /* take */
            if(has && h<H && 1LL*w*(dist_rem+1) <= m){
                ll nm = min<ll>(m - 1LL*w*(dist_rem+1), d);
                if(nm>=0 && nm > dp[idx+1][h+1]){
                    dp[idx+1][h+1] = nm;
                    prevH[idx+1][h+1] = h;
                    take[idx+1][h+1]  = 1;
                }
            }
        }
    }

    int bestH = 0;
    for(int h=H; h>=1; --h) if(dp[L][h]!=NEG){ bestH=h; break; }

    vector<char> pick(L,0);
    if(bestH){
        int h = bestH, idx = L;
        while(idx>0){
            if(take[idx][h]) pick[idx-1]=1;
            h = prevH[idx][h];
            --idx;
        }
    }
    return {bestH, move(pick)};
}

/* ============================================================ */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ---- 入力 ---- */
    int N; if(!(cin>>N)) return 0;
    vector<vector<int>>  W(N,vector<int>(N));
    vector<vector<ll >>  D(N,vector<ll >(N));
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin>>W[i][j];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin>>D[i][j];

    vector<vector<char>> alive(N,vector<char>(N,1)); alive[0][0]=0;

    vector<char> ops; ops.reserve(2*N*N*H);
    auto mv=[&](int& x,int& y,char c){
        if(c=='U')--x; else if(c=='L')--y;
        else if(c=='D')++x; else ++y;     // 'R'
        ops.push_back(c);
    };

    std::mt19937 rng(20240621);           // 固定 seed（必要なら変更）

    int curX=0,curY=0;
    while(true){
        /* ---- 基台 pick ---- */
        int si=-1,sj=-1; ll bestD=-1;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)
            if(alive[i][j] && frontier(i,j,alive) && D[i][j]>bestD){
                bestD=D[i][j]; si=i; sj=j;
            }
        if(si==-1) break;

        /* 入口→基台 */
        while(curX<si) mv(curX,curY,'D');
        while(curY<sj) mv(curX,curY,'R');
        ops.push_back('1'); alive[si][sj]=0;

        /* ========= 最短経路をランダムに MAX_PATHS 本生成 ========= */
        vector<vector<char>> moveList;
        moveList.reserve(MAX_PATHS);

        // まず 2 本の基準 (Left→Up, Up→Left)
        {
            vector<char> seq(sj,'L'); seq.insert(seq.end(), si, 'U');
            moveList.push_back(seq);
            reverse(seq.begin(),seq.end());
            moveList.push_back(seq);
        }
        // ランダム 追加
        std::uniform_int_distribution<int> dist(0, si+sj-1);
        while((int)moveList.size() < MAX_PATHS){
            vector<char> seq(sj,'L');
            seq.insert(seq.end(), si, 'U');
            std::shuffle(seq.begin(),seq.end(), rng);
            moveList.push_back(move(seq));
        }

        /* ========= 各経路で DP ========= */
        int bestH = 0; size_t bestIdx = 0;
        vector<char> bestPick;
        for(size_t id=0; id<moveList.size(); ++id){
            /* cells を構築 */
            vector<pair<int,int>> cells;
            cells.reserve(moveList[id].size());
            int x=si, y=sj;
            for(char c: moveList[id]){
                if(c=='L') --y;
                else       --x;          // 'U'
                cells.emplace_back(x,y);
            }

            Result R = solvePath(cells, moveList[id],
                                 si,sj,W,D,alive);
            if(R.bestH > bestH){
                bestH   = R.bestH;
                bestIdx = id;
                bestPick.swap(R.pick);
            }
        }
        /* bestH==0 → 基台だけ */
        if(bestH==0){ curX=curY=0; continue; }

        /* ========= 採用経路を出力 ========= */
        const vector<char>& mvSeq = moveList[bestIdx];
        int x=si,y=sj;
        for(size_t i=0;i<mvSeq.size(); ++i){
            mv(x,y,mvSeq[i]);            // L or U
            if(bestPick[i]){
                ops.push_back('1');
                alive[x][y]=0;
            }
        }
        curX=curY=0;
    }

    /* ---- 出力 ---- */
    for(char c:ops) cout<<c<<'\n';
    return 0;
}
