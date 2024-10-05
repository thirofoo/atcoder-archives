/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc374/submissions/58454515
 * Submitted at: 2024-10-05 21:19:18
 * Problem URL: https://atcoder.jp/contests/abc374/tasks/abc374_d
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
using ld  = long double;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << setprecision(10) << fixed;

  ll n;
  ld s, t;
  cin >> n >> s >> t;
  vector<ld> a(n), b(n), c(n), d(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];

  ld ans = (1LL << 61);
  vector<ll> perm(n);
  iota(perm.begin(), perm.end(), 0);
  do {
    rep(i, (1LL << n)) {
      ld sx = 0.0, sy = 0.0, cand = 0.0, dis;
      rep(j, n) {
        if(i & (1LL << j)) {
          dis = (ld) sqrt((ld) (a[perm[j]] - sx) * (ld) (a[perm[j]] - sx) + (ld) (b[perm[j]] - sy) * (ld) (b[perm[j]] - sy));
          cand += dis / s;
          dis = (ld) sqrt((ld) (a[perm[j]] - c[perm[j]]) * (ld) (a[perm[j]] - c[perm[j]]) + (ld) (b[perm[j]] - d[perm[j]]) * (ld) (b[perm[j]] - d[perm[j]]));
          cand += dis / t;
          sx = c[perm[j]];
          sy = d[perm[j]];
        } else {
          dis = (ld) sqrt((ld) (c[perm[j]] - sx) * (ld) (c[perm[j]] - sx) + (ld) (d[perm[j]] - sy) * (ld) (d[perm[j]] - sy));
          cand += dis / s;
          dis = (ld) sqrt((ld) (a[perm[j]] - c[perm[j]]) * (ld) (a[perm[j]] - c[perm[j]]) + (ld) (b[perm[j]] - d[perm[j]]) * (ld) (b[perm[j]] - d[perm[j]]));
          cand += dis / t;
          sx = a[perm[j]];
          sy = b[perm[j]];
        }
      }
      ans = min(ans, cand);
    }
  } while(next_permutation(perm.begin(), perm.end()));
  cout << ans << endl;

  return 0;
}