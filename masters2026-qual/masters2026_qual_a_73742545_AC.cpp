/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73742545
 * Submitted at: 2026-03-01 14:29:36
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_a
 * Result: AC
 * Execution Time: 2 ms
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

  vector<pair<int, int>> tree_parent;
  vector<vector<int>> tree_children;
  vector<pair<int, int>> walk_cells;
  vector<Rule> rules;
  int start_r = 0;
  int start_c = 0;
  char start_dir = 'R';

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

  vector<int> neighbors(int r, int c) const {
    vector<int> out;
    if (r > 0 && h[r - 1][c] == '0') {
      out.push_back(id(r - 1, c));
    }
    if (c + 1 < N && v[r][c] == '0') {
      out.push_back(id(r, c + 1));
    }
    if (r + 1 < N && h[r][c] == '0') {
      out.push_back(id(r + 1, c));
    }
    if (c > 0 && v[r][c - 1] == '0') {
      out.push_back(id(r, c - 1));
    }
    return out;
  }

  void build_spanning_tree() {
    int V = N * N;
    tree_parent.assign(V, {-1, -1});
    tree_children.assign(V, {});

    int root = id(0, 0);
    vector<int> st;
    vector<int> vis(V, 0);
    st.push_back(root);
    vis[root] = 1;
    tree_parent[root] = {0, 0};

    while (!st.empty()) {
      int cur = st.back();
      st.pop_back();
      auto [r, c] = rc(cur);
      auto nb = neighbors(r, c);
      for (int nxt : nb) {
        if (vis[nxt]) {
          continue;
        }
        vis[nxt] = 1;
        tree_parent[nxt] = {r, c};
        tree_children[cur].push_back(nxt);
        st.push_back(nxt);
      }
    }
  }

  void dfs_walk(int cur) {
    for (int nxt : tree_children[cur]) {
      walk_cells.push_back(rc(nxt));
      dfs_walk(nxt);
      walk_cells.push_back(rc(cur));
    }
  }

  int dir_id(char d) const {
    if (d == 'U') {
      return 0;
    }
    if (d == 'R') {
      return 1;
    }
    if (d == 'D') {
      return 2;
    }
    return 3;
  }

  char dir_char(int d) const {
    static const char dc[4] = {'U', 'R', 'D', 'L'};
    return dc[d];
  }

  int step_dir(pair<int, int> a, pair<int, int> b) const {
    int r = a.first;
    int c = a.second;
    int nr = b.first;
    int nc = b.second;
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

  void build_actions_and_rules() {
    vector<int> move_dirs;
    for (int i = 0; i + 1 < (int)walk_cells.size(); i++) {
      move_dirs.push_back(step_dir(walk_cells[i], walk_cells[i + 1]));
    }

    if (move_dirs.empty()) {
      start_dir = 'U';
      rules = {{'R', 0, 'R', 0}};
      return;
    }

    int init_dir = move_dirs[0];
    int cur_dir = init_dir;
    start_dir = dir_char(init_dir);

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
      rules = {{'R', 0, 'R', 0}};
      return;
    }

    rules.resize(m);
    for (int s = 0; s < m; s++) {
      int nxt = (s + 1) % m;
      if (actions[s] == 'F') {
        rules[s] = {'F', nxt, 'R', nxt};
      } else {
        rules[s] = {actions[s], nxt, actions[s], nxt};
      }
    }
  }

  void solve() {
    build_spanning_tree();

    walk_cells.clear();
    walk_cells.push_back({0, 0});
    dfs_walk(id(0, 0));

    build_actions_and_rules();

    cout << 1 << '\n';
    cout << rules.size() << ' ' << start_r << ' ' << start_c << ' ' << start_dir << '\n';
    for (const auto &rule : rules) {
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
