/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc377/submissions/59193316
 * Submitted at: 2024-10-27 01:33:10
 * Problem URL: https://atcoder.jp/contests/abc377/tasks/abc377_e
 * Result: AC
 * Execution Time: 206 ms
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

ll pow_mod(ll a, ll b, ll mod) {
  ll result = 1;
  a         = a % mod;
  while(b > 0) {
    if(b & 1) result = result * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return result;
}

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
  vector<ll> ans(n);
  rep(i, n) {
    if(used[i]) continue;
    vector<ll> cycle;
    ll now = i;
    while(!used[now]) {
      cycle.emplace_back(now);
      used[now] = true;
      now       = p[now];
    }
    if(cycle.size() <= 1) {
      ans[cycle[0]] = cycle[0];
      continue;
    }

    ll size = cycle.size();
    ll rest = (pow_mod(2, k, size) - 1 + size) % size;
    for(auto ele: cycle) {
      // doubling
      now = p[ele];
      rep(j, 62) {
        if(!(rest & (1LL << j))) continue;
        now = next[j][now];
      }
      ans[ele] = now;
    }
  }
  rep(i, n) cout << ans[i] + 1 << " ";
  cout << '\n';

  return 0;
}
