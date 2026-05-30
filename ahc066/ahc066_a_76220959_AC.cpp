/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc066/submissions/76220959
 * Submitted at: 2026-05-30 19:21:12
 * Problem URL: https://atcoder.jp/contests/ahc066/tasks/ahc066_a
 * Result: AC
 * Execution Time: 1832 ms
 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// Tunable parameters
const double TIME_LIMIT_MS = 1900.0;
const double SA_END_MS = 1500.0;
const double FINAL_HC_END_MS = 1600.0;
const double COMPRESS_DEADLINE_MS = 1850.0;  // hard cap so macro compression never causes TLE
const int MACRO_SEARCH_MAX_LEN = 80;
const int MACRO_SEARCH_MIN_LEN = 3;
const int MACRO_ROUNDS = 5;

struct Timer {
  chrono::steady_clock::time_point st = chrono::steady_clock::now();
  double ms() const {
    return chrono::duration<double, milli>(chrono::steady_clock::now() - st).count();
  }
};

Timer *g_timer = nullptr;  // set in main; used by the compression deadline guard

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

  using Node = pair<pair<int, int>, int>;
  for (int src : sources) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist_all[src][src] = {0, 0};
    pq.push({{0, 0}, src});

    while (!pq.empty()) {
      auto [key, cur] = pq.top();
      pq.pop();
      Cost cc{key.first, key.second};
      if (dist_all[src][cur].ops != cc.ops || dist_all[src][cur].turns != cc.turns) continue;

      int dir = cur % 4;
      int cell = cell_of(cur);
      int r = cell / N, c = cell % N;
      array<pair<int, char>, 3> nxts;
      int cnt = 0;
      nxts[cnt++] = {state_id(r, c, (dir + 3) % 4), 'L'};
      nxts[cnt++] = {state_id(r, c, (dir + 1) % 4), 'R'};
      if (can_move(cell, dir)) {
        int nc = moved_cell(cell, dir);
        nxts[cnt++] = {state_id(nc, dir), 'F'};
      }

      rep(i, cnt) {
        auto [nxt, op] = nxts[i];
        Cost nc{cc.ops + 1, cc.turns + (op != 'F')};
        if (better_cost(nc, dist_all[src][nxt])) {
          dist_all[src][nxt] = nc;
          parent_state[src][nxt] = cur;
          parent_op[src][nxt] = op;
          pq.push({{nc.ops, nc.turns}, nxt});
        }
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

void optimize_order(vector<int> &order, const Timer &timer) {
  Cost cur = eval_fast(order);
  Cost best = cur;
  vector<int> best_order = order, cand;
  const double start_ms = timer.ms();
  const double start_temp = 80.0;
  const double end_temp = 0.2;

  double now = start_ms;
  double temp = start_temp;
  uint32_t iter = 0;
  while (true) {
    if ((iter++ & 255) == 0) {
      now = timer.ms();
      if (now >= SA_END_MS) break;
      double progress = (now - start_ms) / max(1.0, SA_END_MS - start_ms);
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
    if ((hc_iter++ & 255) == 0 && timer.ms() >= FINAL_HC_END_MS) break;
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

bool macro_char(char c) {
  return c == 'F' || c == 'L' || c == 'R' || c == 'S';
}

struct Snapshot {
  int cell = 0;
  int dir = 1;
  int hold = -1;
  vector<short> pos;
};

int snapshot_floor_ball(const Snapshot &s) {
  rep(k, M) {
    if (s.pos[k] == s.cell) return k;
  }
  return -1;
}

uint64_t splitmix64(uint64_t x) {
  x += 0x9e3779b97f4a7c15ULL;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
  x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
  return x ^ (x >> 31);
}

uint64_t snapshot_hash(const Snapshot &s) {
  uint64_t h = splitmix64((uint64_t)s.cell * 131 + s.dir * 17 + (s.hold + 2));
  rep(k, (int)s.pos.size()) {
    h ^= splitmix64((uint64_t)(k + 1) * 1009 + (uint64_t)(s.pos[k] + 2) * 9176);
  }
  return h;
}

void apply_snapshot_op(Snapshot &s, char op) {
  if (op == 'F') {
    s.cell = moved_cell(s.cell, s.dir);
  } else if (op == 'R') {
    s.dir = (s.dir + 1) % 4;
  } else if (op == 'L') {
    s.dir = (s.dir + 3) % 4;
  } else if (op == 'S') {
    int f = snapshot_floor_ball(s);
    if (s.hold == -1 && f != -1) {
      s.hold = f;
      s.pos[f] = -1;
    } else if (s.hold != -1 && f == -1) {
      s.pos[s.hold] = s.cell;
      s.hold = -1;
    } else if (s.hold != -1 && f != -1) {
      int put = s.hold;
      s.pos[put] = s.cell;
      s.hold = f;
      s.pos[f] = -1;
    }
  }
}

vector<Snapshot> simulate_raw_snapshots(const string &raw) {
  vector<Snapshot> snap(raw.size() + 1);
  Snapshot cur;
  cur.pos.resize(M);
  rep(k, M) cur.pos[k] = cell_id(ball[k]);
  snap[0] = cur;
  rep(i, (int)raw.size()) {
    apply_snapshot_op(cur, raw[i]);
    snap[i + 1] = cur;
  }
  return snap;
}

bool move_macro_char(char c) {
  return c == 'F' || c == 'L' || c == 'R';
}

pair<int, int> apply_move_pattern(int cell, int dir, const string &pat) {
  for (char op : pat) {
    if (op == 'F') {
      cell = moved_cell(cell, dir);
    } else if (op == 'R') {
      dir = (dir + 1) % 4;
    } else if (op == 'L') {
      dir = (dir + 3) % 4;
    }
  }
  return {cell, dir};
}

string compress_one_round_exact(const string &raw, int start_pos, int &next_pos) {
  struct Candidate {
    int gain = 0;
    int len = 0;
    string pat;
    vector<int> pos;
  } best;

  int n = raw.size();
  for (int len = MACRO_SEARCH_MIN_LEN; len <= min(MACRO_SEARCH_MAX_LEN, n - start_pos); len++) {
    unordered_map<string, vector<int>> mp;
    mp.reserve(n);
    for (int p = start_pos; p + len <= n; p++) {
      bool ok = true;
      rep(i, len) {
        if (!macro_char(raw[p + i])) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      mp[raw.substr(p, len)].push_back(p);
    }

    for (auto &kv : mp) {
      vector<int> selected;
      int last_end = -1;
      for (int p : kv.second) {
        if (p >= last_end) {
          selected.push_back(p);
          last_end = p + len;
        }
      }
      int cnt = selected.size();
      if (cnt < 2) continue;
      int gain = cnt * len - (len + 2 + (cnt - 1));
      if (gain > best.gain) best = {gain, len, kv.first, selected};
    }
  }

  if (best.gain <= 0) {
    next_pos = n;
    return raw.substr(start_pos);
  }

  int first = best.pos[0];
  int last_end = best.pos.back() + best.len;
  vector<int> repl(n + 1, -1);
  rep(i, (int)best.pos.size()) repl[best.pos[i]] = i;

  string out = raw.substr(start_pos, first - start_pos);
  for (int i = first; i < last_end;) {
    if (repl[i] != -1) {
      if (repl[i] == 0) {
        out += 'M';
        out += best.pat;
        out += 'M';
      } else {
        out += 'P';
      }
      i += best.len;
    } else {
      out += raw[i++];
    }
  }
  next_pos = last_end;
  return out;
}

string compress_one_round_by_state(const string &raw, int start_pos, int &next_pos) {
  struct Candidate {
    int gain = 0;
    int len = 0;
    string pat;
    vector<int> start;
    vector<int> end;
  } best;

  int n = raw.size();

  // Precompute the whole trajectory once. snapshot_hash factors as
  //   splitmix64(cell,dir,hold) XOR (XOR over balls of splitmix64(pos))
  // so a move-only macro (which never touches balls/hold) lets us recompute the
  // resulting hash in O(1) from the stored (posx, hold) without copying the
  // position vector. hsh[i] == snapshot_hash(snap[i]) exactly.
  vector<int> scell(n + 1), sdir(n + 1), shold(n + 1);
  vector<uint64_t> posx(n + 1), hsh(n + 1);
  {
    auto term = [](int k, int p) {
      return splitmix64((uint64_t)(k + 1) * 1009 + (uint64_t)(p + 2) * 9176);
    };
    vector<int> pos(M);
    uint64_t px = 0;
    rep(k, M) {
      pos[k] = cell_id(ball[k]);
      px ^= term(k, pos[k]);
    }
    int cell = 0, dir = 1, hold = -1;
    auto store = [&](int idx) {
      scell[idx] = cell;
      sdir[idx] = dir;
      shold[idx] = hold;
      posx[idx] = px;
      hsh[idx] = splitmix64((uint64_t)cell * 131 + dir * 17 + (hold + 2)) ^ px;
    };
    store(0);
    rep(i, n) {
      char c = raw[i];
      if (c == 'F') {
        cell = move_tbl[cell * 4 + dir];
      } else if (c == 'R') {
        dir = (dir + 1) % 4;
      } else if (c == 'L') {
        dir = (dir + 3) % 4;
      } else if (c == 'S') {
        int f = -1;
        rep(k, M) if (pos[k] == cell) {
          f = k;
          break;
        }
        if (hold == -1 && f != -1) {
          px ^= term(f, pos[f]); pos[f] = -1; px ^= term(f, -1);
          hold = f;
        } else if (hold != -1 && f == -1) {
          px ^= term(hold, -1); pos[hold] = cell; px ^= term(hold, cell);
          hold = -1;
        } else if (hold != -1 && f != -1) {
          int put = hold;
          px ^= term(put, -1); pos[put] = cell; px ^= term(put, cell);
          px ^= term(f, pos[f]); pos[f] = -1; px ^= term(f, -1);
          hold = f;
        }
      }
      store(i + 1);
    }
  }

  // run_end[p] = first index >= p whose char is not a move char (end of the maximal
  // move-only run starting at p). Lets a macro extend only over move characters.
  vector<int> run_end(n + 1);
  run_end[n] = n;
  for (int p = n - 1; p >= 0; p--) run_end[p] = move_macro_char(raw[p]) ? run_end[p + 1] : p;

  // cc[p]/cd[p] hold the facing state after applying the current pattern (raw[first..
  // first+len)) starting from snap[p]. Maintained incrementally as len grows by one:
  // appending one op to a left-to-right macro is just applying that op to the end state.
  vector<int> cc(n), cd(n);
  vector<int> starts, ends;

  for (int first = start_pos; first < n; first++) {
    if (!move_macro_char(raw[first])) continue;
    int maxlen = min(MACRO_SEARCH_MAX_LEN, run_end[first] - first);
    if (maxlen < MACRO_SEARCH_MIN_LEN) continue;

    for (int p = first + 1; p < n; p++) {
      cc[p] = scell[p];
      cd[p] = sdir[p];
    }

    for (int len = 1; len <= maxlen; len++) {
      char op = raw[first + len - 1];
      if (op == 'F') {
        for (int p = first + len; p < n; p++) cc[p] = move_tbl[cc[p] * 4 + cd[p]];
      } else if (op == 'R') {
        for (int p = first + len; p < n; p++) cd[p] = (cd[p] + 1) % 4;
      } else {
        for (int p = first + len; p < n; p++) cd[p] = (cd[p] + 3) % 4;
      }
      if (len < MACRO_SEARCH_MIN_LEN) continue;

      starts.assign(1, first);
      ends.assign(1, first + len);
      int last_end = first + len;

      for (int p = first + len; p < n; p++) {
        if (p < last_end) continue;
        uint64_t after_hash =
            splitmix64((uint64_t)cc[p] * 131 + cd[p] * 17 + (shold[p] + 2)) ^ posx[p];

        int best_end = -1;
        int limit = min(n, p + len);
        for (int e = p + 1; e <= limit; e++) {
          if (hsh[e] == after_hash) {
            best_end = e;
            break;
          }
          if (!move_macro_char(raw[e - 1])) break;
        }
        if (best_end != -1) {
          starts.push_back(p);
          ends.push_back(best_end);
          last_end = best_end;
        }
      }

      int cnt = starts.size();
      if (cnt < 2) continue;
      int original = 0;
      rep(i, cnt) original += ends[i] - starts[i];
      int compressed = len + 2 + (cnt - 1);
      int gain = original - compressed;
      if (gain > best.gain) best = {gain, len, raw.substr(first, len), starts, ends};
    }

    if (g_timer && g_timer->ms() > COMPRESS_DEADLINE_MS) break;
  }

  if (best.gain <= 0) {
    next_pos = raw.size();
    return raw.substr(start_pos);
  }

  int first = best.start[0];
  int last_end = best.end.back();
  vector<int> idx_at(raw.size() + 1, -1);
  rep(i, (int)best.start.size()) idx_at[best.start[i]] = i;

  string out = raw.substr(start_pos, first - start_pos);
  for (int i = first; i < last_end;) {
    int idx = idx_at[i];
    if (idx != -1) {
      if (idx == 0) {
        out += 'M';
        out += best.pat;
        out += 'M';
      } else {
        out += 'P';
      }
      i = best.end[idx];
    } else {
      out += raw[i++];
    }
  }
  next_pos = last_end;
  return out;
}

string compress_one_round(const string &raw, int start_pos, int &next_pos) {
  int exact_next = raw.size();
  string exact = compress_one_round_exact(raw, start_pos, exact_next);
  int exact_gain = ((int)raw.size() - start_pos) - (int)exact.size();

  int state_next = raw.size();
  string state_based = compress_one_round_by_state(raw, start_pos, state_next);
  int state_gain = ((int)raw.size() - start_pos) - (int)state_based.size();

  if (state_gain > exact_gain) {
    next_pos = state_next;
    return state_based;
  }
  next_pos = exact_next;
  return exact;
}

string compress_macros(const string &raw) {
  string out;
  int pos = 0;
  rep(_, MACRO_ROUNDS) {
    if (pos >= (int)raw.size()) break;
    if (g_timer && g_timer->ms() > COMPRESS_DEADLINE_MS) break;
    int next_pos = raw.size();
    string part = compress_one_round(raw, pos, next_pos);
    out += part;
    pos = next_pos;
    if (next_pos == (int)raw.size()) break;
  }
  if (pos < (int)raw.size()) out += raw.substr(pos);
  return out;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Timer timer;
  g_timer = &timer;
  cin >> N >> M >> T;
  vw.resize(N);
  hw.resize(N - 1);
  rep(i, N) cin >> vw[i];
  rep(i, N - 1) cin >> hw[i];

  ball.resize(M);
  basket.resize(M);
  rep(i, M) cin >> ball[i].r >> ball[i].c >> basket[i].r >> basket[i].c;

  build_move_table();
  build_required_paths();
  build_compact_costs();
  vector<int> order = greedy_order();
  optimize_order(order, timer);

  string raw = build_raw_answer(order);
  string ans = compress_macros(raw);
  for (char op : ans) cout << op << '\n';
  return 0;
}
