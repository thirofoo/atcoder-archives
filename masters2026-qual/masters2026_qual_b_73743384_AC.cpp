/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73743384
 * Submitted at: 2026-03-01 14:56:13
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_b
 * Result: AC
 * Execution Time: 30 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Rule {
  char a0;
  int b0;
  char a1;
  int b1;
};

struct Solver {
  int N;
  int A_K, A_M, A_W;
  vector<string> v, h;

  vector<Rule> best_rules;
  int start_r = 0;
  int start_c = 0;
  char best_start_dir = 'R';

  void input() {
    cin >> N >> A_K >> A_M >> A_W;
    v.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> v[i];
    }
    h.resize(N - 1);
    for (int i = 0; i < N - 1; i++) {
      cin >> h[i];
    }
  }

  int id(int r, int c) const {
    return r * N + c;
  }

  pair<int, int> rc(int idx) const {
    return {idx / N, idx % N};
  }

  char dir_char(int d) const {
    static const char dc[4] = {'U', 'R', 'D', 'L'};
    return dc[d];
  }

  int step_dir(int a, int b) const {
    auto [r, c] = rc(a);
    auto [nr, nc] = rc(b);
    if (nr == r - 1 && nc == c) {
      return 0;
    }
    if (nr == r && nc == c + 1) {
      return 1;
    }
    if (nr == r + 1 && nc == c) {
      return 2;
    }
    return 3;
  }

  int turn_cost(int from_dir, int to_dir) const {
    int diff = (to_dir - from_dir + 4) % 4;
    if (diff == 0) {
      return 0;
    }
    if (diff == 2) {
      return 2;
    }
    return 1;
  }

  vector<pair<int, int>> next_edges(int r, int c) const {
    vector<pair<int, int>> out;
    if (r > 0 && h[r - 1][c] == '0') {
      out.push_back({0, id(r - 1, c)});
    }
    if (c + 1 < N && v[r][c] == '0') {
      out.push_back({1, id(r, c + 1)});
    }
    if (r + 1 < N && h[r][c] == '0') {
      out.push_back({2, id(r + 1, c)});
    }
    if (c > 0 && v[r][c - 1] == '0') {
      out.push_back({3, id(r, c - 1)});
    }
    return out;
  }

  vector<int> bfs_path(int src, int dst) const {
    if (src == dst) {
      return {src};
    }
    int V = N * N;
    vector<int> prev(V, -1);
    queue<int> q;
    q.push(src);
    prev[src] = src;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      auto [r, c] = rc(cur);
      for (auto [dir, nxt] : next_edges(r, c)) {
        (void)dir;
        if (prev[nxt] != -1) {
          continue;
        }
        prev[nxt] = cur;
        if (nxt == dst) {
          break;
        }
        q.push(nxt);
      }
    }

    if (prev[dst] == -1) {
      return {};
    }

    vector<int> path;
    int cur = dst;
    while (cur != src) {
      path.push_back(cur);
      cur = prev[cur];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
  }

  vector<int> build_snake_order(bool reverse_rows, bool first_row_right) const {
    vector<int> order;
    vector<int> rows;
    rows.reserve(N);
    for (int r = 0; r < N; r++) {
      rows.push_back(r);
    }
    if (reverse_rows) {
      reverse(rows.begin(), rows.end());
    }

    for (int i = 0; i < N; i++) {
      int r = rows[i];
      bool to_right = ((i % 2 == 0) ? first_row_right : !first_row_right);
      if (to_right) {
        for (int c = 0; c < N; c++) {
          order.push_back(id(r, c));
        }
      } else {
        for (int c = N - 1; c >= 0; c--) {
          order.push_back(id(r, c));
        }
      }
    }
    return order;
  }

  vector<int> build_snake_like_walk(bool reverse_rows, bool first_row_right, bool &ok) {
    vector<int> target = build_snake_order(reverse_rows, first_row_right);
    vector<int> walk;
    int root = id(0, 0);
    int cur = root;
    walk.push_back(cur);
    ok = true;

    vector<char> seen_target(N * N, 0);
    for (int t : target) {
      if (seen_target[t]) {
        continue;
      }
      seen_target[t] = 1;
      auto path = bfs_path(cur, t);
      if (path.empty()) {
        ok = false;
        return {};
      }
      for (int i = 1; i < (int)path.size(); i++) {
        walk.push_back(path[i]);
      }
      cur = t;
    }

    auto back = bfs_path(cur, root);
    if (back.empty()) {
      ok = false;
      return {};
    }
    for (int i = 1; i < (int)back.size(); i++) {
      walk.push_back(back[i]);
    }

    return walk;
  }

  int straight_unvisited_run(int from, int dir, const vector<char> &visited) const {
    static const int dr[4] = {-1, 0, 1, 0};
    static const int dc[4] = {0, 1, 0, -1};

    auto [r0, c0] = rc(from);
    int r = r0;
    int c = c0;
    int len = 0;

    while (true) {
      int nr = r + dr[dir];
      int nc = c + dc[dir];
      if (!(0 <= nr && nr < N && 0 <= nc && nc < N)) {
        break;
      }
      bool ok = false;
      if (dir == 0) {
        ok = (h[r - 1][c] == '0');
      } else if (dir == 1) {
        ok = (v[r][c] == '0');
      } else if (dir == 2) {
        ok = (h[r][c] == '0');
      } else {
        ok = (v[r][c - 1] == '0');
      }
      if (!ok) {
        break;
      }

      int nxt = id(nr, nc);
      if (visited[nxt]) {
        break;
      }

      len++;
      r = nr;
      c = nc;
    }

    return len;
  }

  vector<int> build_direction_aware_walk(int prefer_dir) {
    int V = N * N;
    vector<char> visited(V, 0);
    vector<int> stack_cells;
    vector<int> walk;

    int root = id(0, 0);
    stack_cells.push_back(root);
    walk.push_back(root);
    visited[root] = 1;

    int heading = prefer_dir;

    while (!stack_cells.empty()) {
      int cur = stack_cells.back();
      auto [r, c] = rc(cur);

      vector<pair<int, int>> candidates;
      for (auto [dir, nxt] : next_edges(r, c)) {
        if (!visited[nxt]) {
          candidates.push_back({dir, nxt});
        }
      }

      if (!candidates.empty()) {
        sort(candidates.begin(), candidates.end(), [&](const auto &a, const auto &b) {
          int ta = turn_cost(heading, a.first);
          int tb = turn_cost(heading, b.first);
          if (ta != tb) {
            return ta < tb;
          }
          int ra = straight_unvisited_run(cur, a.first, visited);
          int rb = straight_unvisited_run(cur, b.first, visited);
          if (ra != rb) {
            return ra > rb;
          }
          return a.second < b.second;
        });

        int nd = candidates[0].first;
        int nxt = candidates[0].second;

        heading = nd;
        visited[nxt] = 1;
        stack_cells.push_back(nxt);
        walk.push_back(nxt);
      } else {
        if ((int)stack_cells.size() == 1) {
          break;
        }
        int parent = stack_cells[(int)stack_cells.size() - 2];
        heading = step_dir(cur, parent);
        stack_cells.pop_back();
        walk.push_back(parent);
      }
    }

    return walk;
  }

  pair<vector<Rule>, char> build_rules_from_walk(const vector<int> &walk) {
    vector<int> move_dirs;
    for (int i = 0; i + 1 < (int)walk.size(); i++) {
      move_dirs.push_back(step_dir(walk[i], walk[i + 1]));
    }

    if (move_dirs.empty()) {
      return {{{'R', 0, 'R', 0}}, 'U'};
    }

    int init_dir = move_dirs[0];
    int cur_dir = init_dir;
    char start_dir = dir_char(init_dir);

    vector<char> actions;
    for (int need : move_dirs) {
      while (cur_dir != need) {
        int diff = (need - cur_dir + 4) % 4;
        if (diff == 1) {
          actions.push_back('R');
          cur_dir = (cur_dir + 1) % 4;
        } else if (diff == 3) {
          actions.push_back('L');
          cur_dir = (cur_dir + 3) % 4;
        } else {
          actions.push_back('R');
          cur_dir = (cur_dir + 1) % 4;
        }
      }
      actions.push_back('F');
    }

    while (cur_dir != init_dir) {
      int diff = (init_dir - cur_dir + 4) % 4;
      if (diff == 1) {
        actions.push_back('R');
        cur_dir = (cur_dir + 1) % 4;
      } else if (diff == 3) {
        actions.push_back('L');
        cur_dir = (cur_dir + 3) % 4;
      } else {
        actions.push_back('R');
        cur_dir = (cur_dir + 1) % 4;
      }
    }

    int m = (int)actions.size();
    if (m == 0) {
      return {{{'R', 0, 'R', 0}}, 'U'};
    }

    vector<Rule> rules(m);
    for (int s = 0; s < m; s++) {
      int nxt = (s + 1) % m;
      if (actions[s] == 'F') {
        rules[s] = {'F', nxt, 'R', nxt};
      } else {
        rules[s] = {actions[s], nxt, actions[s], nxt};
      }
    }

    return {rules, start_dir};
  }

  void solve() {
    long long best_cost = (1LL << 62);

    for (int rev = 0; rev < 2; rev++) {
      for (int right = 0; right < 2; right++) {
        bool ok = false;
        vector<int> walk = build_snake_like_walk(rev, right, ok);
        if (!ok || walk.empty()) {
          continue;
        }
        auto [rules, sd] = build_rules_from_walk(walk);
        long long cost = 1LL * A_K + 1LL * A_M * (int)rules.size();
        if (cost < best_cost) {
          best_cost = cost;
          best_rules = rules;
          best_start_dir = sd;
        }
      }
    }

    for (int prefer = 0; prefer < 4; prefer++) {
      vector<int> walk = build_direction_aware_walk(prefer);
      auto [rules, sd] = build_rules_from_walk(walk);
      long long cost = 1LL * A_K + 1LL * A_M * (int)rules.size();
      if (cost < best_cost) {
        best_cost = cost;
        best_rules = rules;
        best_start_dir = sd;
      }
    }

    cout << 1 << '\n';
    cout << best_rules.size() << ' ' << start_r << ' ' << start_c << ' ' << best_start_dir << '\n';
    for (const auto &rule : best_rules) {
      cout << rule.a0 << ' ' << rule.b0 << ' ' << rule.a1 << ' ' << rule.b1 << '\n';
    }

    string zv(N - 1, '0');
    for (int i = 0; i < N; i++) {
      cout << zv << '\n';
    }
    string zh(N, '0');
    for (int i = 0; i < N - 1; i++) {
      cout << zh << '\n';
    }
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  Solver solver;
  solver.input();
  solver.solve();
  return 0;
}
