/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc368/submissions/57060498
 * Submitted at: 2024-08-24 21:33:34
 * Problem URL: https://atcoder.jp/contests/abc368/tasks/abc368_f
 * Result: AC
 * Execution Time: 92 ms
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

// 約数列挙 (1, n も含む)
vector<ll> divisor(ll n) {
  vector<ll> div;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i) continue;
    div.emplace_back(i);
    if(i != n / i) div.emplace_back(n / i);
  }
  return div;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> grundy(100005, 0);
  for(ll i = 2; i <= 100000; i++) {
    set<ll> s;
    vector<ll> div = divisor(i);
    for(auto &&d: div) {
      if(d == i) continue;
      s.insert(grundy[d]);
    }
    ll g = 0;
    while(s.count(g)) g++;
    grundy[i] = g;
  }
  ll ans = 0;
  rep(i, n) ans ^= grundy[a[i]];
  cout << (ans ? "Anna" : "Bruno") << '\n';

  return 0;
}