/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65245945
 * Submitted at: 2025-04-27 21:06:55
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_c
 * Result: AC
 * Execution Time: 154 ms
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

  ll n, m, q;
  cin >> n >> m >> q;
  vector<set<ll>> qual(n);
  vector<bool> all_qual(n, false);
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x, y;
      cin >> x >> y;
      x--;
      qual[x].insert(y);
    } else if(t == 2) {
      ll x;
      cin >> x;
      x--;
      all_qual[x] = true;
    } else {
      ll x, y;
      cin >> x >> y;
      x--;
      cout << (qual[x].count(y) || all_qual[x] ? "Yes" : "No") << endl;
    }
  }

  return 0;
}