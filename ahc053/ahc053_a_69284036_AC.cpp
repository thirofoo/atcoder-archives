/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc053/submissions/69284036
 * Submitted at: 2025-09-13 22:41:57
 * Problem URL: https://atcoder.jp/contests/ahc053/tasks/ahc053_a
 * Result: AC
 * Execution Time: 1952 ms
 */

#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   AHC053 - Random Sum Game
   追加:
     - 2グループ再分配近傍（p,q を選び、p/q に属する可動カードを
       目標に近づくように再割当）
     - 3グループ再分配近傍（p,q,r の3山で同様）
   既存:
     - V_INIT は既定 2e12（env V_INIT で上書き可）
     - BASELINE は既定 L（= 1e15-2e12 を想定、env BASELINE で上書き可）
     - 行列→カード値は整数安全な重み
     - 出力は 1 行スペース区切り
   ========================================================= */

// =================== RNG (xorshift) ===================
static inline uint32_t rng_u32() {
  static uint32_t x=123456789u,y=362436069u,z=521288629u,w=88675123u;
  uint32_t t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
static inline int rng_int(int l, int r){ // inclusive
  return l + (int)(rng_u32() % (uint32_t)(r - l + 1));
}
static inline double rng_double() {
  return (double)(rng_u32() & 0xFFFFFF) / (double)(0x1000000);
}

// =================== params ===================
// #columns (weight levels). env COLS overrides.
#ifndef COLS_DEFAULT
#define COLS_DEFAULT 40
#endif
// ones per row = bits per card. env BITS_PER_CARD overrides.
#ifndef BITS_PER_CARD_DEFAULT
#define BITS_PER_CARD_DEFAULT 6
#endif
// min tokens per column (lower bound). env PER_LEVEL overrides.
#ifndef PER_LEVEL_QTY
#define PER_LEVEL_QTY 60
#endif

static inline long long clamp_ll(long long v, long long lo, long long hi){
  return v<lo ? lo : (v>hi ? hi : v);
}
static inline unsigned long long pow2_ull_safe(int e){
  if (e <= 0) return 1ULL;
  if (e >= 63) return (1ULL<<62); // guard
  return (1ULL<<e);
}

// =================== main ===================
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M; long long L, U;
  if(!(cin >> N >> M >> L >> U)) return 0;

  const int R = max(0, N - M); // composite rows

  // runtime params
  int COLS = COLS_DEFAULT;
  if (const char* s=getenv("COLS")) {
    int v=atoi(s); if (1<=v && v<=60) COLS=v; // 60まで
  }
  int BPC = BITS_PER_CARD_DEFAULT;
  if (const char* s=getenv("BITS_PER_CARD")) {
    int v=atoi(s); if (1<=v && v<=60) BPC=v;
  }
  if (BPC > COLS) BPC = COLS; // 行の 1 は列数以下

  int min_per_level = PER_LEVEL_QTY;
  if (const char* s=getenv("PER_LEVEL")) {
    int v=atoi(s); if (v>=0) min_per_level=v;
  }

  // V_INIT (既定 2e12), BASELINE(既定 L)
  long long V_INIT = 2000000000000LL; // 2e12
  if (const char* s=getenv("V_INIT")) {
    long long v = atoll(s);
    if (v > 0) V_INIT = v;
  }
  long long BASELINE = L;
  if (const char* s=getenv("BASELINE")) {
    long long v = atoll(s);
    if (v > 0) BASELINE = v;
  }
  BASELINE = clamp_ll(BASELINE, 1LL, U);

  // ===== 1) 0/1 行列 (R x COLS) =====
  long long total_ones = 1LL*R*BPC;
  long long need_min = 1LL*COLS*min_per_level;
  int eff_min_per_level = min_per_level;
  if (COLS <= 0 || R <= 0 || BPC <= 0) eff_min_per_level = 0;
  if (total_ones < need_min) {
    eff_min_per_level = (COLS>0) ? (int)(total_ones / COLS) : 0;
  }

  vector<int> Q(max(1, COLS), 0);
  if (COLS > 0) {
    long long baseq = total_ones / COLS;
    long long rem   = total_ones - baseq * COLS;
    for (int j=0;j<COLS;++j) Q[j] = (int)baseq;
    for (int j=0;j<COLS && rem>0;++j){ Q[j]++; --rem; }

    int changed = 1;
    while (changed) {
      changed = 0;
      int need = 0;
      for (int j=0;j<COLS;++j) if (Q[j] < eff_min_per_level) need += (eff_min_per_level - Q[j]);
      if (need == 0) break;
      for (int j=0;j<COLS && need>0;++j) if (Q[j] > eff_min_per_level) {
        int give = min(Q[j] - eff_min_per_level, need);
        Q[j] -= give; need -= give; changed = 1;
      }
      if (need>0) { eff_min_per_level = max(0, eff_min_per_level-1); changed = 1; }
    }
    long long sumQ = 0; for (int j=0;j<COLS;++j) sumQ += Q[j];
    if (sumQ < total_ones) {
      int add = (int)(total_ones - sumQ);
      for (int j=0;j<COLS && add>0;++j){ Q[j]++; --add; }
    } else if (sumQ > total_ones) {
      int sub = (int)(sumQ - total_ones);
      for (int j=0;j<COLS && sub>0;++j) if (Q[j] > 0){ Q[j]--; --sub; }
    }
  }

  // 列ごとの必要回数に応じたトークン
  vector<int> tok;
  if (COLS > 0){
    tok.reserve((size_t)max(0LL, total_ones));
    for (int j=0;j<COLS;++j) for (int k=0;k<Q[j];++k) tok.push_back(j);
    for (int i=(int)tok.size()-1;i>0;--i){
      int r = rng_u32() % (uint32_t)(i+1);
      if (r!=i) swap(tok[i], tok[r]);
    }
  }

  vector<vector<int>> row_cols(R, vector<int>(max(0,BPC), -1));
  vector<int> row_cnt(R, 0);
  vector<char> used(tok.size(), 0);

  auto has_col_row = [&](int r, int c)->bool{
    for (int z=0; z<row_cnt[r]; ++z) if (row_cols[r][z]==c) return true;
    return false;
  };
  auto take_token = [&](int pos, int r)->bool{
    if (pos<0 || pos>=(int)tok.size()) return false;
    if (used[pos]) return false;
    int c = tok[pos];
    if (has_col_row(r, c)) return false;
    if (row_cnt[r] >= BPC) return false;
    row_cols[r][row_cnt[r]++] = c;
    used[pos] = 1;
    return true;
  };

  for (int r=0;r<R;++r){
    for (int b=0;b<BPC;++b){
      int pos = (tok.empty()? -1 : r + b*R);
      if (take_token(pos, r)) continue;

      bool ok=false;
      for (int k=pos+1;k<(int)tok.size();++k){
        if (used[k]) continue;
        int c=tok[k];
        if (has_col_row(r,c)) continue;
        if (row_cnt[r] >= BPC) break;
        row_cols[r][row_cnt[r]++] = c; used[k]=1; ok=true; break;
      }
      if (!ok){
        for (int k=0;k<pos;++k){
          if (used[k]) continue;
          int c=tok[k];
          if (has_col_row(r,c)) continue;
          if (row_cnt[r] >= BPC) break;
          row_cols[r][row_cnt[r]++] = c; used[k]=1; ok=true; break;
        }
      }
      if (!ok){
        for (int k=0;k<(int)tok.size();++k){
          if (used[k]) continue;
          if (row_cnt[r] >= BPC) break;
          row_cols[r][row_cnt[r]++] = tok[k]; used[k]=1; ok=true; break;
        }
      }
    }
  }

  // --- 行ユニーク化（COLS<=60 のとき） ---
  if (COLS <= 60 && R > 0 && BPC > 0) {
    unordered_set<uint64_t> seen; seen.reserve(R*2);
    auto code_of = [&](int r)->uint64_t{
      uint64_t m=0;
      for (int z=0; z<row_cnt[r]; ++z) if (row_cols[r][z]>=0) m |= (1ULL << row_cols[r][z]);
      return m;
    };
    vector<int> colcnt(COLS, 0);
    for (int r=0;r<R;++r) for (int z=0; z<row_cnt[r]; ++z) if (row_cols[r][z]>=0) colcnt[row_cols[r][z]]++;

    for (int r=0;r<R;++r){
      uint64_t m = code_of(r);
      if (!seen.insert(m).second) {
        bool fixed=false;
        for (int tries=0; tries<200 && !fixed; ++tries){
          int z1 = rng_int(0, row_cnt[r]-1);
          int c1 = row_cols[r][z1];
          if (c1<0) continue;
          if (colcnt[c1]-1 < eff_min_per_level) continue;
          int c0 = rng_int(0, COLS-1);
          if ( (m>>c0)&1ULL ) continue;
          row_cols[r][z1] = c0;
          colcnt[c1]--; colcnt[c0]++;
          uint64_t nm = (m & ~(1ULL<<c1)) | (1ULL<<c0);
          if (!seen.count(nm)) { m = nm; seen.insert(nm); fixed=true; break; }
          row_cols[r][z1] = c1;
          colcnt[c1]++; colcnt[c0]--;
        }
      }
    }
  }

  // ===== 2) 行列 → カード値 =====
  unsigned long long denom = pow2_ull_safe(COLS);
  long long base_unit = (long long)max(1ULL, (unsigned long long)( (V_INIT > 0) ? (unsigned long long)(V_INIT) / (denom ? denom : 1ULL) : 0ULL ));
  vector<long long> wcol(max(0,COLS), 1);
  for (int c=0;c<COLS;++c){
    int sh = COLS - c;
    unsigned long long p2 = (sh>=63) ? (1ULL<<62) : (1ULL<<sh);
    unsigned __int128 tmp = (unsigned __int128)( (unsigned long long)base_unit ) * (unsigned __int128)p2;
    unsigned long long wi = (tmp > (unsigned __int128)ULLONG_MAX ? ULLONG_MAX : (unsigned long long)tmp);
    long long wv = (long long)min<unsigned long long>(wi, (unsigned long long)U);
    if (wv < 1) wv = 1;
    wcol[c] = wv;
  }

  vector<long long> A; A.reserve(N);
  // anchor: 最初の M 枚は BASELINE（各山のアンカー）
  for (int j=0;j<M && (int)A.size()<N; ++j) A.push_back(BASELINE);
  // 残り R 枚は合成カード
  for (int r=0;r<R && (int)A.size()<N; ++r){
    unsigned __int128 s = 0;
    for (int z=0; z<row_cnt[r]; ++z){
      int c = row_cols[r][z];
      if (0<=c && c<COLS) s += (unsigned __int128) wcol[c];
    }
    long long val = (long long) ( s > (unsigned __int128)U ? U : (s<(unsigned __int128)1 ? 1 : (unsigned long long)s) );
    A.push_back(val);
  }
  while ((int)A.size()<N) A.push_back( max(1LL, min(U, base_unit)) );

  // ===== 3) output A (space-separated) =====
  for (int i=0;i<N;++i){ if (i) cout << ' '; cout << A[i]; }
  cout << '\n' << flush;

  // ===== 4) read B =====
  vector<long long> B(M,0);
  for (int j=0;j<M;++j){ if (!(cin >> B[j])) B[j]=0; }

  // ===== 5) 割り当て（貪欲 + SA） =====
  vector<int> X(N,0);
  vector<long long> S(M,0);

  // アンカーを各山に固定
  for (int j=0;j<M && j<N; ++j){
    X[j] = j+1;
    S[j] += A[j];
  }

  // 初期貪欲
  for (int i=M;i<N;++i){
    long long bestDelta = 0; int bestJ = -1;
    long long ai = A[i];
    for (int j=0;j<M;++j){
      long long before = llabs(S[j] - B[j]);
      long long after  = llabs(S[j] + ai - B[j]);
      long long d = after - before; // <0 が改善
      if (d < bestDelta){ bestDelta = d; bestJ = j; }
    }
    if (bestJ >= 0){ X[i] = bestJ+1; S[bestJ] += A[i]; }
  }

  auto totalE = [&]()->long long{
    long long E=0; for (int j=0;j<M;++j) E += llabs(S[j]-B[j]); return E;
  };
  long long E = totalE();
  long long bestE = E;
  vector<int> bestX = X;
  vector<long long> bestS = S;

  // ===== 近傍: 単移動 / スワップ（従来） =====
  auto d_move = [&](int from, int to, long long a)->long long{
    long long d=0;
    if (from>=0) {
      long long bf = llabs(S[from]-B[from]);
      long long af = llabs(S[from]-a - B[from]);
      d += (af-bf);
    }
    if (to>=0) {
      long long bt = llabs(S[to]-B[to]);
      long long at = llabs(S[to]+a - B[to]);
      d += (at-bt);
    }
    return d;
  };
  auto d_swap = [&](int i, int j)->long long{
    int ai = X[i]-1, aj = X[j]-1;
    long long a=A[i], b=A[j];
    if (ai==aj) return 0;
    long long d=0;
    if (ai>=0){
      long long bf = llabs(S[ai]-B[ai]);
      long long af = llabs(S[ai]-a + b - B[ai]);
      d += (af-bf);
    }
    if (aj>=0){
      long long bf = llabs(S[aj]-B[aj]);
      long long af = llabs(S[aj]-b + a - B[aj]);
      d += (af-bf);
    }
    return d;
  };

  // ===== 近傍: 2グループ再分配 =====
  auto try_rebalance2 = [&](int p, int q, long double T)->bool{
    if (p==q) return false;
    int P = p-1, Q = q-1;

    // 対象は「可動カード（i>=M）」で、今 p または q にあるもの
    vector<int> ids; ids.reserve(64);
    long long curMovP=0, curMovQ=0;
    for (int i=M;i<N;++i){
      if (X[i]==p){ ids.push_back(i); curMovP += A[i]; }
      else if (X[i]==q){ ids.push_back(i); curMovQ += A[i]; }
    }
    if (ids.size() <= 1) return false;

    // 大きい順に重要度を上げる（大きいものから決める）
    sort(ids.begin(), ids.end(), [&](int i, int j){ return A[i] > A[j]; });

    // 過大計算を防ぐため制限
    const int LIMIT = 120;
    if ((int)ids.size() > LIMIT) ids.resize(LIMIT);

    long long fixedP = S[P] - curMovP;
    long long fixedQ = S[Q] - curMovQ;
    long long Tmov   = 0; for (int i: ids) Tmov += A[i];

    // 目的関数は |(fixedP + x) - Bp| + |(fixedQ + (Tmov - x)) - Bq|
    // これは |x - a| + |x - b| （a=Bp-fixedP, b=Tmov-(Bq-fixedQ)）
    long long a = B[P] - fixedP;
    long long b = Tmov - (B[Q] - fixedQ);
    long double x_goal = 0.5L * ((long double)a + (long double)b);

    // 貪欲: x（p に入れた移動分）を x_goal に近づける
    long long x = 0;
    vector<char> toP(ids.size(), 0);
    for (size_t t=0; t<ids.size(); ++t){
      long long w = A[ids[t]];
      long double before = fabsl((long double)x - x_goal);
      long double afterP = fabsl((long double)(x + w) - x_goal);
      // p に入れて x_goal に近づくなら p、さもなくば q
      if (afterP <= before){ toP[t] = 1; x += w; }
    }

    // 局所改善: p側のアイテムを落として q に送って |x-x_goal| が縮むなら送る
    bool improved = true;
    int safety = 0;
    while (improved && safety++ < 3){
      improved = false;
      // move 1 from P->Q
      for (size_t t=0; t<ids.size(); ++t){
        if (!toP[t]) continue;
        long long w = A[ids[t]];
        long double cur = fabsl((long double)x - x_goal);
        long double nxt = fabsl((long double)(x - w) - x_goal);
        if (nxt + 1e-9L < cur){
          toP[t] = 0; x -= w; improved = true;
        }
      }
      // move 1 from Q->P
      for (size_t t=0; t<ids.size(); ++t){
        if (toP[t]) continue;
        long long w = A[ids[t]];
        long double cur = fabsl((long double)x - x_goal);
        long double nxt = fabsl((long double)(x + w) - x_goal);
        if (nxt + 1e-9L < cur){
          toP[t] = 1; x += w; improved = true;
        }
      }
      // 1-1 swap
      for (size_t i1=0; i1<ids.size() && !improved; ++i1){
        if (!toP[i1]) continue;
        for (size_t i2=0; i2<ids.size(); ++i2){
          if (toP[i2]) continue;
          long long w1 = A[ids[i1]], w2 = A[ids[i2]];
          long double cur = fabsl((long double)x - x_goal);
          long double nxt = fabsl((long double)(x - w1 + w2) - x_goal);
          if (nxt + 1e-9L < cur){
            toP[i1]=0; toP[i2]=1; x = x - w1 + w2; improved = true; break;
          }
        }
      }
    }

    // 成果を評価
    long long newSp = fixedP + x;
    long long newSq = fixedQ + (Tmov - x);
    long long before = llabs(S[P]-B[P]) + llabs(S[Q]-B[Q]);
    long long after  = llabs(newSp-B[P]) + llabs(newSq-B[Q]);
    long long dE = after - before;

    if (dE <= 0 || rng_double() < expl(-(long double)dE / T)) {
      // 反映
      for (size_t t=0;t<ids.size();++t){
        int i = ids[t];
        int prev = X[i];
        if (toP[t]) {
          if (prev==q) { S[Q]-=A[i]; S[P]+=A[i]; X[i]=p; }
        } else {
          if (prev==p) { S[P]-=A[i]; S[Q]+=A[i]; X[i]=q; }
        }
      }
      E += dE;
      if (E < bestE){ bestE=E; bestX=X; bestS=S; }
      return true;
    }
    return false;
  };

  // ===== 近傍: 3グループ再分配 =====
  auto try_rebalance3 = [&](int p, int q, int r, long double T)->bool{
    if (p==q || q==r || p==r) return false;
    int P=p-1, Q=q-1, Rr=r-1;

    // 可動カードのみ（i>=M）で p/q/r に属するもの
    vector<int> ids; ids.reserve(96);
    long long movP=0, movQ=0, movR=0;
    for (int i=M;i<N;++i){
      if (X[i]==p){ ids.push_back(i); movP += A[i]; }
      else if (X[i]==q){ ids.push_back(i); movQ += A[i]; }
      else if (X[i]==r){ ids.push_back(i); movR += A[i]; }
    }
    if (ids.size() <= 1) return false;

    sort(ids.begin(), ids.end(), [&](int i, int j){ return A[i] > A[j]; });
    const int LIMIT = 150;
    if ((int)ids.size() > LIMIT) ids.resize(LIMIT);

    long long fixedP = S[P] - movP;
    long long fixedQ = S[Q] - movQ;
    long long fixedR = S[Rr]- movR;

    // 各山の目標（可動部分に期待する値）
    long long tgtP = B[P] - fixedP;
    long long tgtQ = B[Q] - fixedQ;
    long long tgtR = B[Rr]- fixedR;

    // 現在の可動部分の割当を 0/1/2（P/Q/R）で持つ
    vector<unsigned char> asg(ids.size(), 0);
    long long sumP=0, sumQ=0, sumR=0;

    auto gain_if = [&](int idx, int to)->long double{
      // idx のカードを pile to に置いたときの局所改善量（負なら改善）
      long long w = A[ids[idx]];
      long double cur =
        fabsl((long double)sumP - (long double)tgtP) +
        fabsl((long double)sumQ - (long double)tgtQ) +
        fabsl((long double)sumR - (long double)tgtR);
      long long nP=sumP, nQ=sumQ, nR=sumR;
      if (to==0) nP+=w; else if (to==1) nQ+=w; else nR+=w;
      long double nxt =
        fabsl((long double)nP - (long double)tgtP) +
        fabsl((long double)nQ - (long double)tgtQ) +
        fabsl((long double)nR - (long double)tgtR);
      return nxt - cur;
    };

    // 大きい順に置き場所を選ぶ（3択の中で最も改善する先）
    for (size_t t=0; t<ids.size(); ++t){
      long double gP = fabsl((long double)(sumP + A[ids[t]]) - (long double)tgtP)
                     - fabsl((long double)sumP - (long double)tgtP);
      long double gQ = fabsl((long double)(sumQ + A[ids[t]]) - (long double)tgtQ)
                     - fabsl((long double)sumQ - (long double)tgtQ);
      long double gR = fabsl((long double)(sumR + A[ids[t]]) - (long double)tgtR)
                     - fabsl((long double)sumR - (long double)tgtR);
      if (gP <= gQ && gP <= gR){ asg[t]=0; sumP += A[ids[t]]; }
      else if (gQ <= gP && gQ <= gR){ asg[t]=1; sumQ += A[ids[t]]; }
      else { asg[t]=2; sumR += A[ids[t]]; }
    }

    // 局所改善: 片移動 & 1-1 swap（少しだけ）
    int loops = 2;
    while (loops--){
      bool any=false;
      for (size_t t=0; t<ids.size(); ++t){
        int cur = asg[t];
        long double bestGain = 0.0L; int bestTo = cur;
        for (int to=0; to<3; ++to){
          if (to==cur) continue;
          long long w = A[ids[t]];
          // 現在値
          long double curLoss =
            fabsl((long double)sumP - (long double)tgtP) +
            fabsl((long double)sumQ - (long double)tgtQ) +
            fabsl((long double)sumR - (long double)tgtR);
          // 移した後
          long long nP=sumP, nQ=sumQ, nR=sumR;
          if (cur==0) nP-=w; else if (cur==1) nQ-=w; else nR-=w;
          if (to==0) nP+=w; else if (to==1) nQ+=w; else nR+=w;
          long double nxtLoss =
            fabsl((long double)nP - (long double)tgtP) +
            fabsl((long double)nQ - (long double)tgtQ) +
            fabsl((long double)nR - (long double)tgtR);
          long double gain = nxtLoss - curLoss;
          if (gain < bestGain){ bestGain = gain; bestTo = to; }
        }
        if (bestTo != cur){
          long long w = A[ids[t]];
          if (cur==0) sumP-=w; else if (cur==1) sumQ-=w; else sumR-=w;
          if (bestTo==0) sumP+=w; else if (bestTo==1) sumQ+=w; else sumR+=w;
          asg[t]=bestTo; any=true;
        }
      }
      // 1-1 swap ランダム試行
      for (int iter=0; iter<100; ++iter){
        int i = rng_u32() % (uint32_t)ids.size();
        int j = rng_u32() % (uint32_t)ids.size();
        if (i==j) continue;
        if (asg[i]==asg[j]) continue;
        int ai=asg[i], aj=asg[j];
        long long wi=A[ids[i]], wj=A[ids[j]];
        long double curLoss =
          fabsl((long double)sumP - (long double)tgtP) +
          fabsl((long double)sumQ - (long double)tgtQ) +
          fabsl((long double)sumR - (long double)tgtR);
        long long nP=sumP, nQ=sumQ, nR=sumR;
        auto sub = [&](int who, long long w){ if (who==0) nP-=w; else if (who==1) nQ-=w; else nR-=w; };
        auto add = [&](int who, long long w){ if (who==0) nP+=w; else if (who==1) nQ+=w; else nR+=w; };
        sub(ai, wi); sub(aj, wj);
        add(aj, wi); add(ai, wj);
        long double nxtLoss =
          fabsl((long double)nP - (long double)tgtP) +
          fabsl((long double)nQ - (long double)tgtQ) +
          fabsl((long double)nR - (long double)tgtR);
        if (nxtLoss + 1e-9L < curLoss){
          // accept swap
          sumP=nP; sumQ=nQ; sumR=nR;
          swap(asg[i], asg[j]);
          any=true;
        }
      }
      if (!any) break;
    }

    long long newSp = fixedP + sumP;
    long long newSq = fixedQ + sumQ;
    long long newSr = fixedR + sumR;
    long long before = llabs(S[P]-B[P]) + llabs(S[Q]-B[Q]) + llabs(S[Rr]-B[Rr]);
    long long after  = llabs(newSp-B[P]) + llabs(newSq-B[Q]) + llabs(newSr-B[Rr]);
    long long dE = after - before;

    if (dE <= 0 || rng_double() < expl(-(long double)dE / T)) {
      // 反映
      for (size_t t=0;t<ids.size();++t){
        int i = ids[t];
        int cur = X[i];
        int to  = (asg[t]==0? p : (asg[t]==1? q : r));
        if (cur == to) continue;
        long long w = A[i];
        if (cur==p) { S[P]-=w; }
        else if (cur==q) { S[Q]-=w; }
        else if (cur==r) { S[Rr]-=w; }
        if (to==p) { S[P]+=w; }
        else if (to==q) { S[Q]+=w; }
        else { S[Rr]+=w; }
        X[i]=to;
      }
      E += dE;
      if (E < bestE){ bestE=E; bestX=X; bestS=S; }
      return true;
    }
    return false;
  };

  // ===== SA parameters =====
  const double SA_MS = 1950.0;
  auto t0 = chrono::high_resolution_clock::now();
  auto elapsed_ms = [&](){
    auto now = chrono::high_resolution_clock::now();
    return (double)chrono::duration_cast<chrono::milliseconds>(now - t0).count();
  };
  long long medA = A[min(N-1, max(0,N/2))];
  long double T0 = 1e10L;
  long double T1 = 1e2L;

  auto pick_deficit_bucket = [&](int k)->int{
    int best=-1; long long bd = LLONG_MIN;
    for (int t=0;t<k;++t){
      int j = rng_int(0, M-1);
      long long d = B[j]-S[j];
      if (d>bd){ bd=d; best=j; }
    }
    if (best<0) best = rng_int(0, M-1);
    return best;
  };

  vector<int> idxs;
  idxs.reserve(max(0,N-M));
  for (int i=M;i<N;++i) idxs.push_back(i);

  // ===== SA main loop =====
  while (elapsed_ms() < SA_MS) {
    long double p = elapsed_ms()/SA_MS; if (p>1) p=1;
    long double Temp = expl( logl(T0)*(1-p) + logl(T1)*p );

    int op = rng_int(0, 99);
    if (op < 60) {
      // move / add / remove
      int i = (idxs.empty()? rng_int(0,N-1) : idxs[rng_u32() % (uint32_t)idxs.size()]);
      int cur = X[i];
      int nxt;
      if (rng_u32()%3==0) {
        nxt = 0;
      } else if (rng_u32()%3){
        nxt = pick_deficit_bucket(4)+1;
      } else {
        nxt = rng_int(0, M);
      }
      if (nxt == cur) continue;
      int from = (cur==0? -1 : cur-1);
      int to   = (nxt==0? -1 : nxt-1);
      long long dE = d_move(from, to, A[i]);
      if (dE <= 0 || rng_double() < expl(-(long double)dE / Temp)) {
        if (from>=0) S[from]-=A[i];
        if (to>=0) S[to]+=A[i];
        X[i]=nxt; E+=dE;
        if (E < bestE){ bestE=E; bestX=X; bestS=S; }
      }
    } else if (op < 85) {
      // 2グループ再分配
      int p1 = rng_int(1, M);
      int p2 = rng_int(1, M);
      if (p1==p2) p2 = (p1%M)+1;
      (void)try_rebalance2(p1, p2, Temp);
    } else if (op < 95) {
      // 3グループ再分配
      int p1 = rng_int(1, M);
      int p2 = rng_int(1, M);
      int p3 = rng_int(1, M);
      if (p2==p1) p2 = (p2%M)+1;
      if (p3==p1 || p3==p2) p3 = (p3%M)+1;
      (void)try_rebalance3(p1, p2, p3, Temp);
    } else {
      // swap
      if (N-M >= 2) {
        int i = idxs[rng_u32() % (uint32_t)idxs.size()];
        int j = idxs[rng_u32() % (uint32_t)idxs.size()];
        if (i==j) continue;
        if (X[i]==0 && X[j]==0) continue;
        long long dE = d_swap(i,j);
        if (dE <= 0 || rng_double() < expl(-(long double)dE / Temp)) {
          int ai = X[i]-1, aj = X[j]-1;
          long long a=A[i], b=A[j];
          if (ai>=0) S[ai] = S[ai]-a+b;
          if (aj>=0) S[aj] = S[aj]-b+a;
          swap(X[i], X[j]);
          E += dE;
          if (E < bestE){ bestE=E; bestX=X; bestS=S; }
        }
      }
    }
  }

  // 最良解へ戻す
  X = move(bestX);

  // ===== 出力 X =====
  for (int i=0;i<N;++i){ if (i) cout << ' '; cout << X[i]; }
  cout << '\n' << flush;

  return 0;
}
