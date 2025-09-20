/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc424/submissions/69462630
 * Submitted at: 2025-09-20 21:05:25
 * Problem URL: https://atcoder.jp/contests/abc424/tasks/abc424_b
 * Result: AC
 * Execution Time: 2 ms
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

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(k), b(k);

  vector<set<ll>> g(n);
  vector<bool> flag(n, false);

  rep(i, k) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    g[a[i]].insert(b[i]);
    if(!flag[a[i]] && g[a[i]].size() >= m) {
      cout << a[i] + 1 << " ";
      flag[a[i]] = true;
    }
  }
  cout << "\n";

  return 0;
}