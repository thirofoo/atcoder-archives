/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc356/submissions/61343870
 * Submitted at: 2025-01-03 23:12:51
 * Problem URL: https://atcoder.jp/contests/abc356/tasks/abc356_c
 * Result: AC
 * Execution Time: 6 ms
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

  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> keys(m, 0);
  vector<char> eval(m);
  rep(i, m) {
    ll c;
    cin >> c;
    rep(j, c) {
      ll a;
      cin >> a;
      keys[i] |= (1LL << (a - 1));
    }
    cin >> eval[i];
  }
  ll ans = 0;
  rep(i, (1LL << n)) {
    bool flag = true;
    rep(j, m) {
      ll cnt = __builtin_popcount((unsigned long) (keys[j] & i));
      flag &= ((eval[j] == 'o' && cnt >= k) || (eval[j] == 'x' && cnt < k));
    }
    if(flag) {
      ans++;
      // cerr << i << endl;
    }
  }
  cout << ans << endl;

  return 0;
}