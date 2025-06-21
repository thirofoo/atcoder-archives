/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66986032
 * Submitted at: 2025-06-22 00:52:13
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_d
 * Result: AC
 * Execution Time: 35 ms
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

  ll n, q;
  cin >> n >> q;
  using T = tuple<ll, ll, string>;
  vector<T> queries(q);
  rep(i, q) {
    ll t, p;
    cin >> t >> p;
    if(t == 2) {
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      queries[i] = {t, p - 1, s};
    } else {
      queries[i] = {t, p - 1, ""};
    }
  }
  reverse(queries.begin(), queries.end());
  // 最後の Server に関するものだけ考慮する (それ以外無視)
  string ans     = "";
  ll related_idx = n; // Server に逆順で足していく時の行先
  rep(i, q) {
    auto [t, p, s] = queries[i];
    if(t == 1) {
      if(related_idx == p) related_idx = n;
    } else if(t == 2) {
      if(related_idx == p) ans += s;
    } else if(t == 3) {
      if(related_idx == n) related_idx = p;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}
