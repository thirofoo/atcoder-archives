/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc383/submissions/60533285
 * Submitted at: 2024-12-07 22:04:20
 * Problem URL: https://atcoder.jp/contests/abc383/tasks/abc383_d
 * Result: AC
 * Execution Time: 25 ms
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

vector<bool> flags;
void eratosthenes(ll n) {
  flags.assign(n, true);
  flags[0]        = false;
  flags[1]        = false;
  const ll sqrt_n = ceil(sqrt(n) + 0.1);
  for(ll i = 2; i < sqrt_n; i++) {
    if(!flags[i]) continue;
    for(ll j = i * i; j < n; j += i) {
      flags[j] = false;
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  eratosthenes(3e6);
  vector<ll> primes = {1};
  rep(i, 3e6) if(flags[i]) primes.emplace_back(i);

  ll now = 2, ans = 0;
  for(ll i = 1; i < primes.size(); i++) {
    bool flag = true;
    ll ele    = 1;
    rep(_, 8) {
      ele *= primes[i];
      flag &= (ele <= n);
      if(!flag) break;
    }
    if(!flag) break;
    ans++;
  }

  for(ll i = 1; i < primes.size() && primes[i] * primes[i] <= n; i++) {
    ll ok = 0, ng = i;
    while(ng - ok > 1) {
      ll mid    = (ok + ng) / 2;
      ll ele    = primes[i] * primes[i];
      bool flag = true;
      ele *= primes[mid];
      flag &= (ele <= n);
      ele *= primes[mid];
      flag &= (ele <= n);

      if(flag) ok = mid;
      else ng = mid;
    }
    ans += ok;
  }
  cout << ans << '\n';

  return 0;
}