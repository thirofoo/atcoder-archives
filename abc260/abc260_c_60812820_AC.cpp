/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/60812820
 * Submitted at: 2024-12-15 22:38:11
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_c
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

  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> red_memo(n + 1, -1), blue_memo(n + 1, -1);
  red_memo[1]  = 0;
  blue_memo[1] = 1;
  auto dfs     = [&](auto self, ll num, bool is_red) -> ll {
    if(is_red) {
      if(red_memo[num] != -1) return red_memo[num];
      return red_memo[num] = self(self, num - 1, true) + self(self, num, false) * x;
    } else {
      if(blue_memo[num] != -1) return blue_memo[num];
      return blue_memo[num] = self(self, num - 1, true) + self(self, num - 1, false) * y;
    }
  };
  dfs(dfs, n, true);
  cout << red_memo[n] << '\n';
  return 0;
}