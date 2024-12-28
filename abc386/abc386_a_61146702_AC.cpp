/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc386/submissions/61146702
 * Submitted at: 2024-12-28 21:04:44
 * Problem URL: https://atcoder.jp/contests/abc386/tasks/abc386_a
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

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  map<ll, ll> mp;
  mp[a]++;
  mp[b]++;
  mp[c]++;
  mp[d]++;
  vector<ll> v;
  for(auto [key, value]: mp) v.emplace_back(value);
  bool flag = (v.size() == 2 && ((v[0] == 2 && v[1] == 2) || (v[0] == 1 && v[1] == 3)) || (v[0] == 3 && v[1] == 1));
  cout << (flag ? "Yes" : "No") << '\n';

  return 0;
}