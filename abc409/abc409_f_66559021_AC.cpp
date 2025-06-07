/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66559021
 * Submitted at: 2025-06-07 21:58:02
 * Problem URL: https://atcoder.jp/contests/abc409/tasks/abc409_f
 * Result: AC
 * Execution Time: 246 ms
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

  ll n, q;
  cin >> n >> q;
  using P = pair<ll, ll>;
  vector<P> v(n);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    v[i] = {x, y};
  }
  using T = tuple<ll, ll, ll>;
  priority_queue<T, vector<T>, greater<T>> pq;
  rep(i, n) for(ll j = i + 1; j < n; j++) {
    auto [x1, y1] = v[i];
    auto [x2, y2] = v[j];
    ll dist       = abs(x1 - x2) + abs(y1 - y2);
    pq.push(T{dist, i, j});
  }

  dsu uf(n + q);
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll a, b;
      cin >> a >> b;
      rep(i, v.size()) {
        auto [x1, y1] = v[i];
        ll dist       = abs(x1 - a) + abs(y1 - b);
        pq.push(T{dist, i, v.size()});
      }
      v.emplace_back(a, b);
    } else if(t == 2) {
      if(uf.size(0) == v.size()) {
        cout << -1 << endl;
        continue;
      }
      while(!pq.empty()) {
        auto [dist, tu, tv] = pq.top();
        if(uf.same(tu, tv)) {
          pq.pop();
          continue;
        }
        break;
      }
      auto [dist, _, __] = pq.top();
      while(!pq.empty()) {
        auto [next_dist, next_u, next_v] = pq.top();
        if(next_dist != dist) break;
        // cerr << "Merging: " << next_u << " " << next_v << " with dist " << next_dist << endl;
        pq.pop();
        uf.merge(next_u, next_v);
      }
      cout << dist << endl;
    } else {
      ll tu, tv;
      cin >> tu >> tv;
      tu--, tv--;
      cout << (uf.same(tu, tv) ? "Yes" : "No") << endl;
    }
  }

  return 0;
}