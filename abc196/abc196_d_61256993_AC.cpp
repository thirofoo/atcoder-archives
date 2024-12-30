/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc196/submissions/61256993
 * Submitted at: 2024-12-31 00:12:21
 * Problem URL: https://atcoder.jp/contests/abc196/tasks/abc196_d
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

  ll h, w, a, b;
  cin >> h >> w >> a >> b;
  vector<vector<bool>> used(h, vector<bool>(w, false));
  ll ans   = 0;
  auto dfs = [&](auto self, ll p, ll cnt_a, ll cnt_b) -> void {
    if(p == h * w) {
      ans++;
      return;
    }
    auto [x, y] = make_pair(p / w, p % w);
    if(used[x][y]) return self(self, p + 1, cnt_a, cnt_b);
    if(y + 1 < w && !used[x][y + 1] && cnt_a > 0) {
      used[x][y] = used[x][y + 1] = true;
      self(self, p + 1, cnt_a - 1, cnt_b);
      used[x][y] = used[x][y + 1] = false;
    }
    if(x + 1 < h && !used[x + 1][y] && cnt_a > 0) {
      used[x][y] = used[x + 1][y] = true;
      self(self, p + 1, cnt_a - 1, cnt_b);
      used[x][y] = used[x + 1][y] = false;
    }
    if(cnt_b > 0) {
      used[x][y] = true;
      self(self, p + 1, cnt_a, cnt_b - 1);
      used[x][y] = false;
    }
    return;
  };
  dfs(dfs, 0, a, b);
  cout << ans << '\n';

  return 0;
}