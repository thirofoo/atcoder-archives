/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc384/submissions/60736243
 * Submitted at: 2024-12-14 21:15:23
 * Problem URL: https://atcoder.jp/contests/abc384/tasks/abc384_d
 * Result: AC
 * Execution Time: 27 ms
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

  ll n, s;
  cin >> n >> s;
  ll sum = 0;

  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  rep(i, n) a.emplace_back(a[i]);
  s %= sum;
  vector<ll> rui(a.size() + 1, 0);
  rep(i, a.size()) rui[i + 1] = rui[i] + a[i];

  bool ans = false;
  rep(l, n) {
    ll left = l, right = a.size();
    while(right - left > 1) {
      ll mid = (left + right) / 2;
      if(rui[mid] - rui[l] <= s) left = mid;
      else right = mid;
    }
    ans |= (rui[left] - rui[l] == s);
    if(ans) break;
  }
  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}
