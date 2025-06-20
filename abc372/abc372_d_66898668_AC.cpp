/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc372/submissions/66898668
 * Submitted at: 2025-06-20 16:57:23
 * Problem URL: https://atcoder.jp/contests/abc372/tasks/abc372_d
 * Result: AC
 * Execution Time: 112 ms
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

  ll n;
  cin >> n;
  vector<ll> h(n), imos(n + 1, 0);
  using P = pair<ll, ll>;
  vector<P> p;
  rep(i, n) {
    cin >> h[i];
    p.emplace_back(P(h[i], i));
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  set<ll> big_idx;
  big_idx.insert(-1);
  for(auto [v, idx]: p) {
    auto itr = big_idx.lower_bound(idx);
    itr--;
    imos[*itr + 1]++;
    imos[idx + 1]--;
    big_idx.insert(idx);
  }
  rep(i, n) {
    imos[i + 1] += imos[i];
    cout << imos[i + 1] << " ";
  }
  cout << "\n";

  return 0;
}