/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2016-qualb/submissions/67024498
 * Submitted at: 2025-06-23 19:30:52
 * Problem URL: https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_c
 * Result: AC
 * Execution Time: 30 ms
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

  ll w, h;
  cin >> w >> h;
  vector<ll> p_col(w), p_row(h);
  rep(i, w) cin >> p_col[i];
  rep(i, h) cin >> p_row[i];
  vector<ll> pc(w, 0), pr(h, 0);
  iota(pc.begin(), pc.end(), 0);
  iota(pr.begin(), pr.end(), 0);
  sort(pc.begin(), pc.end(), [&](ll i, ll j) {
    return p_col[i] < p_col[j];
  });
  sort(pr.begin(), pr.end(), [&](ll i, ll j) {
    return p_row[i] < p_row[j];
  });

  ll ans = 0, idx_c = 0, idx_r = 0;
  while(idx_c < w || idx_r < h) {
    if(idx_c < w && (idx_r == h || p_col[pc[idx_c]] < p_row[pr[idx_r]])) {
      ans += p_col[pc[idx_c]] * (h - idx_r + 1);
      idx_c++;
    } else {
      ans += p_row[pr[idx_r]] * (w - idx_c + 1);
      idx_r++;
    }
  }
  cout << ans << endl;

  return 0;
}