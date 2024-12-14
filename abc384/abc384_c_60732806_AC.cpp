/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc384/submissions/60732806
 * Submitted at: 2024-12-14 21:11:03
 * Problem URL: https://atcoder.jp/contests/abc384/tasks/abc384_c
 * Result: AC
 * Execution Time: 2 ms
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

  using P = pair<ll, string>;

  ll n = 5;
  vector<ll> score(n);
  rep(i, n) cin >> score[i];
  vector<vector<P>> ans(100000);
  rep(i, (1LL << n)) {
    if(i == 0) continue;
    ll now = 0;
    rep(j, n) {
      if(i & (1LL << j)) now += score[j];
    }
    string p = "";
    rep(j, n) {
      if(i & (1LL << j)) p += (char) ('A' + j);
    }
    ans[now].emplace_back(P{now, p});
  }
  rep(i, 100000) {
    if(ans[i].size() == 0) continue;
    sort(ans[i].begin(), ans[i].end());
  }
  for(ll i = 99999; i >= 0; i--) {
    if(ans[i].size() == 0) continue;
    for(auto p: ans[i]) {
      cout << p.second << '\n';
    }
  }

  return 0;
}
