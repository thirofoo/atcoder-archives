/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67392040
 * Submitted at: 2025-07-06 22:39:26
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1967 ms
 */

#include <bits/stdc++.h>
using namespace std;

/* ──────────────────────────────────────────────────────────
   1D 盤面管理 + スパース遷移
   ▸ pool アニーリング
   ▸ Beam 幅 16 × 深さ 2 look-ahead
   ────────────────────────────────────────────────────────── */
constexpr int N  = 40;
constexpr int SZ = N * N;
constexpr int BEAM_W = 16;

/* ---------- 乱数 ---------- */
inline unsigned int rnd() {
  static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
  unsigned int t=x^(x<<11); x=y; y=z; z=w;
  return w=(w^(w>>19))^(t^(t>>8));
}

/* ---------- タイマ ---------- */
struct Timer { chrono::steady_clock::time_point st;
  void start(){ st = chrono::steady_clock::now(); }
  double ms() const {
    return chrono::duration_cast<chrono::milliseconds>(
             chrono::steady_clock::now()-st).count();}};
Timer g_t;

/* ---------- Runner ---------- */
class Runner{
public:
  Runner(const vector<string>& S_,const vector<pair<int,int>>& emp_)
    : S(S_), empty(emp_) {}

  pair<double,vector<pair<int,int>>> run(int base_pool);

private:
  const vector<string>& S;
  const vector<pair<int,int>>& empty;

  array<bool,SZ> rock{};
  array<int,SZ>  up_st,down_st,left_st,right_st;
  array<double,SZ> P[2];
  vector<int> active_cur,active_nxt;
  array<int,SZ> mark{}; int stamp=1;

  vector<int> alive; vector<int> pos_in_alive;

  /* util */
  static inline int id(int r,int c){return r*N+c;}
  static inline int row(int id){return id/N;}
  static inline int col(int id){return id%N;}

  void buildStops();
  void updateStops(int r,int c);
  void sparseDiffuse(int cur,int nxt,vector<int>&src,vector<int>&dst);
};

/* ---------- Solver ---------- */
struct Solver{
  int M; vector<string> board; vector<pair<int,int>> empty;
  Solver(){
    int dummy;cin>>dummy>>M; board.resize(N);
    for(int i=0;i<N;++i){cin>>board[i];
      for(int j=0;j<N;++j) if(board[i][j]=='.') empty.emplace_back(i,j);}
  }
  void solve(){
    g_t.start(); Runner runner(board,empty);
    double bestE=-1; vector<pair<int,int>> bestP; long long iter=0;
    while(g_t.ms()<1950){
      auto [E,P]=runner.run(/*basePool*/100);
      if(E>bestE){bestE=E; bestP=move(P);} ++iter;}
    cerr<<"Iter "<<iter<<'\n';
    for(auto [r,c]:bestP) cout<<r<<' '<<c<<'\n';
  }
};

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
  cout.setf(ios::fixed);cout.precision(12); Solver().solve();}

/* ==================================================================== */
/* Runner impl                                                          */
/* ==================================================================== */
pair<double,vector<pair<int,int>>> Runner::run(int base_pool){
  rock.fill(false); P[0].fill(0); P[1].fill(0);
  active_cur.clear(); active_nxt.clear();

  for(int r=0;r<N;++r) for(int c=0;c<N;++c)
    if(S[r][c]=='#') rock[id(r,c)]=true;

  if(!empty.empty()){
    double p0=1.0/empty.size();
    for(auto [r,c]:empty){int d=id(r,c);P[0][d]=p0; active_cur.push_back(d);}
  }
  buildStops();

  alive.resize(empty.size());
  pos_in_alive.assign(empty.size(),0);
  iota(alive.begin(),alive.end(),0);

  vector<pair<int,int>> placed; placed.reserve(empty.size());
  double expect=0, prAlive=1; int cur=0,nxt=1;

  for(int step=0;step<(int)empty.size();++step){
    /* pool size アニーリング */
    int remainStep=empty.size()-step;
    int pool = 1 + (remainStep*(base_pool-1))/empty.size();

    /* 確率拡散 */
    sparseDiffuse(cur,nxt,active_cur,active_nxt);
    swap(cur,nxt); swap(active_cur,active_nxt);

    /* 最小確率候補 */
    double minp=2.0; vector<int> cand; cand.reserve(32);
    for(int ei:alive){
      auto [r,c]=empty[ei]; double p=P[cur][id(r,c)];
      if(p<minp-1e-12){minp=p; cand.clear(); cand.push_back(ei);}
      else if(fabs(p-minp)<1e-12) cand.push_back(ei);
    }

    /* ペナルティ + 簡易 look-ahead */
    struct Node{double score; int ei;};
    vector<Node> list; list.reserve(cand.size());
    for(int ei:cand){
      auto [r,c]=empty[ei]; int d=id(r,c);
      int upL=r-row(up_st[d]), dnL=row(down_st[d])-r;
      int lfL=c-col(left_st[d]),rtL=col(right_st[d])-c;
      double pen=1.*upL*dnL+1.*lfL*rtL;

      /* very light heuristic spread: active size after 1 step */
      double destroyed = P[cur][d];
      double remainProb = 1.0 - destroyed;
      double spread = active_cur.size();   // fallback
      if(remainProb>1e-12){
        spread *= remainProb;              // fewer & concentrated is good
      }else pen -= 1000;                   // instant death
      list.push_back({pen + 0.01*spread, ei});
    }
    int K=min<int>(pool,list.size());
    nth_element(list.begin(),list.begin()+K,list.end(),
                [](auto&a,auto&b){return a.score<b.score;});
    int choose=list[rnd()%K].ei;

    /* 岩設置 */
    auto [br,bc]=empty[choose]; int idPl=id(br,bc);
    placed.push_back({br,bc});

    /* alive 削除 */
    int pos=find(alive.begin(),alive.end(),choose)-alive.begin();
    alive[pos]=alive.back(); alive.pop_back();

    /* 期待値更新 */
    double destr=P[cur][idPl]; P[cur][idPl]=0;
    double remainProb=1-destr;
    if(remainProb>1e-12){double inv=1/remainProb;
      for(int idv:active_cur) P[cur][idv]*=inv;}
    prAlive*=remainProb; expect+=prAlive;

    /* board update */
    rock[idPl]=true; updateStops(br,bc);
  }
  return {expect,move(placed)};
}

/* -------- sparse diffuse ---------- */
void Runner::sparseDiffuse(int cur,int nxt,vector<int>&src,vector<int>&dst){
  dst.clear(); ++stamp; for(double&v:P[nxt])v=0;
  auto push=[&](int to,double v){
    if(mark[to]!=stamp){mark[to]=stamp;dst.push_back(to);} P[nxt][to]+=v;};
  for(int idv:src){
    double p=P[cur][idv]; if(p<=1e-12)continue;
    double q=0.25*p; push(up_st[idv],q); push(down_st[idv],q);
    push(left_st[idv],q); push(right_st[idv],q); P[cur][idv]=0;
  }
}

/* -------- stop table build ---------- */
void Runner::buildStops(){
  for(int r=0;r<N;r++){int last=-1;
    for(int c=0;c<N;c++){left_st[id(r,c)]=id(r,last+1);if(rock[id(r,c)])last=c;}
    last=N;
    for(int c=N-1;c>=0;c--){right_st[id(r,c)]=id(r,last-1);if(rock[id(r,c)])last=c;}}
  for(int c=0;c<N;c++){int last=-1;
    for(int r=0;r<N;r++){up_st[id(r,c)]=id(last+1,c);if(rock[id(r,c)])last=r;}
    last=N;
    for(int r=N-1;r>=0;r--){down_st[id(r,c)]=id(last-1,c);if(rock[id(r,c)])last=r;}}
}
/* ---- diff update ---- */
void Runner::updateStops(int r,int c){
  for(int i=r-1;i>=0&&!rock[id(i,c)];--i)down_st[id(i,c)]=id(r-1,c);
  for(int i=r+1;i<N&&!rock[id(i,c)];++i) up_st[id(i,c)]=id(r+1,c);
  for(int j=c-1;j>=0&&!rock[id(r,j)];--j) right_st[id(r,j)]=id(r,c-1);
  for(int j=c+1;j<N&&!rock[id(r,j)];++j) left_st[id(r,j)]=id(r,c+1);
}
