/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc385/submissions/60967694
 * Submitted at: 2024-12-21 21:42:39
 * Problem URL: https://atcoder.jp/contests/abc385/tasks/abc385_d
 * Result: AC
 * Execution Time: 359 ms
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

using P          = pair<ll, ll>;
map<char, P> dir = {
    {'U',  {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R',  {1, 0}}
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  map<ll, set<P>> row, col;
  vector<ll> x(n), y(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
    row[y[i]].insert(P(x[i], i));
    col[x[i]].insert(P(y[i], i));
  }
  set<ll> ans;

  rep(i, m) {
    char d;
    ll c;
    cin >> d >> c;
    auto [dx, dy] = dir[d];
    if(d == 'L' || d == 'R') {
      ll next_x = sx + dx * c;
      auto itr  = row[sy].lower_bound(P(min(sx, next_x), -1));
      vector<ll> tmp;
      // cerr << "sx: " << sx << ", next_x: " << next_x << '\n';
      while(itr != row[sy].end() && x[(*itr).second] <= max(sx, next_x)) {
        ll idx = (*itr).second;
        tmp.emplace_back(idx);
        itr++;
        // cerr << "idx: " << idx << '\n';
      }
      while(!tmp.empty()) {
        ll idx = tmp.back();
        ans.insert(idx);
        tmp.pop_back();
        row[y[idx]].erase(P(x[idx], idx));
        col[x[idx]].erase(P(y[idx], idx));
      }
    } else {
      ll next_y = sy + dy * c;
      auto itr  = col[sx].lower_bound(P(min(sy, next_y), -1));
      vector<ll> tmp;
      // cerr << "sy: " << sy << ", next_y: " << next_y << '\n';
      while(itr != col[sx].end() && y[(*itr).second] <= max(sy, next_y)) {
        ll idx = (*itr).second;
        tmp.emplace_back(idx);
        itr++;
        // cerr << "idx: " << idx << '\n';
      }
      while(!tmp.empty()) {
        ll idx = tmp.back();
        ans.insert(idx);
        tmp.pop_back();
        row[y[idx]].erase(P(x[idx], idx));
        col[x[idx]].erase(P(y[idx], idx));
      }
    }
    sx += dx * c;
    sy += dy * c;
    // cerr << "sx: " << sx << ", sy: " << sy << '\n';
  }
  cout << sx << ' ' << sy << ' ' << ans.size() << '\n';

  return 0;
}