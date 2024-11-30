/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc382/submissions/60321808
 * Submitted at: 2024-11-30 21:25:58
 * Problem URL: https://atcoder.jp/contests/abc382/tasks/abc382_d
 * Result: AC
 * Execution Time: 184 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> ans;
  vector<vector<ll>> ans_list;
  auto f = [&](auto self, ll now, ll cnt) -> void {
    if(cnt == n + 1) {
      // rep(i, n) cout << ans[i] << " ";
      // cout << '\n';
      ans_list.emplace_back(ans);
      return;
    }
    ll add = 0;
    while(true) {
      if(now + add + 10 * (n - cnt) > m) break;
      ans.emplace_back(now + add);
      self(self, now + 10 + add, cnt + 1);
      add++;
      ans.pop_back();
    }
    return;
  };
  f(f, 1, 1);
  cout << ans_list.size() << '\n';
  for(auto &v: ans_list) {
    rep(i, n) cout << v[i] << " ";
    cout << '\n';
  }

  return 0;
}
