/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc377/submissions/59160722
 * Submitted at: 2024-10-26 21:07:28
 * Problem URL: https://atcoder.jp/contests/abc377/tasks/abc377_c
 * Result: AC
 * Execution Time: 943 ms
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

vector<ll> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<ll> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m);
  set<pair<ll, ll>> s;
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    s.insert({a[i], b[i]});
  }
  rep(i, m) {
    rep(j, 8) {
      ll x = a[i] + dx[j];
      ll y = b[i] + dy[j];
      if(outField({x, y}, n, n)) continue;
      s.insert({x, y});
    }
  }
  cout << n * n - s.size() << '\n';

  return 0;
}
