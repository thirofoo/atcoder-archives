/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc439/submissions/72172736
 * Submitted at: 2026-01-03 21:05:32
 * Problem URL: https://atcoder.jp/contests/abc439/tasks/abc439_c
 * Result: AC
 * Execution Time: 132 ms
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
  vector<ll> cnt(n + 1, 0);
  for(ll x = 1; x * x <= n; x++) {
    for(ll y = x + 1; x * x + y * y <= n; y++) {
      cnt[x * x + y * y]++;
    }
  }

  vector<ll> ans;
  rep(i, n + 1) {
    if(cnt[i] != 1) continue;
    ans.emplace_back(i);
  }
  cout << ans.size() << "\n";
  for(auto v: ans) cout << v << " ";
  cout << "\n";

  return 0;
}