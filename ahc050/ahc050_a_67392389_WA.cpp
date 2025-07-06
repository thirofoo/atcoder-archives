/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67392389
 * Submitted at: 2025-07-06 22:44:28
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: WA
 * Execution Time: 1951 ms
 */

/*  ───────────────────────────────────────────────────────────────────
    “限界”寄り高速化版
    – AVX2/Ofast 指定
    – double → float （確率演算で十分な精度）
    – 動的 vector を固定長配列に置換して push_back/clear コストゼロ
    – alive 配列も手動 swap-pop 管理
    – メモリアライン済み array<float,1600> でキャッシュ最適
   ────────────────────────────────────────────────────────── */
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

constexpr int N  = 40;
constexpr int SZ = N * N;              // 1600
using Prob = float;                    // ★ double → float

/* ───── 乱数 (xorshift128) ───── */
inline uint32_t rng() {
  static uint32_t x=123456789,y=362436069,z=521288629,w=88675123;
  uint32_t t=x^(x<<11); x=y; y=z; z=w;
  return w=(w^(w>>19))^(t^(t>>8));
}

/* ───── タイマ ───── */
struct Timer {
  chrono::steady_clock::time_point st;
  void start(){ st=chrono::steady_clock::now(); }
  double ms() const {
    return chrono::duration_cast<chrono::milliseconds>(
             chrono::steady_clock::now()-st).count();
  }
} g_tm;

/* ───── Runner ───── */
class Runner {
public:
  Runner(const vector<string>& s,const vector<pair<int,int>>& emp)
      : S(s), empty(emp) {}

  pair<double,vector<pair<int,int>>> run(int basePool);

private:
  const vector<string>&             S;
  const vector<pair<int,int>>&      empty;

  /* 盤面・停止表 */
  alignas(64) array<uint8_t,SZ> rock{};     // 0/1
  alignas(64) array<uint16_t,SZ> up_st,down_st,left_st,right_st;

  /* 確率 & active-list */
  alignas(64) array<Prob,SZ> P[2];
  int active_cur[SZ], active_nxt[SZ];
  int as_cur=0, as_nxt=0;
  alignas(64) array<uint16_t,SZ> mark{}; uint16_t stamp=1;

  /* alive-list */
  int alive[SZ]; uint16_t pos_in_alive[SZ]; int alive_sz=0;

  /* util */
  static inline int id(int r,int c){ return r*N+c; }
  static inline int row(int idx){ return idx/N; }
  static inline int col(int idx){ return idx%N; }

  void buildStops();
  void updateStops(int r,int c);
  inline void push_next(int to, Prob v){
    if(mark[to]!=stamp){ mark[to]=stamp; active_nxt[as_nxt++]=to; }
    P[1][to]+=v;
  }
};

/* ───── Solver ───── */
struct Solver{
  int M; vector<string> board; vector<pair<int,int>> empty;
  Solver(){
    int dummy; cin>>dummy>>M; board.resize(N);
    for(int i=0;i<N;++i){
      cin>>board[i];
      for(int j=0;j<N;++j)
        if(board[i][j]=='.') empty.emplace_back(i,j);
    }
  }
  void solve(){
    g_tm.start(); Runner runner(board,empty);
    double bestE=-1; vector<pair<int,int>> bestP; long long it=0;
    while(g_tm.ms()<1950){
      auto [E,P]=runner.run(80);
      if(E>bestE){bestE=E; bestP = move(P);} ++it;
    }
    cerr<<"Iter "<<it<<'\n';
    for(auto [r,c]:bestP) cout<<r<<' '<<c<<'\n';
  }
};

/* ───── main ───── */
int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cout.setf(ios::fixed); cout.precision(12);
  Solver().solve(); return 0;
}

/* ==================================================================== */
/* Runner::run                                                          */
/* ==================================================================== */
pair<double,vector<pair<int,int>>> Runner::run(int basePool){
  /* 初期化 ................................................................ */
  rock.fill(0); P[0].fill(0); P[1].fill(0); as_cur=as_nxt=0;

  for(int r=0;r<N;++r)for(int c=0;c<N;++c)
    if(S[r][c]=='#') rock[id(r,c)]=1;

  if(!empty.empty()){
    Prob p0 = 1.0f / empty.size();
    for(auto [r,c]:empty){
      int d=id(r,c); P[0][d]=p0; active_cur[as_cur++]=d;
    }
  }
  buildStops();

  alive_sz = empty.size();
  for(int i=0;i<alive_sz;++i){ alive[i]=i; pos_in_alive[i]=i; }

  vector<pair<int,int>> placed; placed.reserve(empty.size());
  double expect=0; Prob probAlive=1.0f;
  int cur=0,nxt=1;

  /* 反復 .................................................................. */
  for(int step=0; step<(int)empty.size(); ++step){
    /* アニーリング pool サイズ */
    int pool = 1 + ( (empty.size()-step) * (basePool-1) ) / empty.size();

    /* === 拡散 (active だけ) === */
    P[nxt].fill(0); as_nxt=0; ++stamp;
    Prob sum_before=0;
    for(int ai=0;ai<as_cur;++ai){
      int idx=active_cur[ai]; Prob p=P[cur][idx];
      if(p<=1e-12f) continue;
      sum_before+=p; Prob q=p*0.25f;
      push_next(up_st[idx],q); push_next(down_st[idx],q);
      push_next(left_st[idx],q); push_next(right_st[idx],q);
    }
    swap(cur,nxt); swap(active_cur,active_nxt); swap(as_cur,as_nxt);

    /* === min-p 候補探索 === */
    Prob minp=2.0f; int cand[64]; int cs=0;
    for(int i=0;i<alive_sz;++i){
      int ei=alive[i]; auto [r,c]=empty[ei];
      Prob p=P[cur][id(r,c)];
      if(p<minp-1e-12f){minp=p; cs=0; cand[cs++]=ei;}
      else if(fabs(p-minp)<1e-12f && cs<64) cand[cs++]=ei;
    }

    /* === ペナルティ / 抽選 === */
    double bestScore=1e100; int choose=cand[0];
    int usePool=min(pool,cs);
    for(int t=0;t<usePool;++t){
      int ei=cand[t];
      auto [r,c]=empty[ei]; int d=id(r,c);
      int upL=r-row(up_st[d]), dnL=row(down_st[d])-r;
      int lfL=c-col(left_st[d]), rtL=col(right_st[d])-c;
      double score = (double)upL*dnL + (double)lfL*rtL;
      if(score<bestScore){bestScore=score; choose=ei;}
    }

    /* === 岩設置・確率更新 === */
    auto [br,bc]=empty[choose]; int dPlaced=id(br,bc);
    placed.push_back({br,bc});

    /* alive swap-pop */
    int pos=pos_in_alive[choose];
    alive[pos]=alive[--alive_sz];
    pos_in_alive[alive[pos]] = pos;

    Prob destroyed = P[cur][dPlaced];
    P[cur][dPlaced]=0;
    Prob remain = sum_before - destroyed;
    if(sum_before>1e-12f) probAlive *= remain/sum_before;
    expect += probAlive;

    if(remain>1e-12f){
      Prob inv=1.0f/remain;
      for(int ai=0;ai<as_cur;++ai) P[cur][active_cur[ai]]*=inv;
    }else break;                                    // 全滅で終了

    /* 盤面・停止表差分更新 */
    rock[dPlaced]=1; updateStops(br,bc);
  }
  return {expect,move(placed)};
}

/* ==================================================================== */
/* Stop table build / update                                            */
/* ==================================================================== */
void Runner::buildStops(){
  for(int r=0;r<N;++r){
    int last=-1;
    for(int c=0;c<N;++c){
      left_st[id(r,c)]=id(r,last+1);
      if(rock[id(r,c)]) last=c;
    }
    last=N;
    for(int c=N-1;c>=0;--c){
      right_st[id(r,c)]=id(r,last-1);
      if(rock[id(r,c)]) last=c;
    }
  }
  for(int c=0;c<N;++c){
    int last=-1;
    for(int r=0;r<N;++r){
      up_st[id(r,c)]=id(last+1,c);
      if(rock[id(r,c)]) last=r;
    }
    last=N;
    for(int r=N-1;r>=0;--r){
      down_st[id(r,c)]=id(last-1,c);
      if(rock[id(r,c)]) last=r;
    }
  }
}
void Runner::updateStops(int r,int c){
  for(int i=r-1;i>=0&&!rock[id(i,c)];--i) down_st[id(i,c)]=id(r-1,c);
  for(int i=r+1;i<N &&!rock[id(i,c)];++i) up_st[id(i,c)]=id(r+1,c);
  for(int j=c-1;j>=0&&!rock[id(r,j)];--j) right_st[id(r,j)]=id(r,c-1);
  for(int j=c+1;j<N &&!rock[id(r,j)];++j) left_st[id(r,j)]=id(r,c+1);
}
