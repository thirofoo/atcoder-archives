/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71838152
 * Submitted at: 2025-12-20 21:10:35
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_c
 * Result: AC
 * Execution Time: 48 ms
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

  ll t;
  cin >> t;
  using P = pair<ll, ll>;
  while(t--) {
    ll n;
    cin >> n;
    vector<P> tonakai(n);
    ll total_w = 0, total_p = 0;
    rep(i, n) {
      ll w, p;
      cin >> w >> p;
      tonakai[i] = {w, p};
      total_w += w;
    }
    sort(tonakai.begin(), tonakai.end(), [](const P &a, const P &b) {
      auto &[w1, p1] = a;
      auto &[w2, p2] = b;
      return p1 + w1 > p2 + w2;
    });

    bool done = false;
    rep(i, n) {
      if(total_w <= total_p) {
        cout << n - i << "\n";
        done = true;
        break;
      }
      auto &[w, p] = tonakai[i];
      total_w -= w;
      total_p += p;
    }
    if(!done) cout << 0 << "\n";
  }

  return 0;
}