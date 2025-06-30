/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67199293
 * Submitted at: 2025-06-30 17:01:39
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cb
 * Result: AC
 * Execution Time: 61 ms
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

ll pow_mod(ll a, ll b, ll mod = (1LL << 61)) {
  ll res = 1;
  while(b > 0) {
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, d;
  cin >> n >> d;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = pow_mod(2, d);
  for(ll i = 1; i < (1LL << n); i++) {
    ll bit = 0;
    rep(j, n) if(i & (1LL << j)) bit |= a[j];
    ll pop_cnt = __builtin_popcountll(bit);
    ans += (1LL << (d - pop_cnt)) * (__builtin_popcountll(i) % 2 == 0 ? 1 : -1);
  }
  cout << ans << '\n';

  return 0;
}