/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/jsc2025advance-final/submissions/69099478
 * Submitted at: 2025-09-07 13:13:54
 * Problem URL: https://atcoder.jp/contests/jsc2025advance-final/tasks/abc422_b
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

// right | down | left | up
#define DIR_NUM 4
vector<ll> dx = {0, 1, 0, -1};
vector<ll> dy = {1, 0, -1, 0};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  bool ok = true;
  rep(i, h) {
    rep(j, w) {
      if(s[i][j] == '.') continue;
      ll cnt = 0;
      rep(d, DIR_NUM) {
        ll ni = i + dx[d], nj = j + dy[d];
        if(outField({ni, nj}, h, w)) continue;
        if(s[ni][nj] == '#') cnt++;
      }
      ok &= (cnt == 2 || cnt == 4);
    }
  }
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}