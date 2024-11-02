/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc378/submissions/59359438
 * Submitted at: 2024-11-02 21:11:25
 * Problem URL: https://atcoder.jp/contests/abc378/tasks/abc378_c
 * Result: AC
 * Execution Time: 98 ms
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  map<ll, ll> mp;
  rep(i, n) {
    if(!mp.count(a[i])) cout << -1 << " ";
    else cout << mp[a[i]] << " ";
    mp[a[i]] = i + 1;
  }
  cout << endl;

  return 0;
}