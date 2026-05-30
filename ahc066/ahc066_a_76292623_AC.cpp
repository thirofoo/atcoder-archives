/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc066/submissions/76292623
 * Submitted at: 2026-05-31 02:16:58
 * Problem URL: https://atcoder.jp/contests/ahc066/tasks/ahc066_a
 * Result: AC
 * Execution Time: 1854 ms
 */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,omit-frame-pointer,inline,unroll-all-loops,no-stack-protector")
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const double TIME_LIMIT_MS = 2000.0;
const double MARGIN_MS = 150.0;
const int N_SOLVE = 5;
const double PH_MACRO =  3.0;
const double PH_ORDER =  1.0;
const int MACRO_MIN_LEN = 3, MACRO_MAX_LEN = 40;
const double MACRO_T0 = 40.0, MACRO_T1 = 0.5;
const double ORDER_T0 = 20.0, ORDER_T1 = 0.2;

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

vector<int> move_tbl;

string g_macro;
vector<int> macroF;
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

vector<int> nbr3;  // nbr3[s*3 + {0,1,2}] = L / R / F neighbour state (F = s itself if blocked)

void build_move_table() {
  move_tbl.assign(N * N * 4, 0);
  rep(cell, N * N) rep(dir, 4) move_tbl[cell * 4 + dir] = moved_cell_raw(cell, dir);
  int Vn = N * N * 4;
  nbr3.assign(Vn * 3, 0);
  rep(s, Vn) {
    int dir = s & 3, base = s - dir;
    nbr3[s * 3 + 0] = base + ((dir + 3) & 3);  // L
    nbr3[s * 3 + 1] = base + ((dir + 1) & 3);  // R
    nbr3[s * 3 + 2] = move_tbl[s] * 4 + dir;   // F (self if blocked)
  }
}

inline int moved_cell(int cell, int dir) { return move_tbl[cell * 4 + dir]; }

vector<int> bseen, bq;  // reused BFS buffers (stamp marks visited, so no V*V reset)
int bstamp = 0;

void build_required_paths() {
  V = N * N * 4;
  if ((int)dist_all.size() != V) {  // allocate once, reuse across all calls
    dist_all.assign(V, vector<Cost>(V, {INF, INF}));
    parent_state.assign(V, vector<int>(V, -1));
    parent_op.assign(V, vector<char>(V, 0));
    bseen.assign(V, 0);
    bq.assign(V, 0);
  }

  vector<int> sources;
  vector<char> seen(V, 0);
  auto add_cell_sources = [&](int cell) {
    rep(d, 4) {
      int s = state_id(cell, d);
      if (!seen[s]) { seen[s] = 1; sources.push_back(s); }
    }
  };
  add_cell_sources(0);
  rep(i, M) {
    add_cell_sources(cell_id(ball[i]));
    add_cell_sources(cell_id(basket[i]));
  }

  const char opc[4] = {'L', 'R', 'F', 'P'};
  for (int src : sources) {
    Cost *dist = dist_all[src].data();
    int *par = parent_state[src].data();
    char *pop = parent_op[src].data();
    ++bstamp;
    bseen[src] = bstamp;
    dist[src] = {0, 0};
    int head = 0, tail = 0;
    bq[tail++] = src;
    while (head < tail) {
      int cur = bq[head++];
      Cost cc = dist[cur];
      const int *nb = &nbr3[cur * 3];
      int outs[4] = {nb[0], nb[1], nb[2], macroLen > 0 ? macroF[cur] : cur};
      int cnt = macroLen > 0 ? 4 : 3;
      rep(i, cnt) {
        int nxt = outs[i];
        if (bseen[nxt] == bstamp) continue;
        bseen[nxt] = bstamp;
        dist[nxt] = {cc.ops + 1, cc.turns + (i == 3 ? macroLen : 1)};
        par[nxt] = cur;
        pop[nxt] = opc[i];
        bq[tail++] = nxt;
      }
    }
  }
}

Cost move_cost(int from_cell, int from_dir, int to_cell, int to_dir) {
  return dist_all[state_id(from_cell, from_dir)][state_id(to_cell, to_dir)];
}

int CK;
vector<int64_t> cpacked;
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

void optimize_order(vector<int> &order, const Timer &timer, double end_ms) {
  Cost cur = eval_fast(order);
  Cost best = cur;
  vector<int> best_order = order, cand;
  const double start_ms = timer.ms();
  const double start_temp = ORDER_T0;
  const double end_temp = ORDER_T1;

  double now = start_ms;
  double temp = start_temp;
  uint32_t iter = 0;
  while (true) {
    if ((iter++ & 255) == 0) {
      now = timer.ms();
      if (now >= end_ms) break;
      double progress = (now - start_ms) / max(1.0, end_ms - start_ms);
      temp = start_temp * pow(end_temp / start_temp, progress);
    }

    cand = order;
    int type = rnd() % 4;
    if (type == 0) {  // swap two jobs
      int i = rnd() % M, j = rnd() % M;
      if (i == j) continue;
      swap(cand[i], cand[j]);
    } else if (type == 1) {  // move one job
      int i = rnd() % M, j = rnd() % M;
      if (i == j) continue;
      int x = cand[i];
      cand.erase(cand.begin() + i);
      if (j > i) j--;
      cand.insert(cand.begin() + j, x);
    } else if (type == 2) {  // reverse a segment
      int i = rnd() % M, j = rnd() % M;
      if (i == j) continue;
      if (i > j) swap(i, j);
      reverse(cand.begin() + i, cand.begin() + j + 1);
    } else {  // Or-opt: move a short contiguous block
      int len = 2 + rnd() % 2;  // 2 or 3
      if (M - len < 2) continue;
      int i = rnd() % (M - len + 1), j = rnd() % (M - len + 1);
      if (i == j) continue;
      int blk[3];
      rep(t, len) blk[t] = cand[i + t];
      cand.erase(cand.begin() + i, cand.begin() + i + len);
      cand.insert(cand.begin() + j, blk, blk + len);
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
}

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
  vector<int> rel;
  vector<int> bI, kI;
  int sI = 0;
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

  vector<int> distB, stampB, qB;
  int curStamp = 0;

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
        int nd = distB[s] + 1;
        const int *nb = &nbr3[s * 3];
        int outs[4] = {nb[0], nb[1], nb[2], useMacro ? macroF[s] : s};
        int cnt = useMacro ? 4 : 3;
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

string macro_search(const Timer &timer, double search_start, double search_end) {
  MacroSearch ms;
  ms.init();
  long long base = ms.tour(ms.allpairs(false));

  const char *OPS = "FRL";
  auto randMacro = [&](int len) {
    string s; rep(i, len) s += OPS[rnd() % 3]; return s;
  };

  string bestM = "";
  long long bestS = base;  // no-macro proxy baseline
  string cur = randMacro(8 + rnd() % 16);
  long long curScore = ms.scoreMacro(cur);
  if (curScore < bestS) { bestS = curScore; bestM = cur; }

  const double T0 = MACRO_T0, T1 = MACRO_T1;
  while (timer.ms() < search_end) {
    string cand = cur;
    int t = rnd() % 4;
    if (cand.empty()) t = 1;
    if (t == 0 && cand.size() > 3) cand[rnd() % cand.size()] = OPS[rnd() % 3];
    else if (t == 1) cand += OPS[rnd() % 3];
    else if (t == 2 && cand.size() > 3) cand.pop_back();
    else { int p = rnd() % (cand.size() + 1); cand.insert(cand.begin() + p, OPS[rnd() % 3]); }
    cand = canon_turns(cand);
    if ((int)cand.size() < MACRO_MIN_LEN || (int)cand.size() > MACRO_MAX_LEN) continue;
    long long sc = ms.scoreMacro(cand);
    if (sc < bestS) { bestS = sc; bestM = cand; }
    double prog = (timer.ms() - search_start) / max(1.0, search_end - search_start);
    double temp = T0 * pow(T1 / T0, prog);
    double d = (double)(sc - curScore);
    if (d <= 0 || exp(-d / temp) > rand01()) { cur = cand; curScore = sc; }
  }

  return bestM;
}

string solve_with_macro(const string &m, const Timer &timer, double end_ms, vector<int> &order) {
  g_macro = canon_turns(m);
  build_macro_f();
  build_required_paths();
  build_compact_costs();
  if (order.empty()) order = greedy_order();  // else warm-start from the carried order
  optimize_order(order, timer, end_ms);
  string raw = build_raw_answer(order);

  string ans;
  if (macroLen > 0 && raw.find('P') != string::npos) {

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
          execNonP += 1;
        }
      }
    }
    int numP = ps.size();
    for (auto &p : ps) { p.direct = direct_path(p.sb, p.sa); p.dl = p.direct.size(); }
    long long exec = execNonP + (long long)macroLen * numP;

    vector<char> repl(numP, 0);
    if (exec > (long long)T) {
      vector<int> ord(numP);
      iota(ord.begin(), ord.end(), 0);
      auto eff = [&](int i) {
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
      if (exec > (long long)T)
        for (int i = 0; i < numP; i++) repl[i] = 1;
    }

    int firstKeep = -1;
    rep(i, numP) if (!repl[i]) { firstKeep = i; break; }

    ans.reserve(raw.size() + macroLen + 2);
    int pj = 0;
    rep(i, (int)raw.size()) {
      if (pj < numP && ps[pj].pos == i) {
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
  return ans;
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

  const double L = (TIME_LIMIT_MS - MARGIN_MS) / N_SOLVE;
  const double sum = PH_MACRO + PH_ORDER;
  string best;
  vector<int> order;  // carried across passes: each pass warm-starts order SA from it
  rep(p, N_SOLVE) {
    double ws = p * L;
    double m_end = ws + L * (PH_MACRO / sum);  // macro search; order SA fills the rest
    double we = (p + 1) * L;
    string m = macro_search(timer, ws, m_end);
    string a = solve_with_macro(m, timer, we, order);
    if (best.empty() || a.size() < best.size()) best = a;
  }

  for (char op : best) cout << op << '\n';
  return 0;
}

