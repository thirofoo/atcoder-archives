/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc065/submissions/75818860
 * Submitted at: 2026-05-16 15:30:05
 * Problem URL: https://atcoder.jp/contests/ahc065/tasks/ahc065_a
 * Result: AC
 * Execution Time: 447 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Solver {
  static constexpr int N = 20;
  static constexpr int EXIT_R = 0;
  static constexpr int EXIT_C = 10;
  static constexpr int LIMIT_T = 100000;

  int n;
  vector<vector<int>> grid;
  vector<pair<int, int>> pos;
  vector<vector<pair<int, int>>> loops;
  vector<vector<int>> idx_in_loop;
  vector<array<int, 4>> target_next;
  vector<int> target_dist;
  vector<pair<int, int>> ops;
  int next_box = 0;

  void input() {
    cin >> n;
    grid.assign(N, vector<int>(N));
    pos.assign(N * N, {-1, -1});
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cin >> grid[i][j];
        pos[grid[i][j]] = {i, j};
      }
    }
  }

  void build_loops() {
    loops.clear();

    for(int r = 0; r < N; r += 2) {
      vector<pair<int, int>> loop;
      for(int c = 0; c < N; c++) loop.push_back({r, c});
      for(int c = N - 1; c >= 0; c--) loop.push_back({r + 1, c});
      loops.push_back(loop);
    }

    for(int c = 0; c < N; c += 2) {
      vector<pair<int, int>> loop;
      for(int r = 0; r < N; r++) loop.push_back({r, c});
      for(int r = N - 1; r >= 0; r--) loop.push_back({r, c + 1});
      loops.push_back(loop);
    }

    idx_in_loop.assign((int)loops.size(), vector<int>(N * N, -1));
    for(int m = 0; m < (int)loops.size(); m++) {
      for(int i = 0; i < (int)loops[m].size(); i++) {
        auto [r, c] = loops[m][i];
        idx_in_loop[m][r * N + c] = i;
      }
    }

    build_target_graph();
  }

  int row_loop_id(int r) const {
    return r / 2;
  }

  int col_loop_id(int c) const {
    return 10 + c / 2;
  }

  int loop_index(int m, int r, int c) const {
    return idx_in_loop[m][r * N + c];
  }

  int signed_delta(int len, int from, int to) const {
    int plus = (to - from + len) % len;
    int minus = (from - to + len) % len;
    return (plus <= minus) ? plus : -minus;
  }

  void build_target_graph() {
    target_next.assign(N * N, array<int, 4>{-1, -1, -1, -1});

    for(int r = 0; r < N; r++) {
      for(int c = 0; c < N; c++) {
        int v = r * N + c;

        int rm = row_loop_id(r);
        int ri = loop_index(rm, r, c);
        for(int dir_i = 0; dir_i < 2; dir_i++) {
          int dir = dir_i == 0 ? -1 : 1;
          int ni = (ri + dir + (int)loops[rm].size()) % (int)loops[rm].size();
          auto [nr, nc] = loops[rm][ni];
          target_next[v][dir_i] = nr * N + nc;
        }

        int cm = col_loop_id(c);
        int ci = loop_index(cm, r, c);
        for(int dir_i = 0; dir_i < 2; dir_i++) {
          int dir = dir_i == 0 ? -1 : 1;
          int ni = (ci + dir + (int)loops[cm].size()) % (int)loops[cm].size();
          auto [nr, nc] = loops[cm][ni];
          target_next[v][2 + dir_i] = nr * N + nc;
        }
      }
    }

    target_dist.assign(N * N, 1 << 30);
    queue<int> q;
    int exit_cell = EXIT_R * N + EXIT_C;
    target_dist[exit_cell] = 0;
    q.push(exit_cell);
    while(!q.empty()) {
      int v = q.front();
      q.pop();
      for(int to: target_next[v]) {
        if(target_dist[to] > target_dist[v] + 1) {
          target_dist[to] = target_dist[v] + 1;
          q.push(to);
        }
      }
    }
  }

  void remove_if_ready() {
    if(next_box >= N * N) return;
    if(grid[EXIT_R][EXIT_C] == next_box) {
      grid[EXIT_R][EXIT_C] = -1;
      pos[next_box] = {-1, -1};
      next_box++;
    }
  }

  bool rotate_once(int m, int dir, bool record) {
    if(record && (int)ops.size() >= LIMIT_T) return false;

    const auto &loop = loops[m];
    int len = (int)loop.size();
    vector<int> vals(len);
    for(int i = 0; i < len; i++) {
      auto [r, c] = loop[i];
      vals[i] = grid[r][c];
    }

    vector<int> moved(len, -1);
    for(int i = 0; i < len; i++) {
      int ni = (i + dir + len) % len;
      moved[ni] = vals[i];
    }

    for(int i = 0; i < len; i++) {
      auto [r, c] = loop[i];
      grid[r][c] = moved[i];
      if(moved[i] != -1) pos[moved[i]] = {r, c};
    }

    if(record) {
      ops.push_back({m, dir});
      remove_if_ready();
    }
    return true;
  }

  bool rotate_steps(int m, int signed_steps, bool record) {
    int dir = signed_steps >= 0 ? 1 : -1;
    int cnt = abs(signed_steps);
    for(int i = 0; i < cnt; i++) {
      if(!rotate_once(m, dir, record)) return false;
    }
    return true;
  }

  struct BeamState {
    array<int, N * N> board{};
    array<int, N * N> cell_of{};
    vector<pair<int, int>> path;
    long long eval = 0;
    int target_cell = -1;
    bool done = false;
  };

  BeamState current_beam_state(int target) const {
    BeamState st;
    st.cell_of.fill(-1);
    for(int r = 0; r < N; r++) {
      for(int c = 0; c < N; c++) {
        int v = grid[r][c];
        st.board[r * N + c] = v;
        if(v != -1) st.cell_of[v] = r * N + c;
      }
    }
    st.target_cell = st.cell_of[target];
    return st;
  }

  void rotate_state(BeamState &st, int m, int dir, int target) const {
    const auto &loop = loops[m];
    int len = (int)loop.size();
    array<int, 40> vals{};
    for(int i = 0; i < len; i++) {
      auto [r, c] = loop[i];
      vals[i] = st.board[r * N + c];
    }

    for(int i = 0; i < len; i++) {
      int ni = (i + dir + len) % len;
      auto [r, c] = loop[ni];
      int v = vals[i];
      st.board[r * N + c] = v;
      if(v != -1) st.cell_of[v] = r * N + c;
    }

    int exit_cell = EXIT_R * N + EXIT_C;
    if(st.board[exit_cell] == target) {
      st.board[exit_cell] = -1;
      st.cell_of[target] = -1;
      st.target_cell = -1;
      st.done = true;
    } else {
      st.target_cell = st.cell_of[target];
    }
    st.path.push_back({m, dir});
  }

  long long evaluate_state(const BeamState &st, int start_box) const {
    long long value = 0;
    for(int b = start_box; b < N * N; b++) {
      int cell = st.cell_of[b];
      if(cell == -1) continue;
      long long w = 1LL * (N * N - b) * (N * N - b);
      value += w * target_dist[cell];
    }
    value += (long long)st.path.size() * 1000000000LL;
    return value;
  }

  vector<pair<int, int>> shortest_ops_from_state(const BeamState &st, int target) const {
    int cell = st.target_cell;
    if(cell == -1) return {};
    int r = cell / N;
    int c = cell % N;
    int cur = target_dist[cell];

    vector<pair<int, int>> res;
    auto add_if_shorter = [&](int m, int dir) {
      int idx = loop_index(m, r, c);
      int ni = (idx + dir + (int)loops[m].size()) % (int)loops[m].size();
      auto [nr, nc] = loops[m][ni];
      int to = nr * N + nc;
      if(target_dist[to] == cur - 1) res.push_back({m, dir});
    };

    int rm = row_loop_id(r);
    int cm = col_loop_id(c);
    bool same_row_pair = rm == row_loop_id(EXIT_R);
    bool same_col_pair = cm == col_loop_id(EXIT_C);

    if(same_row_pair) {
      add_if_shorter(rm, -1);
      add_if_shorter(rm, 1);
    } else if(same_col_pair) {
      add_if_shorter(cm, -1);
      add_if_shorter(cm, 1);
    }

    if(res.empty()) {
      add_if_shorter(rm, -1);
      add_if_shorter(rm, 1);
      add_if_shorter(cm, -1);
      add_if_shorter(cm, 1);
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
  }

  vector<pair<int, int>> beam_path_to_exit(int target) const {
    static constexpr int BEAM_WIDTH = 150;

    BeamState initial = current_beam_state(target);
    if(initial.target_cell == -1) return {};

    int depth_limit = target_dist[initial.target_cell];
    vector<BeamState> beam;
    beam.push_back(initial);
    vector<BeamState> finals;

    for(int depth = 0; depth < depth_limit && finals.empty(); depth++) {
      vector<BeamState> next_beam;
      for(const auto &st: beam) {
        for(auto [m, dir]: shortest_ops_from_state(st, target)) {
          BeamState ns = st;
          rotate_state(ns, m, dir, target);
          ns.eval = evaluate_state(ns, target);
          if(ns.done) finals.push_back(std::move(ns));
          else next_beam.push_back(std::move(ns));
        }
      }

      auto cmp = [](const BeamState &a, const BeamState &b) {
        if(a.eval != b.eval) return a.eval < b.eval;
        return a.path.size() < b.path.size();
      };
      sort(finals.begin(), finals.end(), cmp);
      sort(next_beam.begin(), next_beam.end(), cmp);
      if((int)next_beam.size() > BEAM_WIDTH) next_beam.resize(BEAM_WIDTH);
      beam = std::move(next_beam);
      if(beam.empty()) break;
    }

    if(!finals.empty()) return finals.front().path;

    Candidate cand = best_candidate(target);
    vector<pair<int, int>> fallback;
    int dir = cand.move_col >= 0 ? 1 : -1;
    for(int i = 0; i < abs(cand.move_col); i++) fallback.push_back({cand.col_loop, dir});
    dir = cand.move_row >= 0 ? 1 : -1;
    for(int i = 0; i < abs(cand.move_row); i++) fallback.push_back({cand.row_loop, dir});
    return fallback;
  }

  bool apply_path(const vector<pair<int, int>> &path) {
    for(auto [m, dir]: path) {
      if(!rotate_once(m, dir, true)) return false;
    }
    return true;
  }

  struct Candidate {
    int cost = INT_MAX;
    int col_loop = -1;
    int row_loop = -1;
    int move_col = 0;
    int move_row = 0;
    pair<int, int> via = {-1, -1};
  };

  Candidate best_candidate(int box) const {
    auto [r, c] = pos[box];
    Candidate best;
    if(r == -1) return best;

    int cm = col_loop_id(c);
    int start_col_idx = loop_index(cm, r, c);

    for(auto via: loops[cm]) {
      auto [vr, vc] = via;
      if(vr != 0 && vr != 1) continue;

      int via_col_idx = loop_index(cm, vr, vc);
      int move_col = signed_delta((int)loops[cm].size(), start_col_idx, via_col_idx);
      int rm = row_loop_id(vr);
      int via_row_idx = loop_index(rm, vr, vc);
      int exit_row_idx = loop_index(rm, EXIT_R, EXIT_C);
      int move_row = signed_delta((int)loops[rm].size(), via_row_idx, exit_row_idx);
      int cost = abs(move_col) + abs(move_row);

      if(cost < best.cost) {
        best.cost = cost;
        best.col_loop = cm;
        best.row_loop = rm;
        best.move_col = move_col;
        best.move_row = move_row;
        best.via = via;
      }
    }
    return best;
  }

  void solve() {
    build_loops();
    remove_if_ready();

    while(next_box < N * N && (int)ops.size() < LIMIT_T) {
      int target = next_box;
      vector<pair<int, int>> path = beam_path_to_exit(target);
      if(path.empty()) break;
      if(!apply_path(path)) break;

      if(next_box == target) {
        // This should not happen, but keep producing a legal partial answer.
        break;
      }
    }
  }

  void output() const {
    cout << loops.size() << '\n';
    for(const auto &loop: loops) {
      cout << loop.size();
      for(auto [r, c]: loop) cout << ' ' << r << ' ' << c;
      cout << '\n';
    }

    cout << ops.size() << '\n';
    for(auto [m, d]: ops) {
      cout << m << ' ' << d << '\n';
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
