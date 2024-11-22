/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/60050548
 * Submitted at: 2024-11-22 21:18:09
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_d
 * Result: AC
 * Execution Time: 13 ms
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
  vector<ll> a(n), cnt(n, 0);
  rep(i, n) cin >> a[i];

  ll l = 0, r = 0, ans = 0;
  while(l < n) {
    if(r <= n - 2 && a[r] == a[r + 1] && cnt[a[r]] == 0) {
      r += 2;
      cnt[a[r - 1]] += 2;
    } else {
      if(l != r) {
        cnt[a[l]]--;
        cnt[a[l + 1]]--;
      }
      l += 2;
      r = max(r, l);
      if(r == l) {
        r--;
        l--;
      }
    }
    ans = max(ans, r - l);
  }
  cout << ans << '\n';

  return 0;
}