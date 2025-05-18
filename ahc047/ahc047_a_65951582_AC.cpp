/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc047/submissions/65951582
 * Submitted at: 2025-05-18 20:25:34
 * Problem URL: https://atcoder.jp/contests/ahc047/tasks/ahc047_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < n; i++)

namespace utility {
struct timer {
  chrono::system_clock::time_point start;
  // 開始時間を記録
  void CodeStart() { start = chrono::system_clock::now(); }
  // 経過時間 (ms) を返す
  double elapsed() const {
    using namespace chrono;
    return (double)duration_cast<milliseconds>(system_clock::now() - start)
        .count();
  }
} mytm;
} // namespace utility

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629,
                      tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty, ty = tz, tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

inline double rand_double() { return (double)(rand_int() % (int)1e9) / 1e9; }

// 温度関数
#define TIME_LIMIT 1900
inline double temp(double start) {
  double start_temp = 100, end_temp = 1;
  return start_temp + (end_temp - start_temp) *
                          ((utility::mytm.elapsed() - start) / TIME_LIMIT);
}

// 焼きなましの採用確率
inline double prob(int best, int now, int start) {
  return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

struct Solver {
  int N, M, L;
  vector<string> str;
  vector<int> prior;
  vector<vector<int>> next;

  vector<char> ans_c;
  vector<vector<int>> ans_next;

  Solver() {
    this->input();
    next.assign(N, vector<int>(N, 1));
    ans_c.assign(M, ' ');
    rep(i, M) ans_c[i] = 'a' + (i % 6);
    ans_next.assign(M, vector<int>(M, 1));
    
    utility::mytm.CodeStart();
    return;
  }

  inline vector<int> normalizeIntArrayToSum100(const vector<int>& arr_orig) {
    int n = arr_orig.size();
    if (n == 0) return {};
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = max(0, arr_orig[i]);
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    vector<int> res(n, 0);
    if (sum == 0) {
      res[0] = 100;
      return res;
    }
    vector<double> exact(n);
    for (int i = 0; i < n; ++i) {
      exact[i] = (double)arr[i] * 100.0 / sum;
      res[i] = (int)floor(exact[i] + 0.5);
    }
    int cur = accumulate(res.begin(), res.end(), 0);
    int diff = 100 - cur;
    vector<pair<double,int>> frac(n);
    for (int i = 0; i < n; ++i) frac[i] = { exact[i] - res[i], i };
    if (diff > 0) {
      sort(frac.begin(), frac.end(), greater<>());
      for (int k = 0; k < diff; ++k) ++res[frac[k % n].second];
    } else if (diff < 0) {
      sort(frac.begin(), frac.end());
      int to_remove = -diff, k = 0;
      for (; k < to_remove && k < n; ++k) {
        int i = frac[k].second;
        if (res[i] > 0) --res[i];
      }
      if (k < to_remove) {
        for (int i = 0; i < n && k < to_remove; ++i) {
          if (res[i] > 0) {
            --res[i];
            ++k;
          }
        }
      }
    }
    int fs = accumulate(res.begin(), res.end(), 0);
    if (fs != 100) {
      int adj = 100 - fs;
      for (int i = 0; i < n; ++i) {
        if (res[i] + adj >= 0) {
          res[i] += adj;
          break;
        }
      }
    }
    return res;
  }

  vector<double> solveLinearEquations(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    if (n == 0 || A[0].size() != n || b.size() != n) return {};
    vector<vector<double>> aug(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) aug[i][j] = A[i][j];
      aug[i][n] = b[i];
    }
    for (int i = 0; i < n; ++i) {
      int piv = i;
      for (int k = i + 1; k < n; ++k)
        if (fabs(aug[k][i]) > fabs(aug[piv][i])) piv = k;
      if (fabs(aug[piv][i]) < 1e-9) return {};
      swap(aug[i], aug[piv]);
      double v = aug[i][i];
      for (int j = i; j <= n; ++j) aug[i][j] /= v;
      for (int k = 0; k < n; ++k) if (k != i) {
        double f = aug[k][i];
        for (int j = i; j <= n; ++j) aug[k][j] -= f * aug[i][j];
      }
    }
    vector<double> sol(n);
    for (int i = 0; i < n; ++i) sol[i] = aug[i][n];
    return sol;
  }

  vector<double> calculateStationaryDistribution(const vector<vector<double>>& T) {
    int M = T.size();
    if (M == 0 || T[0].size() != M) return {};
    vector<vector<double>> mat(M, vector<double>(M));
    vector<double> rhs(M);
    for (int j = 0; j < M; ++j) {
      for (int i = 0; i < M; ++i)
        mat[j][i] = T[i][j] + (i == j ? -1.0 : 0.0);
    }
    for (int j = 0; j < M; ++j) mat[M - 1][j] = 1.0;
    rhs[M - 1] = 1.0;
    auto dist = solveLinearEquations(mat, rhs);
    if (!dist.empty()) {
      double sum = 0;
      for (int i = 0; i < M; ++i) {
        dist[i] = max(0.0, dist[i]);
        sum += dist[i];
      }
      if (sum < 1e-6) return {};
      for (int i = 0; i < M; ++i) dist[i] /= sum;
    }
    return dist;
  }

  void input() {
    cin >> N >> M >> L;
    str.resize(N);
    prior.resize(N);
    rep(i, N) cin >> str[i] >> prior[i];
    return;
  }

  void output() {
    rep(i, M) {
      cout << ans_c[i] << " ";
      ans_next[i] = normalizeIntArrayToSum100(ans_next[i]);
      rep(j, M) cout << ans_next[i][j] << " ";
      cout << '\n';
    }
    return;
  }

  void solve() {
    int itr = 2;
    set<int> used;
    vector<vector<int>> idx(6);

    rep(i, itr) {
      int best_p = -1, best_i = -1;
      rep(i, N) {
        if(prior[i] <= best_p || used.count(i)) continue;
        best_p = prior[i];
        best_i = i;
      }
      rep(j, str[best_i].size()) {
        if(i == 0) {
          ans_c[j] = str[best_i][j];
          ans_next[j][(j + 1) % M] += prior[best_i] * (itr - i);
          idx[str[best_i][j] - 'a'].emplace_back(j);
        } else {
          for(auto now : idx[str[best_i][j] - 'a']) {
            for(auto to : idx[str[best_i][(j + 1) % M] - 'a']) {
              ans_next[now][to] += prior[best_i] * (itr - i);
            }
          }
        }
      }
      used.insert(best_i);
    }
    rep(i, M) ans_next[i] = normalizeIntArrayToSum100(ans_next[i]);

    return;
  }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  Solver solver;
  solver.solve();
  solver.output();

  return 0;
}
