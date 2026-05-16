/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc065/submissions/75828564
 * Submitted at: 2026-05-16 18:59:58
 * Problem URL: https://atcoder.jp/contests/ahc065/tasks/ahc065_a
 * Result: AC
 * Execution Time: 1810 ms
 */

# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
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

  static constexpr int BEAM_WIDTH = 250;
  static constexpr int EXTRA_TRANSITIONS = 15;
  static constexpr int EXTRA_DEPTH = 3;
  static constexpr int EVAL_LOOKAHEAD = 400;

  static constexpr long long OP_PENALTY = 0LL;
  static constexpr long long TARGET_WEIGHT = 200000000000LL;
  static constexpr int INF = 1 << 30;

  struct Op {
    int8_t m = -1;
    int8_t dir = 0;
  };

  struct TransCand {
    int8_t m = -1;
    int8_t dir = 0;
    long long eval = 0;
  };

  struct BeamState {
    array<int16_t, NN> board{};
    array<int16_t, NN> cell_of{};
    long long eval = 0;
    int16_t target_cell = -1;
    int16_t depth = 0;
  };

  struct TreeNode {
    int parent = -1;
    long long eval = 0;
    int16_t target_cell = -1;
    int16_t depth = 0;
    int8_t m = -1;
    int8_t dir = 0;
  };

  struct ChildCand {
    int parent = -1;
    long long eval = 0;
    int16_t target_cell = -1;
    int16_t depth = 0;
    int8_t m = -1;
    int8_t dir = 0;
    bool done = false;
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

  // Precomputed fast tables.
  array<array<Op, 4>, NN> shortest_ops_table{};
  array<int8_t, NN> shortest_ops_count{};
  array<array<array<int16_t, NN>, 2>, LOOP_COUNT> moved_cell{};
  array<array<array<int16_t, LOOP_LEN>, 2>, LOOP_COUNT> dist_delta{};

  array<long long, NN> active_weight{};
  vector<Op> answer;
  int next_box = 0;

  static int row_loop_id(int r) { return r >> 1; }
  static int col_loop_id(int c) { return 10 + (c >> 1); }
  static int dir_index(int dir) { return dir > 0; }

  static bool better_child(const ChildCand &a, const ChildCand &b) {
    if(a.eval != b.eval) return a.eval < b.eval;
    return a.depth < b.depth;
  }

  static bool better_trans(const TransCand &a, const TransCand &b) {
    if(a.eval != b.eval) return a.eval < b.eval;
    if(a.m != b.m) return a.m < b.m;
    return a.dir < b.dir;
  }

  static int signed_delta(int len, int from, int to) {
    int plus = (to - from + len) % len;
    int minus = (from - to + len) % len;
    return (plus <= minus) ? plus : -minus;
  }

  void input() {
    cin >> n;
    pos.fill(-1);
    answer.reserve(LIMIT_T);

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
    build_fast_tables();
  }

  void build_target_graph() {
    for(auto &a: target_next) a.fill(-1);

    for(int r = 0; r < N; r++) {
      for(int c = 0; c < N; c++) {
        int v = r * N + c;

        int rm = row_loop_id(r);
        int ri = loop_index(rm, r, c);
        target_next[v][0] = loop_cells[rm][(ri - 1 + LOOP_LEN) % LOOP_LEN];
        target_next[v][1] = loop_cells[rm][(ri + 1) % LOOP_LEN];

        int cm = col_loop_id(c);
        int ci = loop_index(cm, r, c);
        target_next[v][2] = loop_cells[cm][(ci - 1 + LOOP_LEN) % LOOP_LEN];
        target_next[v][3] = loop_cells[cm][(ci + 1) % LOOP_LEN];
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

  void build_fast_tables() {
    build_moved_cell_table();
    build_dist_delta_table();
    build_shortest_ops_table();
  }

  void build_moved_cell_table() {
    for(int m = 0; m < LOOP_COUNT; m++) {
      for(int di = 0; di < 2; di++) {
        for(int cell = 0; cell < NN; cell++) moved_cell[m][di][cell] = (int16_t)cell;
      }

      for(int i = 0; i < LOOP_LEN; i++) {
        int cell = loop_cells[m][i];
        moved_cell[m][0][cell] = loop_cells[m][(i - 1 + LOOP_LEN) % LOOP_LEN];
        moved_cell[m][1][cell] = loop_cells[m][(i + 1) % LOOP_LEN];
      }
    }
  }

  void build_dist_delta_table() {
    for(int m = 0; m < LOOP_COUNT; m++) {
      for(int i = 0; i < LOOP_LEN; i++) {
        int old_cell = loop_cells[m][i];
        int minus_cell = loop_cells[m][(i - 1 + LOOP_LEN) % LOOP_LEN];
        int plus_cell = loop_cells[m][(i + 1) % LOOP_LEN];
        dist_delta[m][0][i] = (int16_t)(target_dist[minus_cell] - target_dist[old_cell]);
        dist_delta[m][1][i] = (int16_t)(target_dist[plus_cell] - target_dist[old_cell]);
      }
    }
  }

  void build_shortest_ops_table() {
    shortest_ops_count.fill(0);

    for(int cell = 0; cell < NN; cell++) {
      if(target_dist[cell] == INF) continue;

      int r = cell / N;
      int c = cell % N;
      int cur = target_dist[cell];
      int cnt = 0;

      auto add_if_shorter = [&](int m, int dir) {
        int to = moved_cell[m][dir_index(dir)][cell];
        if(target_dist[to] == cur - 1) {
          for(int i = 0; i < cnt; i++) {
            if(shortest_ops_table[cell][i].m == m && shortest_ops_table[cell][i].dir == dir) return;
          }
          shortest_ops_table[cell][cnt++] = {(int8_t)m, (int8_t)dir};
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

      sort(shortest_ops_table[cell].begin(), shortest_ops_table[cell].begin() + cnt,
           [](const Op &a, const Op &b) {
             if(a.m != b.m) return a.m < b.m;
             return a.dir < b.dir;
           });

      shortest_ops_count[cell] = (int8_t)cnt;
    }
  }

  void remove_if_ready() {
    while(next_box < NN && grid[EXIT_CELL] == next_box) {
      grid[EXIT_CELL] = -1;
      pos[next_box] = -1;
      next_box++;
    }
  }

  template<class Board, class CellOf>
  inline void rotate_board_inplace(Board &board, CellOf &cell_of, int m, int dir) const {
    const auto &cells = loop_cells[m];

    if(dir > 0) {
      int last_cell = cells[LOOP_LEN - 1];
      int16_t tmp = board[last_cell];

      for(int i = LOOP_LEN - 1; i >= 1; i--) {
        int cell = cells[i];
        int16_t v = board[cells[i - 1]];
        board[cell] = v;
        if(v >= 0) cell_of[v] = (int16_t)cell;
      }

      int first_cell = cells[0];
      board[first_cell] = tmp;
      if(tmp >= 0) cell_of[tmp] = (int16_t)first_cell;
    } else {
      int first_cell = cells[0];
      int16_t tmp = board[first_cell];

      for(int i = 0; i + 1 < LOOP_LEN; i++) {
        int cell = cells[i];
        int16_t v = board[cells[i + 1]];
        board[cell] = v;
        if(v >= 0) cell_of[v] = (int16_t)cell;
      }

      int last_cell = cells[LOOP_LEN - 1];
      board[last_cell] = tmp;
      if(tmp >= 0) cell_of[tmp] = (int16_t)last_cell;
    }
  }

  bool rotate_once(int m, int dir, bool record) {
    if(record && (int)answer.size() >= LIMIT_T) return false;

    rotate_board_inplace(grid, pos, m, dir);

    if(record) {
      answer.push_back({(int8_t)m, (int8_t)dir});
      remove_if_ready();
    }
    return true;
  }

  void prepare_weights(int start_box) {
    active_weight.fill(0);
    int end = min(NN, start_box + EVAL_LOOKAHEAD);

    for(int b = start_box; b < end; b++) {
      if(b == start_box) {
        active_weight[b] = TARGET_WEIGHT;
      } else {
        long long x = NN - b;
        active_weight[b] = x * x * x * x;
      }
    }
  }

  inline long long eval_delta_rotate(const BeamState &st, int m, int dir) const {
    long long delta = 0;
    int di = dir_index(dir);
    const auto &cells = loop_cells[m];
    const auto &dd = dist_delta[m][di];

    for(int i = 0; i < LOOP_LEN; i++) {
      int v = st.board[cells[i]];
      if((unsigned)v < NN) {
        long long w = active_weight[v];
        if(w) delta += w * (long long)dd[i];
      }
    }

    return delta;
  }

  inline long long eval_after_rotate(const BeamState &st, int m, int dir) const {
    return st.eval + eval_delta_rotate(st, m, dir) + OP_PENALTY;
  }

  inline int16_t target_cell_after_rotate(const BeamState &st, int m, int dir) const {
    int cell = st.target_cell;
    if(cell < 0) return -1;
    return moved_cell[m][dir_index(dir)][cell];
  }

  long long evaluate_initial(const BeamState &st, int start_box) const {
    long long value = 0;
    int end = min(NN, start_box + EVAL_LOOKAHEAD);

    for(int b = start_box; b < end; b++) {
      int cell = st.cell_of[b];
      if(cell == -1) continue;
      value += active_weight[b] * (long long)target_dist[cell];
    }

    return value;
  }

  BeamState current_beam_state(int target) const {
    BeamState st;
    st.board = grid;
    st.cell_of = pos;
    st.target_cell = st.cell_of[target];
    st.depth = 0;
    st.eval = evaluate_initial(st, target);
    return st;
  }

  inline void apply_tree_node(BeamState &st, const vector<TreeNode> &nodes, int node_id) const {
    const TreeNode &nd = nodes[node_id];
    if(nd.parent < 0) return;

    rotate_board_inplace(st.board, st.cell_of, nd.m, nd.dir);
    st.eval = nd.eval;
    st.target_cell = nd.target_cell;
    st.depth = nd.depth;
  }

  inline void revert_tree_node(BeamState &st, const vector<TreeNode> &nodes, int node_id) const {
    const TreeNode &nd = nodes[node_id];
    if(nd.parent < 0) return;

    rotate_board_inplace(st.board, st.cell_of, nd.m, -nd.dir);

    const TreeNode &p = nodes[nd.parent];
    st.eval = p.eval;
    st.target_cell = p.target_cell;
    st.depth = p.depth;
  }

  inline void move_to_node(BeamState &st, const vector<TreeNode> &nodes, int &cur_node, int target_node) const {
    if(cur_node == target_node) return;

    int path[128];
    int pc = 0;

    int u = cur_node;
    int v = target_node;

    while(nodes[u].depth > nodes[v].depth) {
      revert_tree_node(st, nodes, u);
      u = nodes[u].parent;
    }

    while(nodes[v].depth > nodes[u].depth) {
      path[pc++] = v;
      v = nodes[v].parent;
    }

    while(u != v) {
      revert_tree_node(st, nodes, u);
      u = nodes[u].parent;

      path[pc++] = v;
      v = nodes[v].parent;
    }

    for(int i = pc - 1; i >= 0; i--) {
      apply_tree_node(st, nodes, path[i]);
    }

    cur_node = target_node;
  }

  inline int shortest_ops_from_state(const BeamState &st, Op out[4]) const {
    int cell = st.target_cell;
    if(cell == -1) return 0;

    int cnt = shortest_ops_count[cell];
    for(int i = 0; i < cnt; i++) out[i] = shortest_ops_table[cell][i];
    return cnt;
  }

  int transition_ops_from_state(const BeamState &st, TransCand out[16]) const {
    Op shortest[4];
    int cnt_short = shortest_ops_from_state(st, shortest);

    bool used[LOOP_COUNT][2] = {};
    int cnt = 0;

    for(int i = 0; i < cnt_short; i++) {
      int m = shortest[i].m;
      int dir = shortest[i].dir;
      int di = dir_index(dir);
      out[cnt++] = {(int8_t)m, (int8_t)dir, eval_after_rotate(st, m, dir)};
      used[m][di] = true;
    }

    TransCand best[EXTRA_TRANSITIONS];
    int bc = 0;

    auto insert_best = [&](TransCand cand) {
      if(bc < EXTRA_TRANSITIONS) {
        int p = bc++;
        while(p > 0 && better_trans(cand, best[p - 1])) {
          best[p] = best[p - 1];
          p--;
        }
        best[p] = cand;
        return;
      }

      if(!better_trans(cand, best[bc - 1])) return;

      int p = bc - 1;
      while(p > 0 && better_trans(cand, best[p - 1])) {
        best[p] = best[p - 1];
        p--;
      }
      best[p] = cand;
    };

    for(int m = 0; m < LOOP_COUNT; m++) {
      for(int dir: {-1, 1}) {
        int di = dir_index(dir);
        if(used[m][di]) continue;
        insert_best({(int8_t)m, (int8_t)dir, eval_after_rotate(st, m, dir)});
      }
    }

    for(int i = 0; i < bc; i++) out[cnt++] = best[i];
    return cnt;
  }

  inline ChildCand make_child(const BeamState &st, int parent_node, const TransCand &tr) const {
    ChildCand ch;
    ch.parent = parent_node;
    ch.m = tr.m;
    ch.dir = tr.dir;
    ch.eval = tr.eval;
    ch.depth = (int16_t)(st.depth + 1);
    ch.target_cell = target_cell_after_rotate(st, tr.m, tr.dir);
    ch.done = (ch.target_cell == EXIT_CELL);
    if(ch.done) ch.target_cell = -1;
    return ch;
  }

  template<class T, class Better>
  void prune_vector(vector<T> &v, int width, Better better) const {
    if((int)v.size() > width) {
      nth_element(v.begin(), v.begin() + width, v.end(), better);
      v.resize(width);
    }
    sort(v.begin(), v.end(), better);
  }

  vector<Op> restore_path_from_node(const vector<TreeNode> &nodes, int node_id) const {
    vector<Op> path;
    path.reserve(64);

    while(node_id > 0) {
      const TreeNode &nd = nodes[node_id];
      path.push_back({nd.m, nd.dir});
      node_id = nd.parent;
    }

    reverse(path.begin(), path.end());
    return path;
  }

  vector<Op> restore_path_from_final(const vector<TreeNode> &nodes, const ChildCand &fin) const {
    vector<Op> path = restore_path_from_node(nodes, fin.parent);
    path.push_back({fin.m, fin.dir});
    return path;
  }

  vector<Op> beam_path_to_exit(int target) {
    prepare_weights(target);

    BeamState st = current_beam_state(target);
    if(st.target_cell == -1) return {};

    int depth_limit = target_dist[st.target_cell] + EXTRA_DEPTH;
    int remaining = LIMIT_T - (int)answer.size();
    if(depth_limit > remaining) depth_limit = remaining;
    if(depth_limit <= 0) return {};

    vector<TreeNode> nodes;
    vector<int> beam;
    vector<int> next_beam;
    vector<ChildCand> children;
    vector<ChildCand> finals;

    nodes.reserve(1 + BEAM_WIDTH * (depth_limit + 1));
    beam.reserve(BEAM_WIDTH);
    next_beam.reserve(BEAM_WIDTH);
    children.reserve(BEAM_WIDTH * (EXTRA_TRANSITIONS + 4));
    finals.reserve(BEAM_WIDTH * 2);

    TreeNode root;
    root.parent = -1;
    root.eval = st.eval;
    root.target_cell = st.target_cell;
    root.depth = 0;
    root.m = -1;
    root.dir = 0;
    nodes.push_back(root);
    beam.push_back(0);

    int cur_node = 0;

    for(int depth = 0; depth < depth_limit; depth++) {
      children.clear();

      for(int i = 0; i < (int)beam.size(); i++) {
        int node_id = beam[i];
        move_to_node(st, nodes, cur_node, node_id);

        TransCand trans[16];
        int tc = transition_ops_from_state(st, trans);

        const TreeNode &parent = nodes[node_id];
        for(int j = 0; j < tc; j++) {
          if(parent.m == trans[j].m && parent.dir == -trans[j].dir) continue;

          ChildCand ch = make_child(st, node_id, trans[j]);
          if(ch.done) finals.push_back(ch);
          else children.push_back(ch);
        }
      }

      prune_vector(finals, BEAM_WIDTH, better_child);
      prune_vector(children, BEAM_WIDTH, better_child);

      next_beam.clear();
      for(const ChildCand &ch: children) {
        TreeNode nd;
        nd.parent = ch.parent;
        nd.eval = ch.eval;
        nd.target_cell = ch.target_cell;
        nd.depth = ch.depth;
        nd.m = ch.m;
        nd.dir = ch.dir;
        nodes.push_back(nd);
        next_beam.push_back((int)nodes.size() - 1);
      }

      beam.swap(next_beam);
      if(beam.empty()) break;
    }

    if(!finals.empty()) {
      return restore_path_from_final(nodes, finals.front());
    }

    Candidate cand = best_candidate(target);
    vector<Op> fallback;

    if(cand.col_loop < 0 || cand.row_loop < 0) return fallback;

    int dir = cand.move_col >= 0 ? 1 : -1;
    for(int i = 0; i < abs(cand.move_col); i++) fallback.push_back({(int8_t)cand.col_loop, (int8_t)dir});

    dir = cand.move_row >= 0 ? 1 : -1;
    for(int i = 0; i < abs(cand.move_row); i++) fallback.push_back({(int8_t)cand.row_loop, (int8_t)dir});

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