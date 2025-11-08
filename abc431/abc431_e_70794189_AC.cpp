/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc431/submissions/70794189
 * Submitted at: 2025-11-08 22:02:38
 * Problem URL: https://atcoder.jp/contests/abc431/tasks/abc431_e
 * Result: AC
 * Execution Time: 28 ms
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
vector<ll> dx  = {0, 1, 0, -1};
vector<ll> dy  = {1, 0, -1, 0};
vector<ll> rdx = {1, 0, 3, 2};
vector<ll> rdy = {3, 2, 1, 0};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  using T = tuple<ll, ll, ll>;

  while(t--) {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<ll> dist(h * w * 4, INF);
    deque<T> dq;
    dist[0] = 0;
    dq.push_back({0, 0, 0});
    ll ans = INF;

    while(!dq.empty()) {
      auto [i, j, d_in] = dq.front();
      dq.pop_front();
      ll v = (i * w + j) * 4 + d_in;
      if(dist[v] >= ans) continue;

      rep(k, 3) {
        char c  = (k == 0 ? 'A' : (k == 1 ? 'B' : 'C'));
        ll cost = (s[i][j] == c ? 0 : 1);
        ll d_out;
        if(k == 0) d_out = d_in;
        else if(k == 1) d_out = rdx[d_in];
        else d_out = rdy[d_in];

        ll ni = i + dx[d_out], nj = j + dy[d_out];
        if(outField({ni, nj}, h, w)) {
          if(i == h - 1 && j == w - 1 && d_out == 0) {
            ll nd = dist[v] + cost;
            if(nd < ans) ans = nd;
          }
          continue;
        }

        ll to = (ni * w + nj) * 4 + d_out;
        ll nd = dist[v] + cost;
        if(nd < dist[to]) {
          dist[to] = nd;
          if(cost == 0) dq.push_front(T(ni, nj, d_out));
          else dq.push_back(T(ni, nj, d_out));
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
