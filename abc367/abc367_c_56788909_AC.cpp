/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc367/submissions/56788909
 * Submitted at: 2024-08-17 21:10:48
 * Problem URL: https://atcoder.jp/contests/abc367/tasks/abc367_c
 * Result: AC
 * Execution Time: 54 ms
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

  ll n, k;
  cin >> n >> k;
  vector<ll> r(n);
  rep(i, n) cin >> r[i];

  vector<ll> perm;
  ll ans = 0;
  auto f = [&](auto self) {
    if(perm.size() == n) {
      ll sum = 0;
      rep(i, n) sum += perm[i];
      if(sum % k == 0) {
        rep(i, n) cout << perm[i] << ' ';
        cout << '\n';
      }
      return;
    }
    for(ll i = 1; i <= r[perm.size()]; i++) {
      perm.emplace_back(i);
      self(self);
      perm.pop_back();
    }
  };
  f(f);

  return 0;
}