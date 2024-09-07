/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc370/submissions/57518482
 * Submitted at: 2024-09-07 21:10:55
 * Problem URL: https://atcoder.jp/contests/abc370/tasks/abc370_c
 * Result: AC
 * Execution Time: 1 ms
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

  string s, t;
  cin >> s >> t;
  vector<pair<ll, ll>> p;
  rep(i, s.size()) {
    if(s[i] == t[i]) continue;
    ll v1 = (s[i] < t[i] ? 1 : 0);
    ll v2 = (v1 == 0 ? 1 : -1) * i;
    p.emplace_back(pair{v1, v2});
  }
  sort(p.begin(), p.end());
  cout << p.size() << '\n';
  for(auto [v1, v2]: p) {
    if(v2 < 0) v2 *= -1;
    s[v2] = t[v2];
    cout << s << '\n';
  }

  return 0;
}