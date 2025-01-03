/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc031/submissions/61341075
 * Submitted at: 2025-01-03 21:23:01
 * Problem URL: https://atcoder.jp/contests/abc031/tasks/abc031_d
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll k, n;
  cin >> k >> n;
  vector<string> v(n), w(n);
  rep(i, n) cin >> v[i] >> w[i];

  bool ok = false;
  vector<ll> nums;
  auto dfs = [&](auto self) -> void {
    if(nums.size() == k) {
      vector<string> fixed(k, "");
      rep(i, n) {
        ll start = 0;
        rep(j, v[i].size()) {
          ll num_idx = v[i][j] - '1';
          string str = "";
          rep(l, nums[num_idx]) {
            if(start + l >= w[i].size()) return;
            str += w[i][start + l];
          }
          if(fixed[num_idx] != "" && fixed[num_idx] != str) return;
          fixed[num_idx] = str;
          // cerr << "str: " << str << endl;
          start += nums[num_idx];
        }
        if(start != w[i].size()) return;
      }
      rep(i, k) cout << fixed[i] << endl;
      ok = true;
      return;
    }
    for(ll i = 1; i <= 3; i++) {
      nums.emplace_back(i);
      self(self);
      if(ok) return;
      nums.pop_back();
    }
  };
  dfs(dfs);

  return 0;
}
