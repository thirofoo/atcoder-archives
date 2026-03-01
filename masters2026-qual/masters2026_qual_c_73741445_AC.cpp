/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73741445
 * Submitted at: 2026-03-01 13:49:22
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_c
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;

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

  void solve() {
    const int K = N * N;
    cout << K << '\n';

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << 1 << ' ' << i << ' ' << j << ' ' << 'U' << '\n';
        cout << 'R' << ' ' << 0 << ' ' << 'R' << ' ' << 0 << '\n';
      }
    }

    string no_vertical(N - 1, '0');
    for (int i = 0; i < N; i++) {
      cout << no_vertical << '\n';
    }
    string no_horizontal(N, '0');
    for (int i = 0; i < N - 1; i++) {
      cout << no_horizontal << '\n';
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
