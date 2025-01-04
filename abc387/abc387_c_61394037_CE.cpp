/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc387/submissions/61394037
 * Submitted at: 2025-01-04 22:23:49
 * Problem URL: https://atcoder.jp/contests/abc387/tasks/abc387_c
 * Result: CE
 * Execution Time: None ms
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

ll dp[20][11][20][2];
bool used[20][11][20][2];

ll dfs(const vector<ll> &d, ll pos, ll lead, ll cnt, ll tight) {
  if(pos == (ll) d.size()) return cnt >= 2;
  if(used[pos][lead][cnt][tight]) return dp[pos][lead][cnt][tight];
  used[pos][lead][cnt][tight] = true;
  ll r = 0;
  ll lim = tight ? d[pos] : 9;
  rep(x, lim + 1) {
    ll nt = tight && (x == lim);
    if(lead == 10){
      if(x == 0) r += dfs(d, pos + 1, 10, 0, nt);
      else r += dfs(d, pos + 1, x, 1, nt);
    } else {
      if(x < lead) r += dfs(d, pos + 1, lead, cnt + 1, nt);
    }
  }
  return dp[pos][lead][cnt][tight] = r;
}

ll f(ll X) {
  if(X < 10) return 0;
  vector<ll> d;
  while(X > 0) {
    d.emplace_back(X % 10);
    X /= 10;
  }
  reverse(d.begin(), d.end());
  rep(i, 20) rep(j, 11) rep(k, 20) rep(l, 2) dp[i][j][k][l] = 0;
  rep(i, 20) rep(j, 11) rep(k, 20) rep(l, 2) used[i][j][k][l] = false;
  return dfs(d, 0, 10, 0, 1);
}

ll main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll L, R;
  cin >> L >> R;
  cout << f(R) - f(L-1) << "\n";
  
  return 0;
}
