/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc377/submissions/59193534
 * Submitted at: 2024-10-27 01:46:16
 * Problem URL: https://atcoder.jp/contests/abc377/tasks/abc377_e
 * Result: AC
 * Execution Time: 270 ms
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

  ll n, k;
  cin >> n >> k;
  vector<ll> p(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }

  // 最初の配列において doubling
  vector<vector<ll>> next(63, vector<ll>(n));
  rep(i, n) next[0][i]                = p[i];
  rep(i, 62) rep(j, n) next[i + 1][j] = next[i][next[i][j]];

  vector<bool> used(n, false);
  rep(i, n) {
    if(used[i]) continue;
    vector<ll> cycle;
    ll now = i;
    while(!used[now]) {
      cycle.emplace_back(now);
      used[now] = true;
      now       = p[now];
    }
    if(cycle.size() <= 1) continue;
    ll size = cycle.size();

    ll to = 2, cnt = 0, tmp = 1;
    while((1LL << cnt) <= k) {
      if(k & (1LL << cnt)) tmp = (tmp * to) % size;
      to = (to * to) % size;
      cnt++;
    }
    ll rest = tmp;

    for(auto ele: cycle) {
      // doubling
      now                                  = ele;
      rep(j, 63) if(rest & (1LL << j)) now = next[j][now];
      p[ele]                               = now;
    }
  }
  rep(i, n) cout << p[i] + 1 << " ";
  cout << '\n';

  return 0;
}
