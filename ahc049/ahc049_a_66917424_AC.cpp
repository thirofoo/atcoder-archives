/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc049/submissions/66917424
 * Submitted at: 2025-06-21 17:13:56
 * Problem URL: https://atcoder.jp/contests/ahc049/tasks/ahc049_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ---------- 定数 ---------- */
constexpr int H = 10;               // スタック高さ上限
const int DX[2] = {-1, 0};          // Up , Left
const int DY[2] = { 0,-1};
const char MV[2]= {'U','L'};

/* ---------- スタック (margin) ---------- */
struct Stack {
    vector<pair<int,ll>> box;       // {w , remDur}
    ll margin; int dist;            // 残余容量 / 出口まで残歩数
    bool step(){                    // 1 歩移動
        ll above=0;
        for(int k=box.size()-1;k>=0;--k){
            box[k].second -= above;
            if(box[k].second<=0) return false;
            above += box[k].first;
        }
        --dist; return true;
    }
    bool can(int w,ll d) const{     // 積める？
        if(w>margin) return false;
        ll cap=d/dist;
        return min<ll>(margin-w,cap)>=0;
    }
    void push(int w,ll d){          // 実際に push
        ll cap=d/dist;
        margin=min<ll>(margin-w,cap);
        box.push_back({w,d});
    }
};

/* ---------- main ---------- */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; if(!(cin>>N)) return 0;
    vector<vector<int>>  W(N, vector<int>(N));
    vector<vector<ll >>  D(N, vector<ll >(N));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>W[i][j];
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>D[i][j];

    vector<vector<char>> alive(N, vector<char>(N,1)); alive[0][0]=0;

    auto is_edge=[&](int i,int j){ return i==0||j==0||i==N-1||j==N-1; };

    vector<char> ops; ops.reserve(2*N*N*N);
    auto mv=[&](int& x,int& y,char c){
        if(c=='U')--x; else if(c=='L')--y;
        else if(c=='D')++x; else if(c=='R')++y;
        ops.push_back(c);
    };

    int curX=0, curY=0;

    while(true){
        /* ---------- frontier 探索 ---------- */
        int si=-1,sj=-1; ll bestD=-1;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++){
            if(!alive[i][j]) continue;
            bool frontier=true;
            for(int x=i;x<N && frontier;x++)
                for(int y=j;y<N;y++)
                    if(alive[x][y] && (x>i||y>j)){ frontier=false; break; }
            if(frontier && D[i][j]>bestD){
                bestD=D[i][j]; si=i; sj=j;
            }
        }
        if(si==-1) break;                  // 全搬出済み

        /* ---------- (0,0)→(si,sj) Down→Right ---------- */
        while(curX<si) mv(curX,curY,'D');
        while(curY<sj) mv(curX,curY,'R');

        /* ---------- pick 出発箱 ---------- */
        Stack st; st.dist=si+sj;
        st.margin = D[si][sj]/st.dist;
        st.box.push_back({W[si][sj], D[si][sj]});
        ops.push_back('1'); alive[si][sj]=0;

        int x=si, y=sj;

        /* ---------- 帰路貪欲 ---------- */
        while(x>0 || y>0){
            int best=-1;         // 0:Up 1:Left
            bool bestEdge=false; int bestW=-1;

            for(int dir=0;dir<2;++dir){
                if(dir==0 && x==0) continue;
                if(dir==1 && y==0) continue;
                int nx=x+DX[dir], ny=y+DY[dir];

                bool edge=is_edge(nx,ny);
                int  w   = (alive[nx][ny] ? W[nx][ny] : -1);

                bool ok = alive[nx][ny] && st.box.size()<H &&
                          st.can(W[nx][ny], D[nx][ny]);

                if(ok){
                    if(best==-1 || edge&&!bestEdge || (edge==bestEdge&&w>bestW)){
                        best=dir; bestEdge=edge; bestW=w;
                    }
                }else if(best==-1){ best=dir; }
            }
            if(best==-1) best = (x>0)?0:1;

            /* 移動 */
            mv(x,y, MV[best]);
            if(!st.step()) return 0;

            /* 取れるなら取る */
            if(alive[x][y] && st.box.size()<H &&
               st.can(W[x][y], D[x][y]))
            {
                st.push(W[x][y], D[x][y]);
                ops.push_back('1');
                alive[x][y]=0;
            }
        }
        curX=curY=0;                           // 荷下ろし
    }

    /* ---------- 出力 ---------- */
    for(char c:ops) cout<<c<<'\n';
    return 0;
}
