/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66519159
 * Submitted at: 2025-06-07 21:09:55
 * Problem URL: https://atcoder.jp/contests/abc409/tasks/abc409_c
 * Result: AC
 * Execution Time: 20 ms
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

  ll n, l;
  cin >> n >> l;
  vector<ll> d(n - 1), cnt(l, 0);
  ll now = 0;
  cnt[now]++;
  rep(i, n - 1) {
    cin >> d[i];
    now = (now + d[i]) % l;
    cnt[now]++;
  }
  if(l % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  rep(i, l / 3) {
    ll nx1 = i;
    ll nx2 = (i + l / 3) % l;
    ll nx3 = (i + 2 * l / 3) % l;
    ans += cnt[nx1] * cnt[nx2] * cnt[nx3];
  }
  cout << ans << endl;

  return 0;
}