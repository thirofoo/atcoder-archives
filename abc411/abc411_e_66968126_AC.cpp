/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66968126
 * Submitted at: 2025-06-21 22:07:58
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_e
 * Result: AC
 * Execution Time: 336 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(6));
  vector<ll> comp;
  rep(i, n) {
    rep(j, 6) {
      cin >> a[i][j];
      comp.emplace_back(a[i][j]);
    }
    sort(a[i].begin(), a[i].end());
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  ll m = comp.size();
  vector<vector<ll>> idx(m);
  rep(i, n) {
    rep(j, 6) {
      a[i][j] = lower_bound(comp.begin(), comp.end(), a[i][j]) - comp.begin();
      idx[a[i][j]].emplace_back(i);
    }
  }

  vector<bool> ok(n, false);
  vector<mint> idx_cnt(n, 0);
  ll ok_cnt       = 0;
  mint prev_p_sum = 0, ans = 0, inv = mint(1) / mint(6).pow(n);
  rep(i, m) {
    mint p_sum = prev_p_sum;
    for(auto id: idx[i]) {
      ok_cnt += (!ok[id]);
      ok[id] = true;
      if(idx_cnt[id] != 0) p_sum /= idx_cnt[id];
      idx_cnt[id]++;
      p_sum *= idx_cnt[id];
    }
    if(ok_cnt == n) {
      if(prev_p_sum == 0) {
        p_sum = mint(1);
        rep(j, n) p_sum *= idx_cnt[j];
      }
      // cerr << "p_sum: " << p_sum.val() << endl;
      // cerr << "prev_p_sum: " << prev_p_sum.val() << endl << endl;
      ans += (p_sum - prev_p_sum) * comp[i] * inv;
      prev_p_sum = p_sum;
    }
  }
  cout << ans.val() << endl;

  return 0;
}