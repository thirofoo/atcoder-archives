/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc416/submissions/67924612
 * Submitted at: 2025-07-26 21:11:35
 * Problem URL: https://atcoder.jp/contests/abc416/tasks/abc416_c
 * Result: AC
 * Execution Time: 29 ms
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

  ll n, k, x;
  cin >> n >> k >> x;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<string> cand;
  auto dfs = [&](auto&& self, ll idx, string now) -> void {
    if(idx == k) {
      cand.emplace_back(now);
      return;
    }
    rep(i, n) self(self, idx + 1, now + s[i]);
    return;
  };
  dfs(dfs, 0, "");

  sort(cand.begin(), cand.end());
  x--;
  cout << cand[x] << endl;

  return 0;
}