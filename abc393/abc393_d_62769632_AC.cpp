/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc393/submissions/62769632
 * Submitted at: 2025-02-15 21:10:20
 * Problem URL: https://atcoder.jp/contests/abc393/tasks/abc393_d
 * Result: AC
 * Execution Time: 19 ms
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
  string s;
  cin >> s;
  vector<ll> idx;
  rep(i, n) if(s[i] == '1') idx.emplace_back(i);

  ll left = 0, right = n - idx.size() + 1;
  while(right - left > 2) {
    ll m1 = (left + right) / 2, m2 = m1 + 1;
    ll s1 = 0, s2 = 0;
    rep(i, idx.size()) {
      s1 += abs(idx[i] - (m1 + i));
      s2 += abs(idx[i] - (m2 + i));
    }
    if(s1 < s2) right = m2;
    else left = m1;
  }
  ll ans = INF;
  for(ll i = max(0LL, left - 5); i < min(n - (ll) idx.size() + 1, right + 5); i++) {
    ll sum = 0;
    rep(j, idx.size()) sum += abs(idx[j] - (i + j));
    ans = min(ans, sum);
  }
  cout << ans << '\n';

  return 0;
}