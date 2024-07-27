/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/56004708
 * Submitted at: 2024-07-27 21:05:31
 * Problem URL: https://atcoder.jp/contests/abc364/tasks/abc364_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

inline bool outField(int x, int y, int h, int w) {
    if(0 <= x && x < h && 0 <= y && y < w) return false;
    return true;
}

// right | down | left | up
#define DIR_NUM 4
// right | down | left | up
using P = pair<int, int>;
map<char, P> dir = {{'R', { 0, 1}},
                    {'D', { 1, 0}},
                    {'L', { 0,-1}},
                    {'U', {-1, 0}}};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll h, w; cin >> h >> w;
  ll si, sj; cin >> si >> sj; si--, sj--;
  vector<string> c(h);
  rep(i, h) cin >> c[i];
  string x; cin >> x;
  rep(i, x.size()) {
    P d = dir[x[i]];
    ll nx = si + d.first, ny = sj + d.second;
    if(outField(nx, ny, h, w) || c[nx][ny] == '#') continue;
    si = nx, sj = ny;
  }
  cout << si + 1 << ' ' << sj + 1 << '\n';
  
  return 0;
}