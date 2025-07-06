/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67390722
 * Submitted at: 2025-07-06 22:17:17
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1964 ms
 */

#include <bits/stdc++.h>
using namespace std;

/* ------------------------- 共通ユーティリティ ------------------------- */
constexpr int N = 40;

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11)); tx = ty; ty = tz; tz = tw;
  return tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8));
}

namespace util {
struct timer {
  chrono::steady_clock::time_point st;
  void start() { st = chrono::steady_clock::now(); }
  double ms() const {
    return chrono::duration_cast<chrono::milliseconds>(
             chrono::steady_clock::now() - st).count();
  }
} tm;
}  // namespace util

/* ------------------------------ Runner --------------------------------- */
class Runner {
public:
  Runner(const vector<string>& board,
         const vector<pair<int,int>>& empty_cells)
      : S(board), empty(empty_cells) {}

  pair<double, vector<pair<int,int>>> run(int random_pool_size);

private:
  /* 入力参照 */
  const vector<string>&             S;
  const vector<pair<int,int>>&      empty;

  /* 盤面状態 */
  bool   is_rock[N][N]{};

  /* 停止位置（事前計算＋差分更新） */
  int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];

  /* 確率 DP 二面バッファ */
  double cur_p[N][N]{}, nxt_p[N][N]{};

  /* 「まだ岩を置いていないマス」の管理を O(1) 削除で */
  vector<int> alive;            // empty[] のインデックス
  vector<int> pos_in_alive;     // idx → alive 内位置

  /* util */
  inline int  idx(int r,int c) const { return r*N + c; }
  inline pair<int,int> rc(int id) const { return { id / N, id % N }; }

  void compute_all_stops();
  void update_stops(int r,int c);
};

/* ------------------------------ Solver --------------------------------- */
struct Solver {
  int M;
  vector<string>            board;
  vector<pair<int,int>>     empty;

  Solver() {
    int dummy;  cin >> dummy >> M;
    board.resize(N);
    for(int i=0;i<N;++i){
      cin >> board[i];
      for(int j=0;j<N;++j)
        if(board[i][j]=='.') empty.emplace_back(i,j);
    }
  }

  void solve(){
    util::tm.start();
    Runner runner(board, empty);

    double best_E = -1.0;
    vector<pair<int,int>> best_P;
    long long iter = 0;

    while(util::tm.ms() < 1950){                 // 1.9 秒ループ
      int pool = 1 + (rand_int() % 100);
      auto [E, P] = runner.run(pool);
      if(E > best_E){ best_E = E; best_P = move(P); }
      ++iter;
    }
    cerr << "Iterations: " << iter << '\n';
    for(auto [r,c]: best_P) cout << r << ' ' << c << '\n';
  }
};

/* ------------------------------ main ----------------------------------- */
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);
  Solver().solve();
  return 0;
}

/* ======================================================================= */
/*  Runner::run                                                            */
/* ======================================================================= */
pair<double, vector<pair<int,int>>> Runner::run(int random_pool_size){
  /* ------- 初期化（盤面・確率・テーブル） ---------------------------- */
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j){
      is_rock[i][j] = (S[i][j]=='#');
      cur_p[i][j] = nxt_p[i][j] = 0.0;
    }
  if(!empty.empty()){
    double p0 = 1.0 / empty.size();
    for(auto [r,c] : empty) cur_p[r][c] = p0;
  }
  compute_all_stops();

  /* ------- alive 配列 O(1) 削除初期化 ------------------------------- */
  alive.clear();              alive.reserve(empty.size());
  pos_in_alive.assign(empty.size(), -1);
  for(int i=0;i<(int)empty.size();++i){
    alive.push_back(i);
    pos_in_alive[i]=i;
  }

  /* ------- メインループ --------------------------------------------- */
  vector<pair<int,int>> placed; placed.reserve(empty.size());
  double expected_prize=0.0, prob_alive=1.0;

  for(size_t step=0; step<empty.size(); ++step){
    /* ---- 1. 移動遷移（盤面全走査： 40×40 = 1600） ---------------- */
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j) nxt_p[i][j] = 0.0;

    double total_before = 0.0;
    for(int r=0;r<N;++r)
      for(int c=0;c<N;++c)
        if(cur_p[r][c] > 1e-12){
          total_before += cur_p[r][c];
          double p4 = cur_p[r][c] * 0.25;
          nxt_p[up_stop   [r][c]][c] += p4;
          nxt_p[down_stop [r][c]][c] += p4;
          nxt_p[r][left_stop [r][c]] += p4;
          nxt_p[r][right_stop[r][c]] += p4;
        }
    swap(cur_p, nxt_p);

    /* ---- 2. 最小確率セル探索（alive だけ一周） -------------------- */
    double min_p = 2.0;
    vector<int> cand; cand.reserve(32);

    for(int idx_alive : alive){
      auto [r,c] = empty[idx_alive];
      double p = cur_p[r][c];
      if(p < min_p - 1e-12){
        min_p = p;
        cand.clear(); cand.push_back(idx_alive);
      }else if(fabs(p - min_p) < 1e-12){
        cand.push_back(idx_alive);
      }
    }

    /* ---- 3. tie → penalty (停止長さ) で pool 抽選 ---------------- */
    int choose_idx;
    if(cand.size()==1){
      choose_idx = cand[0];
    }else{
      struct Sc { double score; int id; };
      vector<Sc> scored; scored.reserve(cand.size());
      for(int id : cand){
        auto [r,c] = empty[id];
        int up_len    = r - up_stop[r][c];
        int down_len  = down_stop[r][c] - r;
        int left_len  = c - left_stop[r][c];
        int right_len = right_stop[r][c] - c;
        double pen = 1.0 * up_len * down_len + 1.0 * left_len * right_len;
        scored.push_back({pen,id});
      }
      int pool = min<int>(random_pool_size, scored.size());
      nth_element(scored.begin(), scored.begin()+pool, scored.end(),
                  [](const Sc& a,const Sc& b){ return a.score < b.score; });
      choose_idx = scored[rand_int() % pool].id;
    }

    /* ---- 4. 岩設置・データ構造更新 ------------------------------- */
    auto [br,bc] = empty[choose_idx];
    placed.push_back({br,bc});

    /* alive から O(1) 削除 */
    int pos = pos_in_alive[choose_idx];
    int last_idx = alive.back();
    alive[pos] = last_idx;            pos_in_alive[last_idx] = pos;
    alive.pop_back();

    /* 期待賞金計算 & 正規化 */
    double destroyed = cur_p[br][bc];
    cur_p[br][bc] = 0.0;
    double remain = total_before - destroyed;
    if(total_before > 1e-12) prob_alive *= (remain / total_before);
    expected_prize += prob_alive;

    if(remain > 1e-12){
      double inv = 1.0 / remain;
      for(int r=0;r<N;++r)
        for(int c=0;c<N;++c) cur_p[r][c] *= inv;
    }

    /* 盤面へ岩を追加し停止表差分更新 */
    is_rock[br][bc] = true;
    update_stops(br,bc);
  }
  return {expected_prize, move(placed)};
}

/* ---------------- 停止位置テーブル全計算 ------------------------------ */
void Runner::compute_all_stops(){
  for(int i=0;i<N;++i){
    int last=-1;
    for(int j=0;j<N;++j){
      left_stop[i][j] = last+1;
      if(is_rock[i][j]) last = j;
    }
    last = N;
    for(int j=N-1; j>=0; --j){
      right_stop[i][j] = last-1;
      if(is_rock[i][j]) last = j;
    }
  }
  for(int j=0;j<N;++j){
    int last=-1;
    for(int i=0;i<N;++i){
      up_stop[i][j] = last+1;
      if(is_rock[i][j]) last = i;
    }
    last = N;
    for(int i=N-1; i>=0; --i){
      down_stop[i][j] = last-1;
      if(is_rock[i][j]) last = i;
    }
  }
}

/* --------- 1 マス岩追加時の差分更新（while で距離 O(距離)） ---------- */
void Runner::update_stops(int r,int c){
  /* 上方向 */
  int i = r-1; while(i>=0 && !is_rock[i][c]){ down_stop[i][c] = r-1; --i; }
  /* 下方向 */
  i = r+1;     while(i<N  && !is_rock[i][c]){ up_stop[i][c]   = r+1; ++i; }
  /* 左方向 */
  int j = c-1; while(j>=0 && !is_rock[r][j]){ right_stop[r][j]= c-1; --j; }
  /* 右方向 */
  j = c+1;     while(j<N  && !is_rock[r][j]){ left_stop[r][j] = c+1; ++j; }
}
