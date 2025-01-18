/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc389/submissions/61824712
 * Submitted at: 2025-01-18 22:10:30
 * Problem URL: https://atcoder.jp/contests/abc389/tasks/abc389_f
 * Result: TLE
 * Execution Time: 2762 ms
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  using P = pair<ll, ll>;
  ll n;
  cin >> n;
  vector<ll> l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];

  ll border    = 1000;
  ll num_block = (n + border - 1) / border;
  vector<vector<P>> blocks(num_block);
  rep(i, n) blocks[i / border].push_back({l[i], r[i]});

  ll q;
  cin >> q;
  while(q--) {
    ll x;
    cin >> x;
    rep(b, num_block) {
      for(auto [tl, tr]: blocks[b]) {
        if(x >= tl && x <= tr) x++;
      }
    }
    cout << x << "\n";
  }
  return 0;
}
