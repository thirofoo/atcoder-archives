/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65470529
 * Submitted at: 2025-05-03 22:25:43
 * Problem URL: https://atcoder.jp/contests/abc404/tasks/abc404_e
 * Result: WA
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<ll> c(n), a(n);
  rep(i, n - 1) cin >> c[i + 1];
  rep(i, n - 1) cin >> a[i + 1];

  vector<ll> f(n, INF);
  deque<pair<ll, ll>> dq;
  f[0] = 0;
  dq.emplace_back(0, 0);
  for(ll i = 1; i < n; i++) {
    ll start = max(0LL, i - c[i]);
    while(!dq.empty() && dq.front().second < start) dq.pop_front();
    f[i] = dq.front().first + 1;
    while(!dq.empty() && dq.back().first >= f[i]) dq.pop_back();
    dq.emplace_back(f[i], i);
  }

  map<ll, ll> m;
  for(ll i = 1; i < n; i++)
    if(a[i] > 0) m[i] = a[i];

  ll ops = 0;
  while(!m.empty()) {
    auto it         = prev(m.end());
    auto [idx, cnt] = *it;
    m.erase(it);
    ops++;

    ll start = max(0LL, idx - c[idx]), end = idx - 1;
    ll best = start, bestF = f[start];
    for(ll j = start + 1; j <= end; j++) {
      if(f[j] < bestF) {
        bestF = f[j];
        best  = j;
      }
    }
    if(best > 0) m[best] += cnt;
  }
  cout << ops << endl;

  return 0;
}
