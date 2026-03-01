/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73741943
 * Submitted at: 2026-03-01 14:07:24
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Segment {
  int l;
  int r;
};

struct Rect {
  int top;
  int bottom;
  int left;
  int right;
};

struct Rule {
  char a0;
  int b0;
  char a1;
  int b1;
};

struct Robot {
  int i;
  int j;
  char d;
  vector<Rule> rules;
};

struct Solver {
  int N;
  int A_K, A_M, A_W;
  vector<string> v, h;

  vector<vector<Segment>> row_segments;
  vector<Rect> rects;
  vector<Robot> robots;
  vector<string> add_v, add_h;

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

  void build_row_segments() {
    row_segments.assign(N, {});
    for (int i = 0; i < N; i++) {
      int left = 0;
      for (int j = 0; j < N - 1; j++) {
        if (v[i][j] == '1') {
          row_segments[i].push_back({left, j});
          left = j + 1;
        }
      }
      row_segments[i].push_back({left, N - 1});
    }
  }

  int find_same_segment_unused(int row, int l, int r, const vector<vector<bool>> &used) const {
    for (int idx = 0; idx < (int)row_segments[row].size(); idx++) {
      if (used[row][idx]) {
        continue;
      }
      if (row_segments[row][idx].l == l && row_segments[row][idx].r == r) {
        return idx;
      }
    }
    return -1;
  }

  bool can_connect_rows(int row, int l, int r) const {
    for (int c = l; c <= r; c++) {
      if (h[row][c] == '1') {
        return false;
      }
    }
    return true;
  }

  void build_rectangles() {
    rects.clear();
    vector<vector<bool>> used(N);
    for (int r = 0; r < N; r++) {
      used[r].assign(row_segments[r].size(), false);
    }

    for (int r = 0; r < N; r++) {
      for (int idx = 0; idx < (int)row_segments[r].size(); idx++) {
        if (used[r][idx]) {
          continue;
        }
        int l = row_segments[r][idx].l;
        int rr = row_segments[r][idx].r;

        vector<pair<int, int>> picked;
        picked.push_back({r, idx});
        int bottom = r;

        while (bottom + 1 < N) {
          int nxt_idx = find_same_segment_unused(bottom + 1, l, rr, used);
          if (nxt_idx == -1) {
            break;
          }
          if (!can_connect_rows(bottom, l, rr)) {
            break;
          }
          bottom++;
          picked.push_back({bottom, nxt_idx});
        }

        for (auto [row, seg_idx] : picked) {
          used[row][seg_idx] = true;
        }
        rects.push_back({r, bottom, l, rr});
      }
    }
  }

  void build_added_walls() {
    add_v.assign(N, string(N - 1, '0'));
    add_h.assign(N - 1, string(N, '0'));

    for (const auto &rect : rects) {
      int top = rect.top;
      int bottom = rect.bottom;
      int left = rect.left;
      int right = rect.right;

      if (top > 0) {
        for (int c = left; c <= right; c++) {
          add_h[top - 1][c] = '1';
        }
      }
      if (bottom < N - 1) {
        for (int c = left; c <= right; c++) {
          add_h[bottom][c] = '1';
        }
      }
      if (left > 0) {
        for (int r = top; r <= bottom; r++) {
          add_v[r][left - 1] = '1';
        }
      }
      if (right < N - 1) {
        for (int r = top; r <= bottom; r++) {
          add_v[r][right] = '1';
        }
      }
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
    if (b.first == a.first - 1 && b.second == a.second) {
      return 0;
    }
    if (b.first == a.first && b.second == a.second + 1) {
      return 1;
    }
    if (b.first == a.first + 1 && b.second == a.second) {
      return 2;
    }
    return 3;
  }

  vector<pair<int, int>> build_snake_path(const Rect &rect) {
    vector<pair<int, int>> path;
    int hgt = rect.bottom - rect.top + 1;
    int wid = rect.right - rect.left + 1;

    if (hgt == 1) {
      for (int c = rect.left; c <= rect.right; c++) {
        path.push_back({rect.top, c});
      }
      return path;
    }
    if (wid == 1) {
      for (int r = rect.top; r <= rect.bottom; r++) {
        path.push_back({r, rect.left});
      }
      return path;
    }

    for (int r = rect.top; r <= rect.bottom; r++) {
      int rel = r - rect.top;
      if (rel % 2 == 0) {
        for (int c = rect.left; c <= rect.right; c++) {
          path.push_back({r, c});
        }
      } else {
        for (int c = rect.right; c >= rect.left; c--) {
          path.push_back({r, c});
        }
      }
    }
    return path;
  }

  Robot build_robot_for_rect(const Rect &rect) {
    auto path = build_snake_path(rect);

    if ((int)path.size() == 1) {
      Robot rb;
      rb.i = path[0].first;
      rb.j = path[0].second;
      rb.d = 'U';
      rb.rules.push_back({'R', 0, 'R', 0});
      return rb;
    }

    vector<pair<int, int>> walk;
    for (int i = 0; i < (int)path.size(); i++) {
      walk.push_back(path[i]);
    }
    for (int i = (int)path.size() - 2; i >= 0; i--) {
      walk.push_back(path[i]);
    }

    vector<int> move_dirs;
    for (int i = 0; i + 1 < (int)walk.size(); i++) {
      move_dirs.push_back(step_dir(walk[i], walk[i + 1]));
    }

    int init_dir = move_dirs[0];
    int cur_dir = init_dir;
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

    Robot rb;
    rb.i = walk[0].first;
    rb.j = walk[0].second;
    rb.d = dir_char(init_dir);

    int m = (int)actions.size();
    rb.rules.resize(m);
    for (int s = 0; s < m; s++) {
      int nxt = (s + 1) % m;
      if (actions[s] == 'F') {
        rb.rules[s] = {'F', nxt, 'R', nxt};
      } else {
        rb.rules[s] = {actions[s], nxt, actions[s], nxt};
      }
    }
    return rb;
  }

  void build_robots() {
    robots.clear();
    robots.reserve(rects.size());
    for (const auto &rect : rects) {
      robots.push_back(build_robot_for_rect(rect));
    }
  }

  void solve() {
    build_row_segments();
    build_rectangles();
    build_added_walls();
    build_robots();

    cout << robots.size() << '\n';
    for (const auto &rb : robots) {
      cout << rb.rules.size() << ' ' << rb.i << ' ' << rb.j << ' ' << rb.d << '\n';
      for (const auto &rule : rb.rules) {
        cout << rule.a0 << ' ' << rule.b0 << ' ' << rule.a1 << ' ' << rule.b1 << '\n';
      }
    }

    for (int i = 0; i < N; i++) {
      cout << add_v[i] << '\n';
    }
    for (int i = 0; i < N - 1; i++) {
      cout << add_h[i] << '\n';
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
