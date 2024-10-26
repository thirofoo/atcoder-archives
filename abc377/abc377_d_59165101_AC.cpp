/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc377/submissions/59165101
 * Submitted at: 2024-10-26 21:12:38
 * Problem URL: https://atcoder.jp/contests/abc377/tasks/abc377_d
 * Result: AC
 * Execution Time: 183 ms
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
  vector<ll> l(n), r(n);
  vector<vector<ll>> lr(m, vector<ll>{});
  multiset<ll> s;
  rep(i, n) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
    s.insert(r[i]);
    lr[l[i]].emplace_back(r[i]);
  }
  ll ans = 0;
  rep(i, m) {
    if(s.empty()) {
      ans += m - i;
      continue;
    }
    auto it = s.begin();
    ans += (*it) - i;
    for(auto &&j: lr[i]) s.erase(s.find(j));
  }
  cout << ans << '\n';

  return 0;
}
