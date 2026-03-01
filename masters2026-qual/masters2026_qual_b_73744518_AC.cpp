/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73744518
 * Submitted at: 2026-03-01 15:33:27
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_b
 * Result: AC
 * Execution Time: 212 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Rule {
  char a0;
  int b0;
  char a1;
  int b1;
};

struct RectRegion {
  int entry;
  vector<int> local_walk;
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
    for (int i = 0; i < N; i++) cin >> v[i];
    h.resize(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> h[i];
  }

  int id(int r, int c) const { return r * N + c; }
  pair<int, int> rc(int idx) const { return {idx / N, idx % N}; }

  int dir_id(char d) const {
    if (d == 'U') return 0;
    if (d == 'R') return 1;
    if (d == 'D') return 2;
    return 3;
  }

  char dir_char(int d) const {
    static const char dc[4] = {'U', 'R', 'D', 'L'};
    return dc[d];
  }

  bool can_move(int r, int c, int dir) const {
    if (dir == 0) return (r > 0 && h[r - 1][c] == '0');
    if (dir == 1) return (c + 1 < N && v[r][c] == '0');
    if (dir == 2) return (r + 1 < N && h[r][c] == '0');
    return (c > 0 && v[r][c - 1] == '0');
  }

  int step_dir(int a, int b) const {
    auto [r, c] = rc(a);
    auto [nr, nc] = rc(b);
    if (nr == r - 1 && nc == c) return 0;
    if (nr == r && nc == c + 1) return 1;
    if (nr == r + 1 && nc == c) return 2;
    return 3;
  }

  int turn_cost(int from_dir, int to_dir) const {
    int diff = (to_dir - from_dir + 4) % 4;
    if (diff == 0) return 0;
    if (diff == 2) return 2;
    return 1;
  }

  vector<pair<int, int>> neighbors(int r, int c) const {
    vector<pair<int, int>> out;
    if (can_move(r, c, 0)) out.push_back({0, id(r - 1, c)});
    if (can_move(r, c, 1)) out.push_back({1, id(r, c + 1)});
    if (can_move(r, c, 2)) out.push_back({2, id(r + 1, c)});
    if (can_move(r, c, 3)) out.push_back({3, id(r, c - 1)});
    return out;
  }

  vector<int> bfs_path(int src, int dst) const {
    if (src == dst) return {src};
    int V = N * N;
    vector<int> prev(V, -1);
    queue<int> q;
    q.push(src);
    prev[src] = src;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      auto [r, c] = rc(cur);
      for (auto [dir, nxt] : neighbors(r, c)) {
        (void)dir;
        if (prev[nxt] != -1) continue;
        prev[nxt] = cur;
        if (nxt == dst) break;
        q.push(nxt);
      }
    }

    if (prev[dst] == -1) return {};
    vector<int> path;
    for (int cur = dst; cur != src; cur = prev[cur]) path.push_back(cur);
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
  }

  vector<int> build_snake_order(bool reverse_rows, bool first_row_right) const {
    vector<int> rows(N);
    iota(rows.begin(), rows.end(), 0);
    if (reverse_rows) reverse(rows.begin(), rows.end());

    vector<int> order;
    order.reserve(N * N);
    for (int i = 0; i < N; i++) {
      int r = rows[i];
      bool to_right = ((i % 2 == 0) ? first_row_right : !first_row_right);
      if (to_right) {
        for (int c = 0; c < N; c++) order.push_back(id(r, c));
      } else {
        for (int c = N - 1; c >= 0; c--) order.push_back(id(r, c));
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
      if (seen_target[t]) continue;
      seen_target[t] = 1;
      auto path = bfs_path(cur, t);
      if (path.empty()) {
        ok = false;
        return {};
      }
      for (int i = 1; i < (int)path.size(); i++) walk.push_back(path[i]);
      cur = t;
    }

    auto back = bfs_path(cur, root);
    if (back.empty()) {
      ok = false;
      return {};
    }
    for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
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
      if (!can_move(r, c, dir)) break;
      int nr = r + dr[dir];
      int nc = c + dc[dir];
      int nxt = id(nr, nc);
      if (visited[nxt]) break;
      len++;
      r = nr;
      c = nc;
    }
    return len;
  }

  vector<int> build_direction_aware_walk(int prefer_dir) {
    int V = N * N;
    vector<char> visited(V, 0);
    vector<int> st;
    vector<int> walk;

    int root = id(0, 0);
    st.push_back(root);
    walk.push_back(root);
    visited[root] = 1;
    int heading = prefer_dir;

    while (!st.empty()) {
      int cur = st.back();
      auto [r, c] = rc(cur);

      vector<pair<int, int>> cand;
      for (auto [dir, nxt] : neighbors(r, c)) {
        if (!visited[nxt]) cand.push_back({dir, nxt});
      }

      if (!cand.empty()) {
        sort(cand.begin(), cand.end(), [&](const auto &a, const auto &b) {
          int ta = turn_cost(heading, a.first);
          int tb = turn_cost(heading, b.first);
          if (ta != tb) return ta < tb;
          int ra = straight_unvisited_run(cur, a.first, visited);
          int rb = straight_unvisited_run(cur, b.first, visited);
          if (ra != rb) return ra > rb;
          return a.second < b.second;
        });

        int nd = cand[0].first;
        int nxt = cand[0].second;
        heading = nd;
        visited[nxt] = 1;
        st.push_back(nxt);
        walk.push_back(nxt);
      } else {
        if ((int)st.size() == 1) break;
        int parent = st[(int)st.size() - 2];
        heading = step_dir(cur, parent);
        st.pop_back();
        walk.push_back(parent);
      }
    }

    if (!walk.empty() && walk.front() != walk.back()) {
      auto back = bfs_path(walk.back(), walk.front());
      if (!back.empty()) {
        for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
      }
    }
    return walk;
  }

  vector<RectRegion> build_rect_regions() {
    vector<RectRegion> regs;
    vector<char> assigned(N * N, 0);

    for (int r = 0; r + 1 < N; r += 2) {
      int c = 0;
      while (c < N) {
        int l = c;
        int rr = c;
        while (rr + 1 < N) {
          bool top_h = (v[r][rr] == '0');
          bool bot_h = (v[r + 1][rr] == '0');
          bool left_v = (h[r][rr] == '0');
          bool right_v = (h[r][rr + 1] == '0');
          if (top_h && bot_h && left_v && right_v) {
            rr++;
          } else {
            break;
          }
        }

        int width = rr - l + 1;
        if (width >= 2) {
          RectRegion reg;
          reg.entry = id(r, l);
          reg.local_walk.push_back(reg.entry);
          for (int x = l + 1; x <= rr; x++) reg.local_walk.push_back(id(r, x));
          reg.local_walk.push_back(id(r + 1, rr));
          for (int x = rr - 1; x >= l; x--) reg.local_walk.push_back(id(r + 1, x));
          reg.local_walk.push_back(reg.entry);

          for (int x = l; x <= rr; x++) {
            assigned[id(r, x)] = 1;
            assigned[id(r + 1, x)] = 1;
          }
          regs.push_back(move(reg));
          c = rr + 1;
        } else {
          c++;
        }
      }
    }

    for (int cell = 0; cell < N * N; cell++) {
      if (assigned[cell]) continue;
      RectRegion reg;
      reg.entry = cell;
      reg.local_walk = {cell};
      regs.push_back(move(reg));
    }

    return regs;
  }

  vector<int> build_rect_route_walk(bool &ok) {
    ok = true;
    auto regs = build_rect_regions();
    if (regs.empty()) {
      ok = false;
      return {};
    }

    int root = id(0, 0);
    int R = (int)regs.size();
    vector<char> used(R, 0);
    vector<int> order;
    order.reserve(R);

    int cur = root;
    for (int step = 0; step < R; step++) {
      int best_idx = -1;
      int best_dist = INT_MAX;

      for (int i = 0; i < R; i++) {
        if (used[i]) continue;
        auto path = bfs_path(cur, regs[i].entry);
        if (path.empty()) continue;
        int dist = (int)path.size();
        if (dist < best_dist) {
          best_dist = dist;
          best_idx = i;
        }
      }

      if (best_idx == -1) {
        ok = false;
        return {};
      }

      used[best_idx] = 1;
      order.push_back(best_idx);
      cur = regs[best_idx].entry;
    }

    vector<int> walk;
    walk.push_back(root);
    cur = root;

    for (int idx : order) {
      auto path = bfs_path(cur, regs[idx].entry);
      if (path.empty()) {
        ok = false;
        return {};
      }
      for (int i = 1; i < (int)path.size(); i++) walk.push_back(path[i]);
      for (int i = 1; i < (int)regs[idx].local_walk.size(); i++) walk.push_back(regs[idx].local_walk[i]);
      cur = regs[idx].entry;
    }

    auto back = bfs_path(cur, root);
    if (back.empty()) {
      ok = false;
      return {};
    }
    for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);

    return walk;
  }

  pair<vector<Rule>, char> build_rules_from_walk(const vector<int> &walk) {
    vector<int> move_dirs;
    for (int i = 0; i + 1 < (int)walk.size(); i++) {
      move_dirs.push_back(step_dir(walk[i], walk[i + 1]));
    }

    if (move_dirs.empty()) return {{{'R', 0, 'R', 0}}, 'U'};

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
    if (m == 0) return {{{'R', 0, 'R', 0}}, 'U'};

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

  pair<vector<Rule>, int> minimize_rules(const vector<Rule> &rules, int start_state) {
    int n = (int)rules.size();
    if (n == 0) return {{}, 0};

    vector<int> cls(n, 0);
    {
      map<pair<char, char>, int> mp;
      int nxt = 0;
      for (int i = 0; i < n; i++) {
        pair<char, char> key = {rules[i].a0, rules[i].a1};
        if (!mp.count(key)) mp[key] = nxt++;
        cls[i] = mp[key];
      }
    }

    while (true) {
      vector<int> ncls(n, 0);
      map<tuple<char, int, char, int>, int> mp;
      int nxt = 0;
      for (int i = 0; i < n; i++) {
        auto sig = make_tuple(rules[i].a0, cls[rules[i].b0], rules[i].a1, cls[rules[i].b1]);
        if (!mp.count(sig)) mp[sig] = nxt++;
        ncls[i] = mp[sig];
      }
      if (ncls == cls) break;
      cls.swap(ncls);
    }

    int cnum = *max_element(cls.begin(), cls.end()) + 1;
    vector<int> repr(cnum, -1);
    for (int i = 0; i < n; i++) {
      if (repr[cls[i]] == -1) repr[cls[i]] = i;
    }

    vector<Rule> comp(cnum);
    for (int c = 0; c < cnum; c++) {
      int r = repr[c];
      comp[c] = {rules[r].a0, cls[rules[r].b0], rules[r].a1, cls[rules[r].b1]};
    }

    int cstart = cls[start_state];
    vector<int> remap(cnum, -1);
    vector<int> q;
    q.push_back(cstart);
    remap[cstart] = 0;
    for (int qi = 0; qi < (int)q.size(); qi++) {
      int vtx = q[qi];
      int to0 = comp[vtx].b0;
      int to1 = comp[vtx].b1;
      if (remap[to0] == -1) {
        remap[to0] = (int)q.size();
        q.push_back(to0);
      }
      if (remap[to1] == -1) {
        remap[to1] = (int)q.size();
        q.push_back(to1);
      }
    }

    vector<Rule> out(q.size());
    for (int i = 0; i < (int)q.size(); i++) {
      int old = q[i];
      out[i] = {comp[old].a0, remap[comp[old].b0], comp[old].a1, remap[comp[old].b1]};
    }
    return {out, 0};
  }

  int simulate_covered(const vector<Rule> &rules, char start_dir) const {
    int M = (int)rules.size();
    if (M == 0) return 0;

    int r = start_r;
    int c = start_c;
    int d = dir_id(start_dir);
    int s = 0;

    vector<vector<char>> visited(N, vector<char>(N, 0));
    visited[r][c] = 1;
    int covered = 1;

    vector<char> seen(N * N * 4 * M, 0);
    auto key = [&](int rr, int cc, int dd, int ss) {
      return (((rr * N + cc) * 4 + dd) * M + ss);
    };

    static const int dr[4] = {-1, 0, 1, 0};
    static const int dc[4] = {0, 1, 0, -1};

    while (true) {
      bool wall = !can_move(r, c, d);
      int nr = r + dr[d];
      int nc = c + dc[d];

      const Rule &rule = rules[s];
      char act = wall ? rule.a1 : rule.a0;
      int ns = wall ? rule.b1 : rule.b0;

      if (act == 'F') {
        if (!wall) {
          r = nr;
          c = nc;
          if (!visited[r][c]) {
            visited[r][c] = 1;
            covered++;
          }
        }
      } else if (act == 'R') {
        d = (d + 1) & 3;
      } else {
        d = (d + 3) & 3;
      }
      s = ns;

      int k = key(r, c, d, s);
      if (seen[k]) break;
      seen[k] = 1;
    }

    return covered;
  }

  void try_candidate(const vector<int> &walk, long long &best_cost) {
    auto [rules, sd] = build_rules_from_walk(walk);
    auto [min_rules, min_start] = minimize_rules(rules, 0);
    (void)min_start;

    if (simulate_covered(min_rules, sd) != N * N) return;

    long long cost = 1LL * A_K + 1LL * A_M * (int)min_rules.size();
    if (cost < best_cost) {
      best_cost = cost;
      best_rules = min_rules;
      best_start_dir = sd;
    }
  }

  void solve() {
    long long best_cost = (1LL << 62);

    bool ok_rect = false;
    auto rect_walk = build_rect_route_walk(ok_rect);
    if (ok_rect && !rect_walk.empty()) {
      try_candidate(rect_walk, best_cost);
    }

    for (int rev = 0; rev < 2; rev++) {
      for (int right = 0; right < 2; right++) {
        bool ok = false;
        vector<int> walk = build_snake_like_walk(rev, right, ok);
        if (!ok || walk.empty()) continue;
        try_candidate(walk, best_cost);
      }
    }

    for (int prefer = 0; prefer < 4; prefer++) {
      vector<int> walk = build_direction_aware_walk(prefer);
      if (walk.empty()) continue;
      try_candidate(walk, best_cost);
    }

    if (best_rules.empty()) {
      best_rules = {{'R', 0, 'R', 0}};
      best_start_dir = 'U';
    }

    cout << 1 << '\n';
    cout << best_rules.size() << ' ' << start_r << ' ' << start_c << ' ' << best_start_dir << '\n';
    for (const auto &rule : best_rules) {
      cout << rule.a0 << ' ' << rule.b0 << ' ' << rule.a1 << ' ' << rule.b1 << '\n';
    }

    string zv(max(0, N - 1), '0');
    for (int i = 0; i < N; i++) cout << zv << '\n';
    string zh(N, '0');
    for (int i = 0; i < N - 1; i++) cout << zh << '\n';
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
