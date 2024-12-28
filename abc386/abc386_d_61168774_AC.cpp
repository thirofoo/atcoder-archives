/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc386/submissions/61168774
 * Submitted at: 2024-12-28 21:30:41
 * Problem URL: https://atcoder.jp/contests/abc386/tasks/abc386_d
 * Result: AC
 * Execution Time: 92 ms
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

  using T = tuple<ll, ll, char>;

  ll n, m;
  cin >> n >> m;
  vector<T> v;
  rep(i, m) {
    ll x, y;
    char c;
    cin >> x >> y >> c;
    x--, y--;
    v.emplace_back(T(x, y, c));
  }
  sort(v.begin(), v.end());

  set<ll> white_col;
  white_col.insert(INF);
  rep(i, m) {
    auto [x, y, c] = v[i];
    if(c == 'W') white_col.insert(y);
    else {
      ll ele = *white_col.begin();
      if(ele <= y) return cout << "No" << '\n', 0;
    }
  }
  cout << "Yes" << '\n';

  return 0;
}