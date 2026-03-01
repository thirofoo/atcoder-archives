/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73741443
 * Submitted at: 2026-03-01 13:49:17
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Robot {
  int i;
  int j;
  char d;
};

struct Solver {
  int N;
  int A_K, A_M, A_W;
  vector<string> v, h;

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
    robots.clear();
    for (int i = 0; i < N; i++) {
      int left = 0;
      for (int j = 0; j < N - 1; j++) {
        if (v[i][j] == '1') {
          robots.push_back({i, left, 'R'});
          left = j + 1;
        }
      }
      robots.push_back({i, left, 'R'});
    }
  }

  void build_added_walls() {
    add_v.assign(N, string(N - 1, '0'));
    add_h.assign(N - 1, string(N, '1'));
  }

  void solve() {
    build_row_segments();
    build_added_walls();

    cout << robots.size() << '\n';
    for (const auto &rb : robots) {
      cout << 1 << ' ' << rb.i << ' ' << rb.j << ' ' << rb.d << '\n';
      cout << 'F' << ' ' << 0 << ' ' << 'R' << ' ' << 0 << '\n';
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