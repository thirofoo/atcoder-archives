/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc370/submissions/57546815
 * Submitted at: 2024-09-07 22:13:26
 * Problem URL: https://atcoder.jp/contests/abc370/tasks/abc370_d
 * Result: AC
 * Execution Time: 1179 ms
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

// up | down | left | right
#define DIR_NUM 4
vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, -1, 1};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w, q;
  cin >> h >> w >> q;
  set<pair<ll, ll>> bombed;
  vector<set<ll>> row(h), col(w);

  auto bomb = [&](ll r, ll c) {
    bombed.insert({r, c});
    row[r].erase(c);
    col[c].erase(r);
    rep(d, DIR_NUM) {
      ll nx = r + dx[d];
      ll ny = c + dy[d];
      if(outField({nx, ny}, h, w) || bombed.count({nx, ny})) continue;
      row[nx].insert(ny);
      col[ny].insert(nx);
    }
  };

  while(q--) {
    ll r, c;
    cin >> r >> c;
    r--;
    c--;
    if(!bombed.count({r, c})) bomb(r, c);
    else {
      auto itr1 = row[r].lower_bound(c);
      auto itr2 = row[r].upper_bound(c);
      auto itr3 = col[c].lower_bound(r);
      auto itr4 = col[c].upper_bound(r);
      if(itr1 != row[r].begin()) {
        itr1--;
        bomb(r, *itr1);
      }
      if(itr2 != row[r].end()) bomb(r, *itr2);
      if(itr3 != col[c].begin()) {
        itr3--;
        bomb(*itr3, c);
      }
      if(itr4 != col[c].end()) bomb(*itr4, c);
    }

    // for(auto [nr, nc]: bombed) {
    //   cout << nr << ' ' << nc << '\n';
    // }
    // cout << '\n';
  }
  cout << h * w - bombed.size() << '\n';

  return 0;
}