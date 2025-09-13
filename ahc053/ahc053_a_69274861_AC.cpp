/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc053/submissions/69274861
 * Submitted at: 2025-09-13 19:49:34
 * Problem URL: https://atcoder.jp/contests/ahc053/tasks/ahc053_a
 * Result: AC
 * Execution Time: 1953 ms
 */

#include <bits/stdc++.h>
using namespace std;

// -------- fast RNG (xorshift) --------
static inline uint32_t rng_u32() {
  static uint32_t x=123456789u,y=362436069u,z=521288629u,w=88675123u;
  uint32_t t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
static inline int rng_int(int l, int r){ // inclusive
  return l + (int)(rng_u32() % (uint32_t)(r - l + 1));
}
static inline double rng_double(){
  return (double)(rng_u32() & 0xFFFFFF) / (double)(0x1000000);
}

static inline unsigned long long pow2_ull(int e){
  if (e >= 63) return (1ULL << 62); // guard
  return (1ULL << e);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  long long L, U;
  if(!(cin >> N >> M >> L >> U)) return 0;

  // ===== 1) カード設計: L×M + 幾何重み + 微調整 =====
  unsigned long long W = (U >= L) ? (unsigned long long)(U - L) : 0ULL;

  // まず各山に L を1枚（M枚）確保
  int fixed_L = min(M, N);
  int free_cards = max(0, N - fixed_L);

  // 在庫設計: 各段に必要な在庫 C_need = ceil(M/2 + 3*sqrt(M)/2)
  double z = 3.0;
  int C_need = (int)ceil(0.5 * M + 0.5 * z * sqrt((double)M));
  C_need = max(1, min(C_need, M));

  // 取れる段数 K を最大化（安全上限 60）
  int K = 0;
  if (W > 0 && free_cards > 0) {
    K = min(60, free_cards / C_need);
  }

  // base = floor(W / (2^K - 1))
  unsigned long long denom = (K>=1) ? (pow2_ull(K) - 1ULL) : 1ULL;
  if (denom == 0ULL) denom = 1ULL;
  unsigned long long base_ull = (K>=1 ? (W / denom) : 0ULL);
  long long base = (long long)((K>=1) ? max(1ULL, base_ull) : 1ULL);

  // 微調整粒度 g = base / 2^d（R と M から決める）
  // 期待不足 ~ M*(base/4) を R*g で吸収したい ⇒ R/M ≈ 2^(d-2) を目安
  int coarse_cards_capacity = (K>0 ? K * C_need : 0);
  int coarse_cards = min(free_cards, coarse_cards_capacity);
  int R = free_cards - coarse_cards;
  if (R < 0) R = 0;
  int d = 0;
  if (M > 0 && (R > 0 || K == 0)) {
    long double lhs = (long double)4.0L * (long double)max(1, R) / (long double)max(1, M);
    long double lg = floor(log2((long double)max(1.0L, lhs)));
    d = (int)max(0.0L, lg);
  }
  long long g = (long long)max(1ULL, (unsigned long long)base >> d);

  // A 構築
  vector<long long> A; A.reserve(N);
  vector<int> idx_L; idx_L.reserve(fixed_L);
  for(int j=0;j<fixed_L;++j){ idx_L.push_back((int)A.size()); A.push_back(L); }

  vector<vector<int>> idx_bit(K);
  vector<long long> w(K,1);
  for(int i=0;i<K;++i){
    __int128 w128 = ( (__int128)base ) * ( (__int128)pow2_ull(i) );
    unsigned long long w_ull = (w128 > (__int128)ULLONG_MAX ? ULLONG_MAX : (unsigned long long)w128);
    long long wi = (long long)min<unsigned long long>(w_ull, (unsigned long long)U);
    if (wi < 1) wi = 1;
    w[i]=wi;
    int quota = min(C_need, N - (int)A.size());
    idx_bit[i].reserve(quota);
    for(int t=0;t<quota && (int)A.size()<N;++t){
      idx_bit[i].push_back((int)A.size());
      A.push_back(wi);
    }
  }

  vector<int> idx_fine;
  for(int t=0; t<R && (int)A.size()<N; ++t){
    idx_fine.push_back((int)A.size());
    A.push_back(g);
  }
  while((int)A.size()<N){ idx_fine.push_back((int)A.size()); A.push_back(g); }

  // ---- A 1行出力 ----
  for(int i=0;i<N;++i){ if(i) cout << ' '; cout << A[i]; }
  cout << '\n' << flush;

  // ===== 2) B を読む =====
  vector<long long> B(M,0);
  for(int j=0;j<M;++j){ if(!(cin>>B[j])) B[j]=0; }

  // ===== 3) 初期解（希望ビット供給） =====
  vector<int> X(N,0);
  vector<long long> S(M,0);

  // L を固定割当
  for(int j=0;j<(int)idx_L.size() && j<M;++j){
    int id = idx_L[j];
    X[id] = j+1;
    S[j] += A[id];
  }

  // 目標ビット列 t_j
  vector<unsigned long long> t(M,0);
  if (K>=1){
    unsigned long long maxT = (K>=63 ? ((1ULL<<62)-1ULL) : (pow2_ull(K) - 1ULL));
    for(int j=0;j<M;++j){
      long long delta = B[j] - L;
      if (delta < 0) delta = 0;
      if ((unsigned long long)delta > W) delta = (long long)W;
      unsigned __int128 num = (unsigned __int128)((unsigned long long)delta) + (unsigned long long)(base/2);
      unsigned long long tt = (base>0) ? (unsigned long long)( num / (unsigned long long)base ) : 0ULL;
      if (tt > maxT) tt = maxT;
      t[j] = tt;
    }
  }

  // グループ個数 y[i][j], y_fine[j] を作る（初期割当）
  vector<vector<int>> y(K, vector<int>(M,0));
  vector<int> tot_y(K,0); // 各重みでの総使用枚数
  auto deficit_cmp = [&](int a, int b){ return (B[a]-S[a]) > (B[b]-S[b]); };

  for(int i=K-1;i>=0;--i){
    if (idx_bit[i].empty()) continue;
    long long wi = w[i];
    vector<int> want; want.reserve(M);
    for(int j=0;j<M;++j) if ((t[j]>>i)&1ULL) want.push_back(j);
    sort(want.begin(), want.end(), deficit_cmp);
    int supply = (int)idx_bit[i].size();
    int used = 0;
    for(int idx=0; idx<(int)want.size() && used<supply; ++idx){
      int j = want[idx];
      long long dlt = B[j]-S[j];
      if (dlt < (wi+1)/2) continue;
      y[i][j]++; tot_y[i]++; used++;
      S[j] += wi;
    }
    // 余りは未使用のまま（捨て）
  }

  // 微調整コイン：Δ>=g/2 の山に貪欲
  vector<int> yfine(M,0);
  if (!idx_fine.empty()){
    struct Node { long long d; int j; };
    struct Cmp2 { bool operator()(const Node& a, const Node& b) const {
      if (a.d!=b.d) return a.d < b.d;
      return a.j > b.j;
    }};
    priority_queue<Node, vector<Node>, Cmp2> pq;
    for(int j=0;j<M;++j){
      long long dlt = B[j]-S[j];
      if (dlt >= (g+1)/2) pq.push({dlt,j});
    }
    int supply = (int)idx_fine.size();
    int used=0;
    while(used<supply && !pq.empty()){
      auto top=pq.top(); pq.pop();
      if (top.d < (g+1)/2) break;
      int j=top.j;
      yfine[j]++; used++; S[j]+=g;
      long long nd = B[j]-S[j];
      if (nd >= (g+1)/2) pq.push({nd,j});
    }
    // 余りは捨て
  }

  // ===== 4) グループ焼きなまし（y, yfine を操作） =====
  // 目的: E = sum |S-B| を最小化
  auto calcE = [&](const vector<long long>& Sref)->long long{
    long long E=0; for(int j=0;j<M;++j) E += llabs(Sref[j]-B[j]); return E;
  };
  long long E = calcE(S);
  long long bestE = E;
  vector<vector<int>> best_y = y;
  vector<int> best_yfine = yfine;
  vector<long long> bestS = S;

  // 便利：レベル総在庫
  vector<int> q(K,0);
  for(int i=0;i<K;++i) q[i] = (int)idx_bit[i].size();
  int qfine = (int)idx_fine.size();

  auto try_add = [&](int i, int j, long long wi)->long long{
    long long old = llabs(S[j]-B[j]);
    long long ne  = llabs(S[j]+wi - B[j]);
    return ne - old;
  };
  auto try_remove = [&](int i, int j, long long wi)->long long{
    long long old = llabs(S[j]-B[j]);
    long long ne  = llabs(S[j]-wi - B[j]);
    return ne - old;
  };
  auto try_transfer = [&](int i, int ja, int jb, long long wi)->long long{
    long long oa = llabs(S[ja]-B[ja]), ob = llabs(S[jb]-B[jb]);
    long long na = llabs(S[ja]-wi - B[ja]), nb = llabs(S[jb]+wi - B[jb]);
    return (na+nb) - (oa+ob);
  };

  // SA パラメータ
  const double SA_MS = 1950.0; // 残り時間を考慮して ~1.65s
  auto t0 = chrono::high_resolution_clock::now();
  auto elapsed_ms = [&](){
    auto now = chrono::high_resolution_clock::now();
    return (double)chrono::duration_cast<chrono::milliseconds>(now - t0).count();
  };
  long double T0 = max<long double>((long double)base*4, (long double)g*8);
  if (T0 < 1e5L) T0 = 1e5L;
  long double T1 = 1e2L;

  auto pick_best_of = [&](int k)->int{
    int best=-1; long long bestd=LLONG_MIN;
    for(int t=0;t<k;++t){
      int j = rng_int(0, M-1);
      long long d = B[j]-S[j];
      if (d>bestd){ bestd=d; best=j; }
    }
    if (best==-1) best= rng_int(0, M-1);
    return best;
  };

  while (elapsed_ms() < SA_MS){
    long double progress = elapsed_ms() / SA_MS;
    if (progress>1) progress=1;
    long double T = expl( logl(T0) * (1-progress) + logl(T1) * progress );

    // レベル選択：微調整を厚め（50%）、残りは q[i] 比例
    int which = -1; bool fine = false;
    if (qfine>0 && rng_u32()%2==0) { fine=true; }
    if (!fine){
      int total_q = 0; for(int i=0;i<K;++i) total_q += max(1,q[i]);
      int r = rng_int(1, max(1,total_q));
      int acc=0;
      for(int i=0;i<K;++i){ acc += max(1,q[i]); if (r<=acc){ which=i; break; } }
      if (which<0) which = rng_int(0, max(0,K-1));
    }

    // 操作タイプ：0=Add 1=Remove 2=Transfer
    int op = rng_int(0,2);

    if (fine){
      long long wi = g;
      // counts: yfine[j], capacity: qfine
      if (op==0){ // Add if remain
        int remain = qfine;
        for(int j=0;j<M;++j) remain -= yfine[j];
        if (remain<=0) continue;
        int j = pick_best_of(4);
        long long dE = try_add(-1, j, wi);
        if (dE<=0 || rng_double() < expl(-(long double)dE / T)){
          yfine[j]++; S[j]+=wi; E+=dE;
          if (E<bestE){ bestE=E; best_y=y; best_yfine=yfine; bestS=S; }
        }
      } else if (op==1){ // Remove from random j with yfine>0
        int tries=8, j=-1;
        while(tries--){
          int cand = rng_int(0, M-1);
          if (yfine[cand]>0){ j=cand; break; }
        }
        if (j==-1) continue;
        long long dE = try_remove(-1, j, wi);
        if (dE<=0 || rng_double() < expl(-(long double)dE / T)){
          yfine[j]--; S[j]-=wi; E+=dE;
          if (E<bestE){ bestE=E; best_y=y; best_yfine=yfine; bestS=S; }
        }
      } else { // Transfer
        int ja=-1, jb=-1;
        int tries=8;
        while(tries--){
          int cand = rng_int(0, M-1);
          if (yfine[cand]>0){ ja=cand; break; }
        }
        if (ja<0) continue;
        jb = pick_best_of(3);
        if (jb==ja) continue;
        long long dE = try_transfer(-1, ja, jb, wi);
        if (dE<=0 || rng_double() < expl(-(long double)dE / T)){
          yfine[ja]--; yfine[jb]++; S[ja]-=wi; S[jb]+=wi; E+=dE;
          if (E<bestE){ bestE=E; best_y=y; best_yfine=yfine; bestS=S; }
        }
      }
    } else if (K>0){
      int i = which;
      long long wi = w[i];
      int remain = q[i] - tot_y[i];
      if (op==0){
        if (remain<=0) continue;
        int j = pick_best_of(4);
        long long dE = try_add(i, j, wi);
        if (dE<=0 || rng_double() < expl(-(long double)dE / T)){
          y[i][j]++; tot_y[i]++; S[j]+=wi; E+=dE;
          if (E<bestE){ bestE=E; best_y=y; best_yfine=yfine; bestS=S; }
        }
      } else if (op==1){
        int tries=8, j=-1;
        while(tries--){
          int cand = rng_int(0, M-1);
          if (y[i][cand]>0){ j=cand; break; }
        }
        if (j==-1) continue;
        long long dE = try_remove(i, j, wi);
        if (dE<=0 || rng_double() < expl(-(long double)dE / T)){
          y[i][j]--; tot_y[i]--; S[j]-=wi; E+=dE;
          if (E<bestE){ bestE=E; best_y=y; best_yfine=yfine; bestS=S; }
        }
      } else {
        int ja=-1, jb=-1;
        int tries=8;
        while(tries--){
          int cand = rng_int(0, M-1);
          if (y[i][cand]>0){ ja=cand; break; }
        }
        if (ja<0) continue;
        jb = pick_best_of(3);
        if (jb==ja) continue;
        long long dE = try_transfer(i, ja, jb, wi);
        if (dE<=0 || rng_double() < expl(-(long double)dE / T)){
          y[i][ja]--; y[i][jb]++; S[ja]-=wi; S[jb]+=wi; E+=dE;
          if (E<bestE){ bestE=E; best_y=y; best_yfine=yfine; bestS=S; }
        }
      }
    }
  }

  // ベストに戻す
  y = best_y; yfine = best_yfine; S = bestS;

  // ===== 5) y → 実カード X へマッピング =====
  // まず X を 0 クリア（L は維持）
  for(int i=0;i<N;++i) if (X[i]!=0) X[i]=0;
  // L を再設定
  for(int j=0;j<(int)idx_L.size() && j<M;++j){ int id=idx_L[j]; X[id]=j+1; }

  // 幾何重み
  for(int i=0;i<K;++i){
    int ptr = 0;
    for(int j=0;j<M;++j){
      int need = y[i][j];
      while(need>0 && ptr < (int)idx_bit[i].size()){
        int id = idx_bit[i][ptr++];
        X[id] = j+1;
        --need;
      }
    }
    // 余りは捨て（X=0 のまま）
  }

  // 微調整
  {
    int ptr=0;
    for(int j=0;j<M;++j){
      int need = yfine[j];
      while(need>0 && ptr < (int)idx_fine.size()){
        int id = idx_fine[ptr++];
        X[id] = j+1;
        --need;
      }
    }
  }

  // 安全：範囲外は 0（捨て）
  for(int i=0;i<N;++i) if (X[i]<0 || X[i]>M) X[i]=0;

  // ===== 6) X を 1行出力 =====
  for(int i=0;i<N;++i){ if(i) cout << ' '; cout << X[i]; }
  cout << '\n' << flush;

  return 0;
}
