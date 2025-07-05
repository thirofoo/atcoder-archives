/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67342328
 * Submitted at: 2025-07-05 22:09:59
 * Problem URL: https://atcoder.jp/contests/abc413/tasks/abc413_g
 * Result: WA
 * Execution Time: 372 ms
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
#define DIR_NUM 8
vector<ll> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<ll> dy = {1, 0, -1, 0, 1, -1, 1, -1};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w, k;
  cin >> h >> w >> k;
  using P = pair<ll, ll>;
  vector<P> ps(k);
  set<P> st;
  rep(i, k) {
    ll r, c;
    cin >> r >> c;
    r--, c--;
    ps[i] = {r, c};
    st.insert({r, c});
  }

  // rep(i, h) {
  //   rep(j, w) cerr << (st.count({i, j}) ? "1" : "0") << " ";
  //   cerr << endl;
  // }

  queue<P> q;
  rep(i, k) {
    auto [r, c] = ps[i];
    if(r == 0) q.push({r, c});
  }
  set<P> visited;
  bool ng = false;
  while(!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    // cerr << "r: " << r << ", c: " << c << endl;
    ng |= (r == h - 1 || c == 0);
    rep(dir, DIR_NUM) {
      ll nr = r + dx[dir];
      ll nc = c + dy[dir];
      if(outField({nr, nc}, h, w) || !st.count({nr, nc}) || visited.count({nr, nc})) continue;
      q.push({nr, nc});
      visited.insert({nr, nc});
    }
  }

  visited.clear();
  rep(i, k) {
    auto [r, c] = ps[i];
    if(c == 0) q.push({r, c});
  }
  while(!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    // cerr << "r: " << r << ", c: " << c << endl;
    ng |= (r == 0 || c == w - 1);
    rep(dir, DIR_NUM) {
      ll nr = r + dx[dir];
      ll nc = c + dy[dir];
      if(outField({nr, nc}, h, w) || !st.count({nr, nc}) || visited.count({nr, nc})) continue;
      q.push({nr, nc});
      visited.insert({nr, nc});
    }
  }

  cout << (ng ? "No" : "Yes") << endl;

  return 0;
}