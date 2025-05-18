/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc047/submissions/65959232
 * Submitted at: 2025-05-18 22:41:00
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
    ans_next.assign(M, vector<int>(M, 0));
    
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

  using P = pair<int, int>;
  void solve() {
    rep(i, M) ans_c[i] = 'a' + (i % 6);
    // 全ての文字列の i → i + 1 を探索して、ローマ字 → ローマ字 の遷移があるかの one-hot を作成
    vector<vector<vector<int>>> one_hot(N, vector<vector<int>>(6, vector<int>(6, 0)));
    rep(i, N) rep(j, str[i].size()) one_hot[i][str[i][j] - 'a'][str[i][(j + 1) % str[i].size()] - 'a'] += 2;

    set<int> used;
    int best_p = -1, best_i = -1;
    rep(i, N) {
      if(prior[i] <= best_p || used.count(i)) continue;
      best_p = prior[i];
      best_i = i;
    }
    used.insert(best_i);
    rep(i, M) ans_c[i] = 'a' + (i % 6);
    rep(i, str[best_i].size()) ans_next[str[best_i][i] - 'a'][str[best_i][(i + 1) % str[best_i].size()] - 'a']++;
    if(str[best_i][0] != 'a') {
      ans_next[0][str[best_i][0] - 'a']++;
      ans_next[str[best_i][0] - 'a'][0]++;
    }
    // one-hot ベクトルの差が最も小さいものを選ぶ
    int best_diff = 1e9;
    rep(i, N) {
      if(used.count(i)) continue;
      int diff = 0;
      bool ng = false;
      rep(j, 6) rep(k, 6) {
        if(one_hot[best_i][j][k] != one_hot[i][j][k]) diff += (one_hot[best_i][j][k] - one_hot[i][j][k]) * (one_hot[best_i][j][k] - one_hot[i][j][k]);
        if(abs(one_hot[best_i][j][k] - one_hot[i][j][k]) > 1) ng = true;
      }
      if(ng) continue;
      diff *= prior[i];
      if(diff < best_diff) {
        best_diff = diff;
        best_i = i;
      }
    }
    // これを 0 ~ 5 に加える
    if(best_i != -1) {
      rep(i, str[best_i].size()) {
        if(ans_next[str[best_i][i] - 'a'][str[best_i][(i + 1) % str[best_i].size()]] != 0) continue;
        ans_next[str[best_i][i] - 'a'][str[best_i][(i + 1) % str[best_i].size()] - 'a']++;
      }
      used.insert(best_i);
    }



    best_p = -1, best_i = -1;
    rep(i, N) {
      if(prior[i] <= best_p || used.count(i)) continue;
      best_p = prior[i];
      best_i = i;
    }
    rep(i, str[best_i].size()) ans_next[str[best_i][i] - 'a' + 6][str[best_i][(i + 1) % str[best_i].size()] - 'a' + 6]++;
    ans_next[0][str[best_i][0] - 'a' + 6]++;
    ans_next[str[best_i][0] - 'a' + 6][0]++;
    // one-hot ベクトルの差が最も小さいものを選ぶ
    best_diff = 1e9;
    rep(i, N) {
      if(used.count(i)) continue;
      int diff = 0;
      bool ng = false;
      rep(j, 6) rep(k, 6) {
        if(one_hot[best_i][j][k] != one_hot[i][j][k]) diff += (one_hot[best_i][j][k] - one_hot[i][j][k]) * (one_hot[best_i][j][k] - one_hot[i][j][k]);
        if(abs(one_hot[best_i][j][k] - one_hot[i][j][k]) > 1) ng = true;
      }
      if(ng) continue;
      diff *= prior[i];
      if(diff < best_diff) {
        best_diff = diff;
        best_i = i;
      }
    }
    // これを 6 ~ 11 に加える
    if(best_i != -1) {
      rep(i, str[best_i].size()) {
        if(ans_next[str[best_i][i] - 'a' + 6][str[best_i][(i + 1) % str[best_i].size()] - 'a' + 6] != 0) continue;
        ans_next[str[best_i][i] - 'a' + 6][str[best_i][(i + 1) % str[best_i].size()] - 'a' + 6]++;
      }
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
