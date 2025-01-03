/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc031/submissions/61336516
 * Submitted at: 2025-01-03 17:25:14
 * Problem URL: https://atcoder.jp/contests/abc031/tasks/abc031_d
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll k, n;
  cin >> k >> n;
  vector<string> num(n), str(n);
  vector<vector<vector<ll>>> pattern(n);
  rep(i, n) {
    cin >> num[i] >> str[i];

    vector<ll> cand;
    ll div = num[i].size(), total_ch = str[i].size();
    auto enum_divide = [&](auto self, ll sum_ch) -> void {
      if(cand.size() == div) {
        if(sum_ch == total_ch) {
          pattern[i].emplace_back(cand);
          // rep(j, cand.size()) cerr << cand[j] << " ";
          // cerr << endl;
        }
        return;
      }
      // 以降全てに 3 文字以上を割り当てても間に合わない場合 (枝狩り)
      if(total_ch - sum_ch > 3 * (div - cand.size())) return;
      for(ll size = 1; size <= 3; size++) {
        if(total_ch < size + sum_ch) continue;
        cand.emplace_back(size);
        self(self, sum_ch + size);
        cand.pop_back();
      }
      return;
    };
    enum_divide(enum_divide, 0LL);
  }

  vector<string> fixed(k + 1, "");
  bool ok  = false;
  auto dfs = [&](auto self, ll idx) -> void {
    if(ok) return;
    // rep(i, k + 1) cerr << i << ": " << fixed[i] << endl;
    // cerr << endl;
    if(idx == n) {
      ok = true;
      rep(i, k) cout << fixed[i + 1] << endl;
      return;
    }

    vector<string> store = fixed;
    for(auto&& ps: pattern[idx]) {
      ll now_idx = 0;
      bool flag  = true;
      rep(ps_idx, ps.size()) {
        string tmp = "";
        rep(i, ps[ps_idx]) tmp += str[idx][now_idx + i];
        if(fixed[num[idx][ps_idx] - '0'] != "" && fixed[num[idx][ps_idx] - '0'] != tmp) {
          flag = false;
          break;
        }
        fixed[num[idx][ps_idx] - '0'] = tmp;
        now_idx += ps[ps_idx];
      }

      if(flag) self(self, idx + 1);
      if(ok) return;
      fixed = store;
    }
    return;
  };
  dfs(dfs, 0);

  return 0;
}