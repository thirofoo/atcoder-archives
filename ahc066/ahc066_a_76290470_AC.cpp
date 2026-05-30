/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc066/submissions/76290470
 * Submitted at: 2026-05-31 00:01:33
 * Problem URL: https://atcoder.jp/contests/ahc066/tasks/ahc066_a
 * Result: AC
 * Execution Time: 1724 ms
 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const double MACRO_SEARCH_END_MS = 550.0;
const double RERANK_END_MS = 1100.0;
const double SA_END_MS = 1600.0;
const double FINAL_HC_END_MS = 1720.0;
const int MACRO_MIN_LEN = 3;
const int MACRO_MAX_LEN = 40;

struct Timer {
  chrono::steady_clock::time_point st = chrono::steady_clock::now();
  double ms() const {
    return chrono::duration<double, milli>(chrono::steady_clock::now() - st).count();
  }
};

struct Pos {
  int r, c;
};

struct Cost {
  int ops, turns;
};

bool better_cost(const Cost &a, const Cost &b) {
  if (a.ops != b.ops) return a.ops < b.ops;
  return a.turns < b.turns;
}

Cost add_cost(Cost a, Cost b) {
  return {a.ops + b.ops, a.turns + b.turns};
}

const int INF = 1e9;
const int DR[4] = {-1, 0, 1, 0};
const int DC[4] = {0, 1, 0, -1};

int N, M, T, V;
vector<string> vw, hw;
vector<Pos> ball, basket;
vector<vector<Cost>> dist_all;
vector<vector<int>> parent_state;
vector<vector<char>> parent_op;

uint32_t rng_state = 123456789;
uint32_t rnd() {
  rng_state ^= rng_state << 13;
  rng_state ^= rng_state >> 17;
  rng_state ^= rng_state << 5;
  return rng_state;
}

double rand01() {
  return (rnd() + 0.5) / 4294967296.0;
}

int cell_id(Pos p) {
  return p.r * N + p.c;
}

int state_id(int cell, int dir) {
  return cell * 4 + dir;
}

int state_id(int r, int c, int dir) {
  return (r * N + c) * 4 + dir;
}

int cell_of(int state) {
  return state / 4;
}

bool can_move(int cell, int dir) {
  int r = cell / N, c = cell % N;
  int nr = r + DR[dir], nc = c + DC[dir];
  if (nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
  if (dir == 0) return hw[r - 1][c] == '0';
  if (dir == 1) return vw[r][c] == '0';
  if (dir == 2) return hw[r][c] == '0';
  return vw[r][c - 1] == '0';
}

vector<int> move_tbl;  // move_tbl[cell * 4 + dir] -> destination cell (same cell if blocked)

// The single registered macro (string of F/L/R) and its state-transition f.
string g_macro;
vector<int> macroF;  // macroF[state] = state after replaying the macro once
int macroLen = 0;

void build_macro_f() {
  macroLen = g_macro.size();
  macroF.assign(N * N * 4, 0);
  rep(cell, N * N) rep(dir, 4) {
    int cc = cell, dd = dir;
    for (char op : g_macro) {
      if (op == 'F') cc = move_tbl[cc * 4 + dd];
      else if (op == 'R') dd = (dd + 1) % 4;
      else dd = (dd + 3) % 4;
    }
    macroF[cell * 4 + dir] = cc * 4 + dd;
  }
}

int moved_cell_raw(int cell, int dir) {
  if (!can_move(cell, dir)) return cell;
  int r = cell / N, c = cell % N;
  return (r + DR[dir]) * N + (c + DC[dir]);
}

void build_move_table() {
  move_tbl.assign(N * N * 4, 0);
  rep(cell, N * N) rep(dir, 4) move_tbl[cell * 4 + dir] = moved_cell_raw(cell, dir);
}

inline int moved_cell(int cell, int dir) { return move_tbl[cell * 4 + dir]; }

void build_required_paths() {
  V = N * N * 4;
  dist_all.assign(V, vector<Cost>(V, {INF, INF}));
  parent_state.assign(V, vector<int>(V, -1));
  parent_op.assign(V, vector<char>(V, 0));

  vector<int> sources;
  vector<char> seen(V, 0);
  auto add_cell_sources = [&](int cell) {
    rep(d, 4) {
      int s = state_id(cell, d);
      if (!seen[s]) {
        seen[s] = 1;
        sources.push_back(s);
      }
    }
  };

  add_cell_sources(0);
  rep(i, M) {
    add_cell_sources(cell_id(ball[i]));
    add_cell_sources(cell_id(basket[i]));
  }

  // Every edge costs exactly 1 output char, so shortest output length = BFS depth
  // (no Dijkstra needed). turns = executed base ops along that first path (info for
  // the T-aware tiebreak; not separately minimized).
  vector<int> q(V);
  for (int src : sources) {
    Cost *dist = dist_all[src].data();
    int *par = parent_state[src].data();
    char *pop = parent_op[src].data();
    dist[src] = {0, 0};
    int head = 0, tail = 0;
    q[tail++] = src;
    while (head < tail) {
      int cur = q[head++];
      Cost cc = dist[cur];
      int dir = cur & 3, cell = cur >> 2;
      int nxts[4]; char ops[4];
      int cnt = 0;
      nxts[cnt] = (cell << 2) + ((dir + 3) & 3); ops[cnt++] = 'L';
      nxts[cnt] = (cell << 2) + ((dir + 1) & 3); ops[cnt++] = 'R';
      if (can_move(cell, dir)) { nxts[cnt] = (moved_cell(cell, dir) << 2) + dir; ops[cnt++] = 'F'; }
      if (macroLen > 0) { nxts[cnt] = macroF[cur]; ops[cnt++] = 'P'; }
      rep(i, cnt) {
        int nxt = nxts[i];
        if (dist[nxt].ops != INF) continue;  // first visit = shortest output
        dist[nxt] = {cc.ops + 1, cc.turns + (ops[i] == 'P' ? macroLen : 1)};
        par[nxt] = cur;
        pop[nxt] = ops[i];
        q[tail++] = nxt;
      }
    }
  }
}

Cost move_cost(int from_cell, int from_dir, int to_cell, int to_dir) {
  return dist_all[state_id(from_cell, from_dir)][state_id(to_cell, to_dir)];
}

// ---- Compact, cache-friendly cost table over the only cells the optimizer touches
// (start cell, every ball cell, every basket cell). Packs (ops<<32 | turns) so a
// single int64 compare reproduces better_cost() exactly.
int CK;                       // number of relevant cells
vector<int64_t> cpacked;      // [(a*CK + b) * 16 + da*4 + db] -> packed cost
vector<int> ball_idx, basket_idx;
int start_idx;
const int64_t PACK_BIG = (int64_t)INF << 32;

inline int64_t pack_cost(Cost c) { return ((int64_t)c.ops << 32) | (uint32_t)c.turns; }

void build_compact_costs() {
  vector<int> cells;
  vector<int> cidx(N * N, -1);
  auto add = [&](int cell) {
    if (cidx[cell] == -1) {
      cidx[cell] = cells.size();
      cells.push_back(cell);
    }
  };
  add(0);
  rep(i, M) {
    add(cell_id(ball[i]));
    add(cell_id(basket[i]));
  }
  CK = cells.size();
  start_idx = cidx[0];
  ball_idx.resize(M);
  basket_idx.resize(M);
  rep(i, M) {
    ball_idx[i] = cidx[cell_id(ball[i])];
    basket_idx[i] = cidx[cell_id(basket[i])];
  }
  cpacked.assign((size_t)CK * CK * 16, PACK_BIG);
  rep(a, CK) rep(b, CK) {
    int ca = cells[a], cb = cells[b];
    size_t base = ((size_t)(a * CK + b)) * 16;
    rep(da, 4) rep(db, 4) {
      cpacked[base + da * 4 + db] = pack_cost(dist_all[state_id(ca, da)][state_id(cb, db)]);
    }
  }
}

// Fast cost-only evaluation used inside the SA/HC hot loop. Two-phase DP over the
// 4 facing directions; identical result to evaluate_order(order, false).cost.
Cost eval_fast(const vector<int> &order) {
  int64_t dp[4];
  rep(d, 4) dp[d] = PACK_BIG;
  dp[1] = 0;
  int prev = start_idx;
  const int64_t add2 = (int64_t)2 << 32;

  rep(i, M) {
    int k = order[i];
    int bi = ball_idx[k], ci = basket_idx[k];
    const int64_t *pb = &cpacked[((size_t)(prev * CK + bi)) * 16];
    int64_t toball[4] = {PACK_BIG, PACK_BIG, PACK_BIG, PACK_BIG};
    rep(pd, 4) {
      int64_t base = dp[pd];
      if (base >= PACK_BIG) continue;
      const int64_t *row = pb + pd * 4;
      rep(bd, 4) {
        int64_t v = base + row[bd];
        if (v < toball[bd]) toball[bd] = v;
      }
    }
    const int64_t *bc = &cpacked[((size_t)(bi * CK + ci)) * 16];
    int64_t ndp[4] = {PACK_BIG, PACK_BIG, PACK_BIG, PACK_BIG};
    rep(bd, 4) {
      int64_t base = toball[bd];
      if (base >= PACK_BIG) continue;
      const int64_t *row = bc + bd * 4;
      rep(cd, 4) {
        int64_t v = base + row[cd];
        if (v < ndp[cd]) ndp[cd] = v;
      }
    }
    rep(d, 4) {
      dp[d] = ndp[d] < PACK_BIG ? ndp[d] + add2 : PACK_BIG;
    }
    prev = ci;
  }

  int64_t best = dp[0];
  rep(d, 4) if (dp[d] < best) best = dp[d];
  return {(int)(best >> 32), (int)(best & 0xffffffffLL)};
}

struct EvalResult {
  Cost cost;
  vector<array<int, 2>> dirs;
};

EvalResult evaluate_order(const vector<int> &order, bool keep_dirs) {
  vector<Cost> dp(4, {INF, INF}), ndp(4, {INF, INF});
  vector<array<int, 4>> prev_dir(M), pickup_dir(M);

  int prev_cell = 0;
  dp[1] = {0, 0};

  rep(i, M) {
    fill(ndp.begin(), ndp.end(), Cost{INF, INF});
    int k = order[i];
    int bcell = cell_id(ball[k]);
    int ccell = cell_id(basket[k]);

    rep(pd, 4) {
      if (dp[pd].ops >= INF) continue;
      rep(bd, 4) rep(cd, 4) {
        Cost c = add_cost(dp[pd], move_cost(prev_cell, pd, bcell, bd));
        c = add_cost(c, move_cost(bcell, bd, ccell, cd));
        c.ops += 2;
        if (better_cost(c, ndp[cd])) {
          ndp[cd] = c;
          if (keep_dirs) {
            prev_dir[i][cd] = pd;
            pickup_dir[i][cd] = bd;
          }
        }
      }
    }

    dp.swap(ndp);
    prev_cell = ccell;
  }

  int best_dir = 0;
  rep(d, 4) {
    if (better_cost(dp[d], dp[best_dir])) best_dir = d;
  }

  vector<array<int, 2>> dirs;
  if (keep_dirs) {
    dirs.assign(M, {-1, -1});
    int cd = best_dir;
    for (int i = M - 1; i >= 0; i--) {
      dirs[i] = {pickup_dir[i][cd], cd};
      cd = prev_dir[i][cd];
    }
  }
  return {dp[best_dir], dirs};
}

string restore_path(int src, int dst) {
  string ops;
  for (int cur = dst; cur != src; cur = parent_state[src][cur]) {
    ops.push_back(parent_op[src][cur]);
  }
  reverse(ops.begin(), ops.end());
  return ops;
}

string build_raw_answer(const vector<int> &order) {
  EvalResult ev = evaluate_order(order, true);
  string ans;
  int prev_cell = 0, prev_dir = 1;

  rep(i, M) {
    int k = order[i];
    int bcell = cell_id(ball[k]);
    int ccell = cell_id(basket[k]);
    int bd = ev.dirs[i][0];
    int cd = ev.dirs[i][1];

    ans += restore_path(state_id(prev_cell, prev_dir), state_id(bcell, bd));
    ans += 'S';
    ans += restore_path(state_id(bcell, bd), state_id(ccell, cd));
    ans += 'S';

    prev_cell = ccell;
    prev_dir = cd;
  }

  return ans;
}

vector<int> greedy_order() {
  vector<int> order;
  vector<char> used(M, 0);
  int cur_cell = 0, cur_dir = 1;

  rep(_, M) {
    int best_k = -1;
    int best_cd = 0;
    Cost best{INF, INF};
    rep(k, M) {
      if (used[k]) continue;
      int bcell = cell_id(ball[k]);
      int ccell = cell_id(basket[k]);
      rep(bd, 4) rep(cd, 4) {
        Cost c = add_cost(move_cost(cur_cell, cur_dir, bcell, bd), move_cost(bcell, bd, ccell, cd));
        c.ops += 2;
        if (better_cost(c, best)) {
          best = c;
          best_k = k;
          best_cd = cd;
        }
      }
    }
    used[best_k] = 1;
    order.push_back(best_k);
    cur_cell = cell_id(basket[best_k]);
    cur_dir = best_cd;
  }
  return order;
}

double score_value(Cost c) {
  return c.ops + c.turns * 0.001;
}

void optimize_order(vector<int> &order, const Timer &timer, double sa_end, double hc_end) {
  Cost cur = eval_fast(order);
  Cost best = cur;
  vector<int> best_order = order, cand;
  const double start_ms = timer.ms();
  const double start_temp = 20.0;
  const double end_temp = 0.2;

  double now = start_ms;
  double temp = start_temp;
  uint32_t iter = 0;
  while (true) {
    if ((iter++ & 255) == 0) {
      now = timer.ms();
      if (now >= sa_end) break;
      double progress = (now - start_ms) / max(1.0, sa_end - start_ms);
      temp = start_temp * pow(end_temp / start_temp, progress);
    }

    cand = order;
    int type = rnd() % 3;
    int i = rnd() % M;
    int j = rnd() % M;
    if (i == j) continue;

    if (type == 0) {
      swap(cand[i], cand[j]);
    } else if (type == 1) {
      int x = cand[i];
      cand.erase(cand.begin() + i);
      if (j > i) j--;
      cand.insert(cand.begin() + j, x);
    } else {
      if (i > j) swap(i, j);
      reverse(cand.begin() + i, cand.begin() + j + 1);
    }

    Cost nxt = eval_fast(cand);
    double diff = score_value(nxt) - score_value(cur);
    if (diff < 0 || exp(-diff / temp) > rand01()) {
      order.swap(cand);
      cur = nxt;
      if (better_cost(cur, best)) {
        best = cur;
        best_order = order;
      }
    }
  }

  order.swap(best_order);

  cur = eval_fast(order);
  uint32_t hc_iter = 0;
  while (true) {
    if ((hc_iter++ & 255) == 0 && timer.ms() >= hc_end) break;
    cand = order;
    int type = rnd() % 3;
    int i = rnd() % M;
    int j = rnd() % M;
    if (i == j) continue;
    if (type == 0) {
      swap(cand[i], cand[j]);
    } else if (type == 1) {
      int x = cand[i];
      cand.erase(cand.begin() + i);
      if (j > i) j--;
      cand.insert(cand.begin() + j, x);
    } else {
      if (i > j) swap(i, j);
      reverse(cand.begin() + i, cand.begin() + j + 1);
    }
    Cost nxt = eval_fast(cand);
    if (better_cost(nxt, cur)) {
      order.swap(cand);
      cur = nxt;
    }
  }
}

// Collapse every maximal run of consecutive turns (L/R, nothing between them) to the
// minimal turn string with the same net rotation: net%4 = 0->"" 1->R 2->RR 3->L.
// Always valid (intermediate facings don't matter without an F/S/P between) and it
// also shrinks the macro body, lowering both define cost and executed ops.
string canon_turns(const string &s) {
  string out;
  out.reserve(s.size());
  int n = s.size();
  for (int i = 0; i < n;) {
    char c = s[i];
    if (c == 'R' || c == 'L') {
      int net = 0, j = i;
      while (j < n && (s[j] == 'R' || s[j] == 'L')) { net += (s[j] == 'R') ? 1 : 3; j++; }
      net &= 3;
      if (net == 1) out += 'R';
      else if (net == 2) out += "RR";
      else if (net == 3) out += 'L';
      i = j;
    } else {
      out += c;
      i++;
    }
  }
  return out;
}

// Shortest macro-free path (L/R/F only) between two states, as an op string.
string direct_path(int sb, int sa) {
  if (sb == sa) return "";
  int Vn = N * N * 4;
  vector<int> par(Vn, -2);
  vector<char> pc(Vn, 0);
  deque<int> q;
  par[sb] = -1;
  q.push_back(sb);
  while (!q.empty()) {
    int s = q.front();
    q.pop_front();
    if (s == sa) break;
    int cell = s / 4, dir = s % 4;
    pair<int, char> nb[3] = {{cell * 4 + ((dir + 3) % 4), 'L'},
                             {cell * 4 + ((dir + 1) % 4), 'R'},
                             {move_tbl[cell * 4 + dir] * 4 + dir, 'F'}};
    for (auto [t, op] : nb) {
      if (par[t] == -2) { par[t] = s; pc[t] = op; q.push_back(t); }
    }
  }
  string r;
  for (int s = sa; s != sb; s = par[s]) r.push_back(pc[s]);
  reverse(r.begin(), r.end());
  return r;
}


struct MacroSearch {
  vector<int> rel;            // relevant cells
  vector<int> bI, kI;         // ball/basket -> index into rel
  int sI = 0;                 // start cell index
  int V = 0;

  void init() {
    V = N * N * 4;
    map<int, int> idx;
    auto add = [&](int cell) {
      if (!idx.count(cell)) { idx[cell] = rel.size(); rel.push_back(cell); }
    };
    add(0);
    rep(i, M) { add(cell_id(ball[i])); add(cell_id(basket[i])); }
    sI = idx[0];
    bI.resize(M); kI.resize(M);
    rep(i, M) { bI[i] = idx[cell_id(ball[i])]; kI[i] = idx[cell_id(basket[i])]; }
  }

  // reusable BFS buffers (stamp avoids re-filling 'dist' each of the R sources)
  vector<int> distB, stampB, qB;
  int curStamp = 0;

  // all-pairs facing-free distances among relevant cells using L/R/F + (optional) P
  vector<vector<int>> allpairs(bool useMacro) {
    int R = rel.size();
    if ((int)distB.size() != V) { distB.assign(V, 0); stampB.assign(V, 0); qB.assign(V, 0); curStamp = 0; }
    vector<vector<int>> D(R, vector<int>(R, INF));
    rep(ai, R) {
      int A = rel[ai];
      ++curStamp;
      int head = 0, tail = 0;
      rep(d, 4) { int s = A * 4 + d; stampB[s] = curStamp; distB[s] = 0; qB[tail++] = s; }
      while (head < tail) {
        int s = qB[head++];
        int dir = s & 3, nd = distB[s] + 1;
        int outs[4]; int cnt = 0;
        outs[cnt++] = (s - dir) + ((dir + 3) & 3);
        outs[cnt++] = (s - dir) + ((dir + 1) & 3);
        outs[cnt++] = move_tbl[s] * 4 + dir;
        if (useMacro) outs[cnt++] = macroF[s];
        rep(k, cnt) {
          int t = outs[k];
          if (stampB[t] != curStamp) { stampB[t] = curStamp; distB[t] = nd; qB[tail++] = t; }
        }
      }
      rep(bi, R) {
        int B = rel[bi] * 4, best = INF;
        rep(d, 4) if (stampB[B + d] == curStamp) best = min(best, distB[B + d]);
        D[ai][bi] = best;
      }
    }
    return D;
  }

  long long tour(const vector<vector<int>> &D) {
    vector<char> used(M, 0);
    int cur = sI; long long tot = 0;
    rep(_, M) {
      int bk = -1; long long best = LLONG_MAX;
      rep(k, M) {
        if (used[k]) continue;
        long long c = (long long)D[cur][bI[k]] + D[bI[k]][kI[k]];
        if (c < best) { best = c; bk = k; }
      }
      used[bk] = 1; tot += best; cur = kI[bk];
    }
    return tot + 2 * M;
  }

  long long scoreMacro(const string &mac) {
    g_macro = mac;
    build_macro_f();
    long long t = tour(allpairs(true));
    return t + (mac.empty() ? 0 : (long long)mac.size() + 2);
  }
};

void macro_search(const Timer &timer) {
  MacroSearch ms;
  ms.init();
  long long base = ms.tour(ms.allpairs(false));

  const char *OPS = "FRL";
  auto randMacro = [&](int len) {
    string s; rep(i, len) s += OPS[rnd() % 3]; return s;
  };

  // Keep the best K distinct macros under the (cheap, facing-free) proxy, then
  // re-rank them with the real pipeline — the proxy is only loosely correlated
  // with the true objective, so the final pick must use real distances.
  const int K = 12;
  vector<pair<long long, string>> topk;  // (proxy score, macro), ascending
  auto consider = [&](long long sc, const string &m) {
    for (auto &pr : topk) if (pr.second == m) return;
    if ((int)topk.size() < K) topk.push_back({sc, m});
    else if (sc < topk.back().first) topk.back() = {sc, m};
    else return;
    sort(topk.begin(), topk.end());
  };

  string cur = randMacro(8 + rnd() % 16);
  long long curScore = ms.scoreMacro(cur);
  consider(curScore, cur);

  // simulated annealing over macro strings (explores past local optima; the
  // diverse states it visits feed top-K, which the real re-rank then judges).
  const double T0 = 40.0, T1 = 0.5;
  while (timer.ms() < MACRO_SEARCH_END_MS) {
    string cand = cur;
    int t = rnd() % 4;
    if (cand.empty()) t = 1;
    if (t == 0 && cand.size() > 3) cand[rnd() % cand.size()] = OPS[rnd() % 3];
    else if (t == 1) cand += OPS[rnd() % 3];
    else if (t == 2 && cand.size() > 3) cand.pop_back();
    else { int p = rnd() % (cand.size() + 1); cand.insert(cand.begin() + p, OPS[rnd() % 3]); }
    cand = canon_turns(cand);  // search only over canonical macros (no RL/LR/RRR ...)
    if ((int)cand.size() < MACRO_MIN_LEN || (int)cand.size() > MACRO_MAX_LEN) continue;
    long long sc = ms.scoreMacro(cand);
    consider(sc, cand);
    double prog = timer.ms() / MACRO_SEARCH_END_MS;
    double temp = T0 * pow(T1 / T0, prog);
    double d = (double)(sc - curScore);
    if (d <= 0 || exp(-d / temp) > rand01()) { cur = cand; curScore = sc; }
  }

  // Re-rank with the real objective: output length of the greedy order under the
  // macro-augmented shortest paths (+ one-time define cost). Pick the true best.
  auto realCost = [&](const string &m) -> long long {
    g_macro = m;
    build_macro_f();
    build_required_paths();
    build_compact_costs();
    vector<int> o = greedy_order();
    long long c = (long long)eval_fast(o).ops;
    return c + (m.empty() ? 0 : (long long)m.size() + 1);
  };
  string bestReal = "";
  long long bestRealCost = realCost("");  // no-macro baseline
  for (auto &pr : topk) {
    if (timer.ms() > RERANK_END_MS) break;
    long long rc = realCost(pr.second);
    if (rc < bestRealCost) { bestRealCost = rc; bestReal = pr.second; }
  }
  g_macro = bestReal;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Timer timer;
  cin >> N >> M >> T;
  vw.resize(N);
  hw.resize(N - 1);
  rep(i, N) cin >> vw[i];
  rep(i, N - 1) cin >> hw[i];

  ball.resize(M);
  basket.resize(M);
  rep(i, M) cin >> ball[i].r >> ball[i].c >> basket[i].r >> basket[i].c;

  build_move_table();

  // ---- Solution B: macro-driven tour (gets the bulk of the time budget) ----
  macro_search(timer);  // runs until MACRO_SEARCH_END_MS, sets g_macro
  g_macro = canon_turns(g_macro);  // drop redundant turns in the macro body
  build_macro_f();
  build_required_paths();
  build_compact_costs();
  vector<int> order = greedy_order();
  optimize_order(order, timer, SA_END_MS, FINAL_HC_END_MS);
  string raw = build_raw_answer(order);  // sequence over L/R/F/P/S

  string ans;
  if (macroLen > 0 && raw.find('P') != string::npos) {
    // Walk the tour, recording each P's (before,after) state, and the executed
    // base-op count of everything else.
    struct PInfo { int pos, sb, sa, dl; string direct; };
    vector<PInfo> ps;
    long long execNonP = 0;
    {
      int cell = 0, dir = 1;
      rep(i, (int)raw.size()) {
        char ch = raw[i];
        int s = cell * 4 + dir;
        if (ch == 'P') {
          int sa = macroF[s];
          ps.push_back({i, s, sa, 0, ""});
          cell = sa / 4; dir = sa % 4;
        } else {
          if (ch == 'F') cell = move_tbl[s];
          else if (ch == 'R') dir = (dir + 1) % 4;
          else if (ch == 'L') dir = (dir + 3) % 4;
          execNonP += 1;  // F/L/R/S each execute one base op
        }
      }
    }
    int numP = ps.size();
    for (auto &p : ps) { p.direct = direct_path(p.sb, p.sa); p.dl = p.direct.size(); }
    long long exec = execNonP + (long long)macroLen * numP;

    // T enforcement: replace the most wasteful P's (high executed, cheap to expand)
    // with their direct paths until the execution budget is met.
    vector<char> repl(numP, 0);
    if (exec > (long long)T) {
      vector<int> ord(numP);
      iota(ord.begin(), ord.end(), 0);
      auto eff = [&](int i) {  // executed saved per extra output char
        int saved = macroLen - ps[i].dl;
        int cost = max(1, ps[i].dl - 1);
        return (double)saved / cost;
      };
      sort(ord.begin(), ord.end(), [&](int a, int b) { return eff(a) > eff(b); });
      for (int i : ord) {
        if (exec <= (long long)T) break;
        int saved = macroLen - ps[i].dl;
        if (saved <= 0) continue;
        repl[i] = 1;
        exec -= saved;
      }
      if (exec > (long long)T)  // still over: drop the macro entirely (plain tour)
        for (int i = 0; i < numP; i++) repl[i] = 1;
    }

    int firstKeep = -1;
    rep(i, numP) if (!repl[i]) { firstKeep = i; break; }

    ans.reserve(raw.size() + macroLen + 2);
    int pj = 0;
    rep(i, (int)raw.size()) {
      if (pj < numP && ps[pj].pos == i) {  // this char is a P
        if (repl[pj]) ans += ps[pj].direct;
        else if (pj == firstKeep) { ans += 'M'; ans += g_macro; ans += 'M'; }
        else ans += 'P';
        pj++;
      } else {
        ans += raw[i];
      }
    }
  } else {
    ans = raw;
  }

  ans = canon_turns(ans);
  for (char op : ans) cout << op << '\n';
  return 0;
}
