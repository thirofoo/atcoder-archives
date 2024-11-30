/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc382/submissions/60312612
 * Submitted at: 2024-11-30 21:10:37
 * Problem URL: https://atcoder.jp/contests/abc382/tasks/abc382_c
 * Result: AC
 * Execution Time: 52 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  vector<ll> r_min(n + 1, INF);
  rep(i, n) r_min[i + 1] = min(r_min[i], a[i]);
  rep(i, m) {
    ll ok = n, ng = -1;
    while(ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      if(r_min[mid] <= b[i]) ok = mid;
      else ng = mid;
    }
    cout << (r_min[ok] <= b[i] ? ok : -1) << '\n';
  }

  return 0;
}