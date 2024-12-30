/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc050/submissions/61255024
 * Submitted at: 2024-12-30 22:52:58
 * Problem URL: https://atcoder.jp/contests/abc050/tasks/arc066_a
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
using ll   = long long;
using ull  = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n), cnt(1e5 + 5, 0);
  bool ng = false;
  rep(i, n) {
    cin >> a[i];
    cnt[a[i]]++;
    ng |= (cnt[a[i]] > 2);
  }
  ng |= (n % 2 == 1 && cnt[0] > 1);
  if(ng) {
    cout << 0 << '\n';
    return 0;
  }
  cout << mint(2).pow(n / 2).val() << '\n';

  return 0;
}