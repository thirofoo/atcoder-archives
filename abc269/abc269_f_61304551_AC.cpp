/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/61304551
 * Submitted at: 2025-01-02 01:39:12
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_f
 * Result: AC
 * Execution Time: 550 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll   = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m, q;
  cin >> n >> m >> q;
  auto calc_tousa = [&](ll start, ll end, ll num) -> mint {
    return (mint) (start + end) * num / 2;
  };
  auto calc_rect = [&](ll x, ll y) -> mint {
    if(x == 0 || y == 0) return (mint) 0;
    mint res = 0;
    // 1. j の部分
    res += (x / 2) * calc_tousa(1, y, y);
    if(x % 2) res += calc_tousa(1, (y - (y + 1) % 2), (y + 1) / 2);
    // 2. (i - 1) * M の部分
    res += ((y + 1) / 2) * m * calc_tousa(0, x - 2 + (x % 2), (x + 1) / 2);
    res += (y / 2) * m * calc_tousa(1, x - 1 - (x % 2), x / 2);
    return res;
  };

  while(q--) {
    ll x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    mint ans = calc_rect(x2, y2) - calc_rect(x2, y1 - 1) - calc_rect(x1 - 1, y2) + calc_rect(x1 - 1, y1 - 1);
    cout << ans.val() << endl;
  }

  return 0;
}