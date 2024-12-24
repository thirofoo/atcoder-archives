/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc369/submissions/61051674
 * Submitted at: 2024-12-24 14:26:12
 * Problem URL: https://atcoder.jp/contests/abc369/tasks/abc369_b
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

  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<char> s(n);
  ll sr = -1, sl = -1;
  ll ans = 0;
  rep(i, n) {
    cin >> a[i] >> s[i];
    if(s[i] == 'L' && sl == -1) sl = a[i];
    if(s[i] == 'R' && sr == -1) sr = a[i];
    if(s[i] == 'L') {
      ans += abs(a[i] - sl);
      sl = a[i];
    } else {
      ans += abs(a[i] - sr);
      sr = a[i];
    }
  }
  cout << ans << '\n';

  return 0;
}