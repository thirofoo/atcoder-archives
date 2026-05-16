/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc065/submissions/75823232
 * Submitted at: 2026-05-16 16:58:13
 * Problem URL: https://atcoder.jp/contests/ahc065/tasks/ahc065_a
 * Result: AC
 * Execution Time: 1585 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Solver {
  static constexpr int N = 20;
  static constexpr int NN = N * N;
  static constexpr int LOOP_COUNT = 20;
  static constexpr int LOOP_LEN = 40;
  static constexpr int EXIT_R = 0;
  static constexpr int EXIT_C = 10;
  static constexpr int EXIT_CELL = EXIT_R * N + EXIT_C;
  static constexpr int LIMIT_T = 10000;
  static constexpr int BEAM_WIDTH = 100;
  static constexpr int EXTRA_TRANSITIONS = 5;
  static constexpr int EXTRA_DEPTH = 2;
  static constexpr int EVAL_LOOKAHEAD = 400;
  static constexpr long long OP_PENALTY = 2000000LL;
  static constexpr long long TARGET_WEIGHT = 1000000000000LL;
  static constexpr int INF = 1 << 30;

  struct Op {
    int8_t m = -1;
    int8_t dir = 0;
  };

  struct BeamState {
    array<int16_t, NN> board{};
    array<int16_t, NN> cell_of{};
    long long eval = 0;
    int16_t target_cell = -1;
    int16_t parent = -1;
    int16_t depth = 0;
    int8_t last_m = -1;
    int8_t last_dir = 0;
    bool done = false;
  };

  struct TraceNode {
    int16_t parent = -1;
    int8_t m = -1;
    int8_t dir = 0;
  };

  struct Candidate {
    int cost = INT_MAX;
    int col_loop = -1;
    int row_loop = -1;
    int move_col = 0;
    int move_row = 0;
  };

  int n = N;
  array<int16_t, NN> grid{};
  array<int16_t, NN> pos{};
  array<array<int16_t, LOOP_LEN>, LOOP_COUNT> loop_cells{};
  array<array<int16_t, NN>, LOOP_COUNT> idx_in_loop{};
  array<array<int16_t, 4>, NN> target_next{};
  array<int, NN> target_dist{};
  array<long long, NN> active_weight{};
  vector<Op> answer;
  int next_box = 0;
  int active_start = 0;
  int active_end = NN;

  static int row_loop_id(int r) { return r >> 1; }
  static int col_loop_id(int c) { return 10 + (c >> 1); }
  static int dir_index(int dir) { return dir > 0; }

  static bool better_state(const BeamState &a, const BeamState &b) {
    if(a.eval != b.eval) return a.eval < b.eval;
    return a.depth < b.depth;
  }

  static int signed_delta(int len, int from, int to) {
    int plus = (to - from + len) % len;
    int minus = (from - to + len) % len;
    return (plus <= minus) ? plus : -minus;
  }

  void input() {
    cin >> n;
    pos.fill(-1);
    for(int r = 0; r < N; r++) {
      for(int c = 0; c < N; c++) {
        int v;
        cin >> v;
        int cell = r * N + c;
        grid[cell] = (int16_t)v;
        if(0 <= v && v < NN) pos[v] = (int16_t)cell;
      }
    }
  }

  int loop_index(int m, int r, int c) const {
    return idx_in_loop[m][r * N + c];
  }

  int loop_index_cell(int m, int cell) const {
    return idx_in_loop[m][cell];
  }

  void build_loops() {
    for(auto &x: idx_in_loop) x.fill(-1);

    int id = 0;
    for(int r = 0; r < N; r += 2, id++) {
      int k = 0;
      for(int c = 0; c < N; c++) loop_cells[id][k++] = (int16_t)(r * N + c);
      for(int c = N - 1; c >= 0; c--) loop_cells[id][k++] = (int16_t)((r + 1) * N + c);
    }

    for(int c = 0; c < N; c += 2, id++) {
      int k = 0;
      for(int r = 0; r < N; r++) loop_cells[id][k++] = (int16_t)(r * N + c);
      for(int r = N - 1; r >= 0; r--) loop_cells[id][k++] = (int16_t)(r * N + c + 1);
    }

    for(int m = 0; m < LOOP_COUNT; m++) {
      for(int i = 0; i < LOOP_LEN; i++) idx_in_loop[m][loop_cells[m][i]] = (int16_t)i;
    }

    build_target_graph();
  }

  void build_target_graph() {
    for(auto &a: target_next) a.fill(-1);

    for(int r = 0; r < N; r++) {
      for(int c = 0; c < N; c++) {
        int v = r * N + c;

        int rm = row_loop_id(r);
        int ri = loop_index(rm, r, c);
        for(int di = 0; di < 2; di++) {
          int dir = (di == 0 ? -1 : 1);
          int ni = (ri + dir + LOOP_LEN) % LOOP_LEN;
          target_next[v][di] = loop_cells[rm][ni];
        }

        int cm = col_loop_id(c);
        int ci = loop_index(cm, r, c);
        for(int di = 0; di < 2; di++) {
          int dir = (di == 0 ? -1 : 1);
          int ni = (ci + dir + LOOP_LEN) % LOOP_LEN;
          target_next[v][2 + di] = loop_cells[cm][ni];
        }
      }
    }

    target_dist.fill(INF);
    queue<int> q;
    target_dist[EXIT_CELL] = 0;
    q.push(EXIT_CELL);
    while(!q.empty()) {
      int v = q.front();
      q.pop();
      int nd = target_dist[v] + 1;
      for(int to: target_next[v]) {
        if(target_dist[to] > nd) {
          target_dist[to] = nd;
          q.push(to);
        }
      }
    }
  }

  void remove_if_ready() {
    while(next_box < NN && grid[EXIT_CELL] == next_box) {
      grid[EXIT_CELL] = -1;
      pos[next_box] = -1;
      next_box++;
    }
  }

  bool rotate_once(int m, int dir, bool record) {
    if(record && (int)answer.size() >= LIMIT_T) return false;

    array<int16_t, LOOP_LEN> vals{};
    for(int i = 0; i < LOOP_LEN; i++) vals[i] = grid[loop_cells[m][i]];

    if(dir > 0) {
      for(int i = 0; i < LOOP_LEN; i++) {
        int ni = (i + 1 == LOOP_LEN ? 0 : i + 1);
        int cell = loop_cells[m][ni];
        int v = vals[i];
        grid[cell] = (int16_t)v;
        if(v >= 0) pos[v] = (int16_t)cell;
      }
    } else {
      for(int i = 0; i < LOOP_LEN; i++) {
        int ni = (i == 0 ? LOOP_LEN - 1 : i - 1);
        int cell = loop_cells[m][ni];
        int v = vals[i];
        grid[cell] = (int16_t)v;
        if(v >= 0) pos[v] = (int16_t)cell;
      }
    }

    if(record) {
      answer.push_back({(int8_t)m, (int8_t)dir});
      remove_if_ready();
    }
    return true;
  }

  void prepare_weights(int start_box) {
    active_start = start_box;
    active_end = min(NN, start_box + EVAL_LOOKAHEAD);
    active_weight.fill(0);
    for(int b = active_start; b < active_end; b++) {
      if(b == active_start) {
        active_weight[b] = TARGET_WEIGHT;
      } else {
        long long x = NN - b;
        active_weight[b] = x * x * x * x;
      }
    }
  }

  long long eval_delta_rotate(const BeamState &st, int m, int dir) const {
    long long delta = 0;

    if(dir > 0) {
      for(int i = 0; i < LOOP_LEN; i++) {
        int old_cell = loop_cells[m][i];
        int new_cell = loop_cells[m][(i + 1 == LOOP_LEN ? 0 : i + 1)];
        int v = st.board[old_cell];
        if((unsigned)v < NN) {
          long long w = active_weight[v];
          if(w) delta += w * (long long)(target_dist[new_cell] - target_dist[old_cell]);
        }
      }
    } else {
      for(int i = 0; i < LOOP_LEN; i++) {
        int old_cell = loop_cells[m][i];
        int new_cell = loop_cells[m][(i == 0 ? LOOP_LEN - 1 : i - 1)];
        int v = st.board[old_cell];
        if((unsigned)v < NN) {
          long long w = active_weight[v];
          if(w) delta += w * (long long)(target_dist[new_cell] - target_dist[old_cell]);
        }
      }
    }

    return delta;
  }

  long long eval_after_rotate(const BeamState &st, int m, int dir) const {
    return st.eval + eval_delta_rotate(st, m, dir) + OP_PENALTY;
  }

  void rotate_state(BeamState &st, int m, int dir, int target) const {
    array<int16_t, LOOP_LEN> vals{};
    for(int i = 0; i < LOOP_LEN; i++) vals[i] = st.board[loop_cells[m][i]];

    st.eval += eval_delta_rotate(st, m, dir) + OP_PENALTY;

    if(dir > 0) {
      for(int i = 0; i < LOOP_LEN; i++) {
        int ni = (i + 1 == LOOP_LEN ? 0 : i + 1);
        int cell = loop_cells[m][ni];
        int v = vals[i];
        st.board[cell] = v;
        if(v >= 0) st.cell_of[v] = (int16_t)cell;
      }
    } else {
      for(int i = 0; i < LOOP_LEN; i++) {
        int ni = (i == 0 ? LOOP_LEN - 1 : i - 1);
        int cell = loop_cells[m][ni];
        int v = vals[i];
        st.board[cell] = v;
        if(v >= 0) st.cell_of[v] = (int16_t)cell;
      }
    }

    if(st.board[EXIT_CELL] == target) {
      st.board[EXIT_CELL] = -1;
      st.cell_of[target] = -1;
      st.target_cell = -1;
      st.done = true;
    } else {
      st.target_cell = st.cell_of[target];
      st.done = false;
    }

    st.last_m = (int8_t)m;
    st.last_dir = (int8_t)dir;
    st.depth++;
  }

  long long evaluate_initial(const BeamState &st, int start_box) const {
    long long value = 0;
    int end_box = min(NN, start_box + EVAL_LOOKAHEAD);

    for(int b = start_box; b < end_box; b++) {
      int cell = st.cell_of[b];
      if(cell == -1) continue;
      value += active_weight[b] * (long long)target_dist[cell];
    }

    return value;
  }

  BeamState current_beam_state(int target) const {
    BeamState st;
    st.cell_of.fill(-1);
    st.board = grid;

    for(int cell = 0; cell < NN; cell++) {
      int v = st.board[cell];
      if(v >= 0) st.cell_of[v] = (int16_t)cell;
    }

    st.target_cell = st.cell_of[target];
    st.depth = 0;
    st.eval = evaluate_initial(st, target);
    return st;
  }

  int shortest_ops_from_state(const BeamState &st, Op out[4]) const {
    int cell = st.target_cell;
    if(cell == -1) return 0;

    int r = cell / N;
    int c = cell % N;
    int cur = target_dist[cell];
    int cnt = 0;

    auto add_if_shorter = [&](int m, int dir) {
      int idx = loop_index_cell(m, cell);
      int ni = (idx + dir + LOOP_LEN) % LOOP_LEN;
      int to = loop_cells[m][ni];

      if(target_dist[to] == cur - 1) {
        for(int i = 0; i < cnt; i++) {
          if(out[i].m == m && out[i].dir == dir) return;
        }
        out[cnt++] = {(int8_t)m, (int8_t)dir};
      }
    };

    int rm = row_loop_id(r);
    int cm = col_loop_id(c);
    bool same_row_pair = (rm == row_loop_id(EXIT_R));
    bool same_col_pair = (cm == col_loop_id(EXIT_C));

    if(same_row_pair) {
      add_if_shorter(rm, -1);
      add_if_shorter(rm, 1);
    } else if(same_col_pair) {
      add_if_shorter(cm, -1);
      add_if_shorter(cm, 1);
    }

    if(cnt == 0) {
      add_if_shorter(rm, -1);
      add_if_shorter(rm, 1);
      add_if_shorter(cm, -1);
      add_if_shorter(cm, 1);
    }

    for(int i = 1; i < cnt; i++) {
      Op key = out[i];
      int j = i - 1;
      while(j >= 0 && (out[j].m > key.m || (out[j].m == key.m && out[j].dir > key.dir))) {
        out[j + 1] = out[j];
        j--;
      }
      out[j + 1] = key;
    }

    return cnt;
  }

  int transition_ops_from_state(const BeamState &st, Op out[16]) const {
    Op shortest[4];
    int cnt = shortest_ops_from_state(st, shortest);

    bool used[LOOP_COUNT][2] = {};
    for(int i = 0; i < cnt; i++) {
      out[i] = shortest[i];
      used[(int)shortest[i].m][dir_index(shortest[i].dir)] = true;
    }

    struct Extra {
      long long eval;
      Op op;
    } extras[LOOP_COUNT * 2];

    int ec = 0;
    for(int m = 0; m < LOOP_COUNT; m++) {
      for(int dir: {-1, 1}) {
        if(used[m][dir_index(dir)]) continue;
        extras[ec++] = {eval_after_rotate(st, m, dir), {(int8_t)m, (int8_t)dir}};
      }
    }

    auto cmp = [](const Extra &a, const Extra &b) {
      if(a.eval != b.eval) return a.eval < b.eval;
      if(a.op.m != b.op.m) return a.op.m < b.op.m;
      return a.op.dir < b.op.dir;
    };

    int take = min(EXTRA_TRANSITIONS, ec);
    if(ec > take) nth_element(extras, extras + take, extras + ec, cmp);
    sort(extras, extras + take, cmp);

    for(int i = 0; i < take; i++) out[cnt++] = extras[i].op;
    return cnt;
  }

  void prune_states(vector<BeamState> &states) const {
    if((int)states.size() > BEAM_WIDTH) {
      nth_element(states.begin(), states.begin() + BEAM_WIDTH, states.end(), better_state);
      states.resize(BEAM_WIDTH);
    }
    sort(states.begin(), states.end(), better_state);
  }

  vector<Op> beam_path_to_exit(int target) {
    prepare_weights(target);

    BeamState initial = current_beam_state(target);
    if(initial.target_cell == -1) return {};

    int depth_limit = target_dist[initial.target_cell] + EXTRA_DEPTH;
    vector<BeamState> beam;
    vector<BeamState> next_beam;
    vector<BeamState> finals;
    vector<vector<TraceNode>> trace_layers;

    beam.reserve(BEAM_WIDTH);
    next_beam.reserve(BEAM_WIDTH * (EXTRA_TRANSITIONS + 4));
    finals.reserve(BEAM_WIDTH * 2);
    trace_layers.reserve(depth_limit + 1);

    beam.push_back(initial);
    trace_layers.push_back(vector<TraceNode>{{-1, -1, 0}});

    for(int depth = 0; depth < depth_limit; depth++) {
      next_beam.clear();

      for(int parent_id = 0; parent_id < (int)beam.size(); parent_id++) {
        const BeamState &st = beam[parent_id];

        Op trans[16];
        int tc = transition_ops_from_state(st, trans);

        for(int i = 0; i < tc; i++) {
          BeamState ns = st;
          rotate_state(ns, trans[i].m, trans[i].dir, target);
          ns.parent = (int16_t)parent_id;

          if(ns.done) finals.push_back(std::move(ns));
          else next_beam.push_back(std::move(ns));
        }
      }

      prune_states(finals);
      prune_states(next_beam);

      vector<TraceNode> next_trace;
      next_trace.reserve(next_beam.size());
      for(const auto &st: next_beam) {
        next_trace.push_back({st.parent, st.last_m, st.last_dir});
      }
      trace_layers.push_back(std::move(next_trace));

      beam.swap(next_beam);
      if(beam.empty()) break;
    }

    if(!finals.empty()) {
      const BeamState &best = finals.front();

      vector<Op> path;
      path.reserve(best.depth);
      path.push_back({best.last_m, best.last_dir});

      int d = best.depth - 1;
      int p = best.parent;

      while(d > 0) {
        if(d >= (int)trace_layers.size() || p < 0 || p >= (int)trace_layers[d].size()) break;

        const TraceNode &node = trace_layers[d][p];
        path.push_back({node.m, node.dir});
        p = node.parent;
        d--;
      }

      reverse(path.begin(), path.end());
      return path;
    }

    Candidate cand = best_candidate(target);
    vector<Op> fallback;

    if(cand.col_loop < 0 || cand.row_loop < 0) return fallback;

    int dir = cand.move_col >= 0 ? 1 : -1;
    for(int i = 0; i < abs(cand.move_col); i++) {
      fallback.push_back({(int8_t)cand.col_loop, (int8_t)dir});
    }

    dir = cand.move_row >= 0 ? 1 : -1;
    for(int i = 0; i < abs(cand.move_row); i++) {
      fallback.push_back({(int8_t)cand.row_loop, (int8_t)dir});
    }

    return fallback;
  }

  bool apply_path(const vector<Op> &path) {
    for(const Op &op: path) {
      if(!rotate_once(op.m, op.dir, true)) return false;
    }
    return true;
  }

  Candidate best_candidate(int box) const {
    int start_cell = pos[box];

    Candidate best;
    if(start_cell == -1) return best;

    int c = start_cell % N;
    int cm = col_loop_id(c);
    int start_col_idx = loop_index_cell(cm, start_cell);

    for(int i = 0; i < LOOP_LEN; i++) {
      int via_cell = loop_cells[cm][i];
      int vr = via_cell / N;

      if(vr != 0 && vr != 1) continue;

      int move_col = signed_delta(LOOP_LEN, start_col_idx, i);
      int rm = row_loop_id(vr);
      int via_row_idx = loop_index_cell(rm, via_cell);
      int exit_row_idx = loop_index_cell(rm, EXIT_CELL);
      int move_row = signed_delta(LOOP_LEN, via_row_idx, exit_row_idx);
      int cost = abs(move_col) + abs(move_row);

      if(cost < best.cost) {
        best.cost = cost;
        best.col_loop = cm;
        best.row_loop = rm;
        best.move_col = move_col;
        best.move_row = move_row;
      }
    }

    return best;
  }

  void solve() {
    build_loops();
    remove_if_ready();

    while(next_box < NN && (int)answer.size() < LIMIT_T) {
      int target = next_box;

      vector<Op> path = beam_path_to_exit(target);
      if(path.empty()) break;

      if(!apply_path(path)) break;

      if(next_box == target) break;
    }
  }

  void output() const {
    cout << LOOP_COUNT << '\n';

    for(int m = 0; m < LOOP_COUNT; m++) {
      cout << LOOP_LEN;
      for(int i = 0; i < LOOP_LEN; i++) {
        int cell = loop_cells[m][i];
        cout << ' ' << cell / N << ' ' << cell % N;
      }
      cout << '\n';
    }

    cout << answer.size() << '\n';
    for(const Op &op: answer) {
      cout << (int)op.m << ' ' << (int)op.dir << '\n';
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solver solver;
  solver.input();
  solver.solve();
  solver.output();

  return 0;
}