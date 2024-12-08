/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc189/submissions/60588024
 * Submitted at: 2024-12-08 21:38:24
 * Problem URL: https://atcoder.jp/contests/arc189/tasks/arc189_a
 * Result: AC
 * Execution Time: 30 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

  vector<mint> fact(n + 1, 1), r_fact(n + 1, 1);
  for(int i = 1; i <= n; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }
  auto nCr = [&](ll num, ll r) {
    return fact[num] * r_fact[r] * r_fact[num - r];
  };
  auto nHr = [&](ll num, ll r) {
    return nCr(num + r - 1, r);
  };

  bool ng = false;
  ng |= (a[0] != 1 || a.back() != (n % 2));

  ll len = 1, pre = a[0], cnt = 0, size = 0;
  mint ans = 1;

  for(ll i = 1; i < n; i++) {
    if(a[i] == pre) len++;
    else {
      if(len % 2 == 0) {
        ng = true;
        break;
      }
      cnt = len - 2;
      while(cnt >= 1) {
        ans *= cnt;
        cnt -= 2;
      }
      ans *= nHr(size + 1, len / 2);
      // cerr << "len: " << len << " size: " << size << " ans: " << ans.val() << '\n';
      size += len / 2;

      len = 1;
      pre = a[i];
    }
  }
  cnt = len - 2;
  while(cnt >= 1) {
    ans *= cnt;
    cnt -= 2;
  }
  ans *= nHr(size + 1, len / 2);

  if(ng) return cout << 0 << '\n', 0;
  cout << ans.val() << '\n';

  return 0;
}