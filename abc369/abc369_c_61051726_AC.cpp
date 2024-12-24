/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc369/submissions/61051726
 * Submitted at: 2024-12-24 14:30:44
 * Problem URL: https://atcoder.jp/contests/abc369/tasks/abc369_c
 * Result: AC
 * Execution Time: 14 ms
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
  rep(i, n) cin >> a[i];
  vector<ll> fact(n + 1, 1), r_fact(n + 1, 1);
  for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
  auto nC2 = [](ll num) {
    return num * (num - 1) / 2;
  };

  ll tousa = INF, cnt = 0, ans = n;
  rep(left, n - 1) {
    if(tousa != a[left + 1] - a[left]) {
      ans += nC2(cnt);
      tousa = a[left + 1] - a[left];
      cnt   = 2;
    } else cnt++;
  }
  ans += nC2(cnt);
  cout << ans << '\n';

  return 0;
}