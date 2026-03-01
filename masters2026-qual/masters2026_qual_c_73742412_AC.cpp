/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73742412
 * Submitted at: 2026-03-01 14:24:37
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_c
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Rule {
  char a0;
  int b0;
  char a1;
  int b1;
};

struct RobotPlan {
  int sr;
  int sc;
  char sd;
  vector<Rule> rules;
};

struct Candidate {
  bool valid = false;
  long long V = (1LL << 62);
  int K = 0;
  int M = 0;
  int W = 0;
  vector<RobotPlan> robots;
  vector<string> add_v;
  vector<string> add_h;
};

struct Solver {
  int N;
  int A_K, A_M, A_W;
  vector<string> v, h;

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

  pair<int, int> rc(int x) const {
    return {x / N, x % N};
  }

  bool in_stripe(int r, int top, int bottom) const {
    return top <= r && r <= bottom;
  }

  vector<int> neighbors_in_stripe(int r, int c, int top, int bottom) const {
    vector<int> out;
    if (r > top && h[r - 1][c] == '0') {
      out.push_back(id(r - 1, c));
    }
    if (c + 1 < N && v[r][c] == '0') {
      out.push_back(id(r, c + 1));
    }
    if (r < bottom && h[r][c] == '0') {
      out.push_back(id(r + 1, c));
    }
    if (c > 0 && v[r][c - 1] == '0') {
      out.push_back(id(r, c - 1));
    }
    return out;
  }

  int step_dir(pair<int, int> a, pair<int, int> b) const {
    int r = a.first, c = a.second;
    int nr = b.first, nc = b.second;
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

  char dir_char(int d) const {
    static const char dc[4] = {'U', 'R', 'D', 'L'};
    return dc[d];
  }

  bool build_robot_for_component(const vector<pair<int, int>> &cells, int top, int bottom, RobotPlan &out) {
    if (cells.empty()) {
      return false;
    }

    vector<int> in_comp(N * N, 0);
    for (auto [r, c] : cells) {
      in_comp[id(r, c)] = 1;
    }

    int root = id(cells[0].first, cells[0].second);
    vector<int> vis(N * N, 0);
    vector<vector<int>> children(N * N);
    vector<int> st;
    st.push_back(root);
    vis[root] = 1;

    while (!st.empty()) {
      int cur = st.back();
      st.pop_back();
      auto [r, c] = rc(cur);
      auto nb = neighbors_in_stripe(r, c, top, bottom);
      for (int nxt : nb) {
        if (!in_comp[nxt] || vis[nxt]) {
          continue;
        }
        vis[nxt] = 1;
        children[cur].push_back(nxt);
        st.push_back(nxt);
      }
    }

    for (auto [r, c] : cells) {
      if (!vis[id(r, c)]) {
        return false;
      }
    }

    vector<pair<int, int>> walk;
    walk.push_back(rc(root));

    function<void(int)> dfs = [&](int cur) {
      for (int nxt : children[cur]) {
        walk.push_back(rc(nxt));
        dfs(nxt);
        walk.push_back(rc(cur));
      }
    };
    dfs(root);

    vector<int> move_dirs;
    for (int i = 0; i + 1 < (int)walk.size(); i++) {
      move_dirs.push_back(step_dir(walk[i], walk[i + 1]));
    }

    vector<char> actions;
    char sd = 'U';

    if (move_dirs.empty()) {
      actions.push_back('R');
      sd = 'U';
    } else {
      int init_dir = move_dirs[0];
      int cur_dir = init_dir;
      sd = dir_char(init_dir);

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
    }

    if ((int)actions.size() > 4 * N * N) {
      return false;
    }

    out.sr = walk[0].first;
    out.sc = walk[0].second;
    out.sd = sd;
    out.rules.resize(actions.size());

    int m = (int)actions.size();
    for (int s = 0; s < m; s++) {
      int nxt = (s + 1) % m;
      if (actions[s] == 'F') {
        out.rules[s] = {'F', nxt, 'R', nxt};
      } else {
        out.rules[s] = {actions[s], nxt, actions[s], nxt};
      }
    }
    return true;
  }

  bool build_components_in_stripe(int top, int bottom, vector<vector<pair<int, int>>> &components) {
    components.clear();
    vector<vector<int>> vis(N, vector<int>(N, 0));

    for (int r = top; r <= bottom; r++) {
      for (int c = 0; c < N; c++) {
        if (vis[r][c]) {
          continue;
        }
        vector<pair<int, int>> comp;
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;

        while (!q.empty()) {
          auto [cr, cc] = q.front();
          q.pop();
          comp.push_back({cr, cc});

          auto nb = neighbors_in_stripe(cr, cc, top, bottom);
          for (int nxt : nb) {
            auto [nr, nc] = rc(nxt);
            if (vis[nr][nc]) {
              continue;
            }
            vis[nr][nc] = 1;
            q.push({nr, nc});
          }
        }

        components.push_back(comp);
      }
    }

    return true;
  }

  Candidate evaluate_with_cuts(const vector<int> &cuts) {
    Candidate cand;

    vector<pair<int, int>> stripes;
    int top = 0;
    for (int cut : cuts) {
      stripes.push_back({top, cut});
      top = cut + 1;
    }
    stripes.push_back({top, N - 1});

    cand.add_v.assign(N, string(N - 1, '0'));
    cand.add_h.assign(N - 1, string(N, '0'));

    for (int cut : cuts) {
      for (int c = 0; c < N; c++) {
        cand.add_h[cut][c] = '1';
      }
    }

    cand.robots.clear();

    for (auto [s_top, s_bottom] : stripes) {
      vector<vector<pair<int, int>>> comps;
      build_components_in_stripe(s_top, s_bottom, comps);
      if ((int)comps.size() != 1) {
        return cand;
      }

      RobotPlan rb;
      if (!build_robot_for_component(comps[0], s_top, s_bottom, rb)) {
        return cand;
      }
      cand.robots.push_back(move(rb));
    }

    cand.K = (int)cand.robots.size();
    cand.M = 0;
    for (auto &rb : cand.robots) {
      cand.M += (int)rb.rules.size();
    }

    cand.W = 0;
    for (int r = 0; r < N; r++) {
      for (char ch : cand.add_v[r]) {
        if (ch == '1') {
          cand.W++;
        }
      }
    }
    for (int r = 0; r < N - 1; r++) {
      for (char ch : cand.add_h[r]) {
        if (ch == '1') {
          cand.W++;
        }
      }
    }

    cand.V = 1LL * A_K * (cand.K - 1) + 1LL * A_M * cand.M + 1LL * A_W * cand.W;
    cand.valid = true;
    return cand;
  }

  Candidate build_best_candidate() {
    Candidate best;

    {
      Candidate c1 = evaluate_with_cuts({});
      if (c1.valid && c1.V < best.V) {
        best = move(c1);
      }
    }

    for (int cut = 0; cut + 1 < N; cut++) {
      Candidate c2 = evaluate_with_cuts({cut});
      if (c2.valid && c2.V < best.V) {
        best = move(c2);
      }
    }

    for (int cut1 = 0; cut1 + 1 < N; cut1++) {
      for (int cut2 = cut1 + 1; cut2 + 1 < N; cut2++) {
        Candidate c3 = evaluate_with_cuts({cut1, cut2});
        if (c3.valid && c3.V < best.V) {
          best = move(c3);
        }
      }
    }

    return best;
  }

  void solve() {
    Candidate ans = build_best_candidate();

    if (!ans.valid) {
      ans = evaluate_with_cuts({});
    }

    cout << ans.K << '\n';
    for (const auto &rb : ans.robots) {
      cout << rb.rules.size() << ' ' << rb.sr << ' ' << rb.sc << ' ' << rb.sd << '\n';
      for (const auto &rule : rb.rules) {
        cout << rule.a0 << ' ' << rule.b0 << ' ' << rule.a1 << ' ' << rule.b1 << '\n';
      }
    }

    for (int i = 0; i < N; i++) {
      cout << ans.add_v[i] << '\n';
    }
    for (int i = 0; i < N - 1; i++) {
      cout << ans.add_h[i] << '\n';
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
