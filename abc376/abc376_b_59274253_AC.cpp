/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc376/submissions/59274253
 * Submitted at: 2024-10-30 18:44:50
 * Problem URL: https://atcoder.jp/contests/abc376/tasks/abc376_b
 * Result: AC
 * Execution Time: 3 ms
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
  ll left = 0, right = 1, ans = 0;
  while(q--) {
    char h;
    ll t;
    cin >> h >> t;
    t--;
    ll m1   = min((h == 'R' ? right : left), t);
    ll m2   = max((h == 'R' ? right : left), t);
    ll cand = abs((h == 'R' ? right : left) - t);
    if(m1 <= (h == 'R' ? left : right) && (h == 'R' ? left : right) <= m2) cand = n - cand;
    // cerr << "m1: " << m1 << " m2: " << m2 << " cand: " << cand << endl;
    ans += cand;
    (h == 'R' ? right : left) = t;
  }
  cout << ans << endl;

  return 0;
}