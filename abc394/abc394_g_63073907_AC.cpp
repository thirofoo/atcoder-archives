/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63073907
 * Submitted at: 2025-02-23 01:44:16
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_g
 * Result: AC
 * Execution Time: 1441 ms
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
  vector<vector<ll>> f(h, vector<ll>(w));
  vector<tuple<ll, ll, ll>> height;
  rep(i, h) rep(j, w) {
    cin >> f[i][j];
    height.emplace_back(f[i][j], i, j);
  }
  sort(height.begin(), height.end(), greater<tuple<ll, ll, ll>>());

  ll q;
  cin >> q;
  vector<ll> a(q), b(q), y(q), c(q), d(q), z(q);
  rep(i, q) {
    cin >> a[i] >> b[i] >> y[i] >> c[i] >> d[i] >> z[i];
    a[i]--, b[i]--, c[i]--, d[i]--;
  }

  vector<ll> ok(q, 0), ng(q, INF);
  while(true) {
    bool finish = true;
    vector<pair<ll, ll>> mid_idx;
    rep(i, q) {
      if(ng[i] - ok[i] > 1) {
        finish = false;
        mid_idx.emplace_back((ok[i] + ng[i]) / 2, i);
      }
    }
    if(finish) break;
    sort(mid_idx.begin(), mid_idx.end(), greater<pair<ll, ll>>());

    dsu uf(h * w);
    ll h_idx = 0;
    for(auto [mid, idx]: mid_idx) {
      // cerr << "mid: " << mid << ", idx: " << idx << endl;
      while(h_idx < height.size()) {
        auto [th, tx, ty] = height[h_idx];
        if(th < mid) break;
        rep(dir, DIR_NUM) {
          ll nx = tx + dx[dir], ny = ty + dy[dir];
          if(outField({nx, ny}, h, w)) continue;
          if(f[nx][ny] >= f[tx][ty]) uf.merge(tx * w + ty, nx * w + ny);
        }
        h_idx++;
      }
      if(uf.same(a[idx] * w + b[idx], c[idx] * w + d[idx])) ok[idx] = mid;
      else ng[idx] = mid;
    }
  }
  rep(i, q) {
    ll bottom = min({ok[i], y[i], z[i]});
    cout << y[i] + z[i] - bottom * 2 << endl;
    // cerr << "ok: " << ok[i] << ", ng: " << ng[i] << endl;
  }

  return 0;
}