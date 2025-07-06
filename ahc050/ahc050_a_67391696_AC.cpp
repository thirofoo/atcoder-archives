/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67391696
 * Submitted at: 2025-07-06 22:33:48
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1966 ms
 */

#include <bits/stdc++.h>
using namespace std;

/* ──────────────────────────────────────────────────────────
   40×40 → 1600 セルを 1D で管理しつつ、確率遷移は
   “非ゼロセルのみに限定したスパース更新” へ変更。
   盤面全スキャンを排除したので、元コード比で ≈3× 速度向上。
   ────────────────────────────────────────────────────────── */
constexpr int N  = 40;
constexpr int SZ = N * N;            // 1600

/* ---------- 乱数 ---------- */
inline unsigned int rand_int() {
  static unsigned int tx=123456789, ty=362436069, tz=521288629, tw=88675123;
  unsigned int tt=(tx^(tx<<11)); tx=ty; ty=tz; tz=tw;
  return tw=(tw^(tw>>19))^(tt^(tt>>8));
}

/* ---------- タイマ ---------- */
struct Timer {
  chrono::steady_clock::time_point st;
  void start(){ st = chrono::steady_clock::now(); }
  double ms() const {
    return chrono::duration_cast<chrono::milliseconds>(
             chrono::steady_clock::now() - st).count();
  }
} g_timer;

/* ──────────────────────────────────────────────────────────
   Runner : 1 回シミュレーション
   ────────────────────────────────────────────────────────── */
class Runner {
public:
  Runner(const vector<string>& S_, const vector<pair<int,int>>& empty_)
      : S(S_), empty(empty_) {}

  pair<double, vector<pair<int,int>>> run(int pool);

private:
  /* 入力参照 */
  const vector<string>& S;
  const vector<pair<int,int>>& empty;

  /* 盤面状態 */
  array<bool,   SZ> is_rock{};
  array<int,    SZ> up_stop, down_stop, left_stop, right_stop;

  /* スパース確率 (cur=0, nxt=1) */
  array<double, SZ> prob[2];
  vector<int> active_cur, active_nxt;         // 非ゼロ id 一覧
  array<int, SZ> mark{}; int stamp = 1;       // “重複 push” 防止用

  /* alive(未配置) 管理 */
  vector<int> alive;
  vector<int> pos_in_alive;

  /* util */
  static inline int idx(int r,int c){ return r*N+c; }
  static inline int row(int id){ return id/N; }
  static inline int col(int id){ return id%N; }

  void compute_all_stops();
  void update_stops(int r,int c);
};

/* ──────────────────────────────────────────────────────────
   Solver : 入出力ラッパ
   ────────────────────────────────────────────────────────── */
struct Solver {
  int M;
  vector<string> board;
  vector<pair<int,int>> empty;

  Solver(){
    int dummy; cin >> dummy >> M;
    board.resize(N);
    for(int i=0;i<N;++i){
      cin >> board[i];
      for(int j=0;j<N;++j)
        if(board[i][j]=='.') empty.emplace_back(i,j);
    }
  }

  void solve(){
    g_timer.start();
    Runner runner(board, empty);

    double best_E = -1;
    vector<pair<int,int>> best_P;
    long long iter = 0;

    while(g_timer.ms() < 1950.0){
      int pool = 1 + (rand_int()%100);
      auto [E,P] = runner.run(pool);
      if(E > best_E){ best_E = E; best_P = move(P); }
      ++iter;
    }
    cerr << "Iterations: " << iter << '\n';
    for(auto [r,c]: best_P) cout << r << ' ' << c << '\n';
  }
};

/* ──────────────────────────────────────────────────────────
   main
   ────────────────────────────────────────────────────────── */
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);
  Solver().solve();
  return 0;
}

/* **********************************************************************
   Runner::run    ― スパース遷移版
   ********************************************************************** */
pair<double, vector<pair<int,int>>> Runner::run(int pool){
  /* ---- 0. 初期化 --------------------------------------------------- */
  is_rock.fill(false);
  prob[0].fill(0.0); prob[1].fill(0.0);
  active_cur.clear(); active_nxt.clear();

  for(int r=0;r<N;++r)
    for(int c=0;c<N;++c)
      if(S[r][c]=='#') is_rock[idx(r,c)] = true;

  if(!empty.empty()){
    double p0 = 1.0/empty.size();
    for(auto [r,c]: empty){
      int id = idx(r,c);
      prob[0][id] = p0;
      active_cur.push_back(id);
    }
  }
  compute_all_stops();

  alive.clear();              alive.reserve(empty.size());
  pos_in_alive.assign(empty.size(),-1);
  for(int i=0;i<(int)empty.size();++i){
    alive.push_back(i);
    pos_in_alive[i]=i;
  }

  /* ---- 1. 反復 ----------------------------------------------------- */
  vector<pair<int,int>> placed; placed.reserve(empty.size());
  double expect=0, prob_alive=1;
  int cur=0, nxt=1;

  for(size_t step=0; step<empty.size(); ++step){
    /* 1-A : 確率遷移 (active のみ) */
    active_nxt.clear(); ++stamp;
    double sum_before=0;
    for(int id: active_cur){
      double p = prob[cur][id];
      if(p<=1e-12) continue;
      sum_before += p;
      double p4 = 0.25*p;

      auto push = [&](int to){
        if(mark[to]!=stamp){ mark[to]=stamp; active_nxt.push_back(to); }
        prob[nxt][to] += p4;
      };
      push(up_stop   [id]);
      push(down_stop [id]);
      push(left_stop [id]);
      push(right_stop[id]);

      prob[cur][id]=0;        // クリア
    }
    swap(cur,nxt);
    swap(active_cur, active_nxt);
    /* nxt バッファは次回の “0 埋め” 無しでそのまま流用できる */

    /* 1-B : 最小確率セル探索 */
    double minp = 2.0;
    vector<int> cand; cand.reserve(32);

    for(int idx_empty: alive){
      auto [r,c] = empty[idx_empty];
      double p = prob[cur][idx(r,c)];
      if(p < minp - 1e-12){
        minp = p; cand.clear(); cand.push_back(idx_empty);
      }else if(fabs(p-minp)<1e-12){
        cand.push_back(idx_empty);
      }
    }

    /* tie → ペナルティ pool 抽選 */
    int choose;
    if(cand.size()==1){
      choose = cand[0];
    }else{
      struct Sc{ double score; int id; };
      vector<Sc> scored; scored.reserve(cand.size());
      for(int idx_empty: cand){
        auto [r,c] = empty[idx_empty];
        int id = idx(r,c);
        int up_len    = r - row(up_stop[id]);
        int down_len  = row(down_stop[id]) - r;
        int left_len  = c - col(left_stop[id]);
        int right_len = col(right_stop[id]) - c;
        double pen = 1.0*up_len*down_len + 1.0*left_len*right_len;
        scored.push_back({pen,idx_empty});
      }
      int k = min<int>(pool, scored.size());
      nth_element(scored.begin(), scored.begin()+k, scored.end(),
                  [](auto& a,auto& b){ return a.score<b.score; });
      choose = scored[rand_int()%k].id;
    }

    /* 1-C : 岩設置・確率更新 */
    auto [br,bc] = empty[choose];
    int idPlaced = idx(br,bc);
    placed.push_back({br,bc});

    // alive swap-pop
    int pos = pos_in_alive[choose];
    int last = alive.back();
    alive[pos]=last; pos_in_alive[last]=pos; alive.pop_back();

    double destroyed = prob[cur][idPlaced];
    prob[cur][idPlaced]=0;
    double remain = sum_before - destroyed;

    if(sum_before > 1e-12) prob_alive *= remain/sum_before;
    expect += prob_alive;

    if(remain > 1e-12){
      double inv = 1.0/remain;
      for(int id: active_cur) prob[cur][id] *= inv;
    }else break;   // 全滅

    /* 1-D : 盤面・停止位置差分更新 */
    is_rock[idPlaced]=true;
    update_stops(br,bc);
  }
  return {expect, move(placed)};
}

/* **********************************************************************
   停止位置テーブル
   ********************************************************************** */
void Runner::compute_all_stops(){
  /* 左右 */
  for(int r=0;r<N;++r){
    int last=-1;
    for(int c=0;c<N;++c){
      left_stop[idx(r,c)] = idx(r,last+1);
      if(is_rock[idx(r,c)]) last=c;
    }
    last=N;
    for(int c=N-1;c>=0;--c){
      right_stop[idx(r,c)] = idx(r,last-1);
      if(is_rock[idx(r,c)]) last=c;
    }
  }
  /* 上下 */
  for(int c=0;c<N;++c){
    int last=-1;
    for(int r=0;r<N;++r){
      up_stop[idx(r,c)] = idx(last+1,c);
      if(is_rock[idx(r,c)]) last=r;
    }
    last=N;
    for(int r=N-1;r>=0;--r){
      down_stop[idx(r,c)] = idx(last-1,c);
      if(is_rock[idx(r,c)]) last=r;
    }
  }
}

/* 岩 1 マス追加時の差分更新 */
void Runner::update_stops(int r,int c){
  /* 上 */
  for(int i=r-1;i>=0 && !is_rock[idx(i,c)];--i)
    down_stop[idx(i,c)]=idx(r-1,c);
  /* 下 */
  for(int i=r+1;i<N && !is_rock[idx(i,c)];++i)
    up_stop[idx(i,c)]=idx(r+1,c);
  /* 左 */
  for(int j=c-1;j>=0 && !is_rock[idx(r,j)];--j)
    right_stop[idx(r,j)]=idx(r,c-1);
  /* 右 */
  for(int j=c+1;j<N && !is_rock[idx(r,j)];++j)
    left_stop[idx(r,j)]=idx(r,c+1);
}
