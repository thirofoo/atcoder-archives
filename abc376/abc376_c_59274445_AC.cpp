/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc376/submissions/59274445
 * Submitted at: 2024-10-30 18:52:33
 * Problem URL: https://atcoder.jp/contests/abc376/tasks/abc376_c
 * Result: AC
 * Execution Time: 790 ms
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

  ll n;
  cin >> n;
  vector<ll> a(n), b(n - 1);
  rep(i, n) cin >> a[i];
  rep(i, n - 1) cin >> b[i];
  sort(a.begin(), a.end());

  ll left = 0, right = INF;
  while(right - left > 1) {
    ll mid         = (right + left) / 2;
    vector<ll> tmp = b;
    tmp.emplace_back(mid);
    sort(tmp.begin(), tmp.end());
    bool ok = true;
    rep(i, n) {
      ok &= (a[i] <= tmp[i]);
      // cerr << tmp[i] << " ";
    }
    // cerr << endl;
    if(ok) right = mid;
    else left = mid;
  }
  cout << (right != INF ? right : -1) << endl;

  return 0;
}