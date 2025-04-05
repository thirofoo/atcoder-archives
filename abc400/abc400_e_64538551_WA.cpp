/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64538551
 * Submitted at: 2025-04-05 21:51:59
 * Problem URL: https://atcoder.jp/contests/abc400/tasks/abc400_e
 * Result: WA
 * Execution Time: 251 ms
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

  ll q;
  cin >> q;
  eratosthenes(1e6 + 5);
  vector<ll> squares;
  for(ll i = 1; i * i <= 1e12; i++) {
    if(flags[i]) continue;
    squares.emplace_back(i * i);
  }
  while(q--) {
    ll a;
    cin >> a;
    auto it = upper_bound(squares.begin(), squares.end(), a);
    it--;
    cout << *it << endl;
  }

  return 0;
}