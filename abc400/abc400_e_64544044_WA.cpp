/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64544044
 * Submitted at: 2025-04-05 22:04:37
 * Problem URL: https://atcoder.jp/contests/abc400/tasks/abc400_e
 * Result: WA
 * Execution Time: 346 ms
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

vector<ll> div_cand;
void eratosthenes(ll n) {
  div_cand.assign(n, 1);
  for(int i = 1; i < n; i++) div_cand[i] = i;
  const ll sqrt_n = ceil(sqrt(n) + 0.1);
  for(ll i = 2; i < sqrt_n; i++) {
    if(div_cand[i] != i) continue;
    for(ll j = i; j < n; j += i) div_cand[j] = i;
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll q;
  cin >> q;
  eratosthenes(1e6 + 5);
  vector<ll> squares;
  for(ll i = 6; i * i <= 1e12; i++) {
    ll tmp = i * i;
    while(tmp % div_cand[i] == 0) {
      // cerr << i << " " << div_cand[i] << endl;
      tmp /= div_cand[i];
    }
    if(tmp == 1) continue;
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