/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc371/submissions/57742818
 * Submitted at: 2024-09-14 21:08:12
 * Problem URL: https://atcoder.jp/contests/abc371/tasks/abc371_b
 * Result: AC
 * Execution Time: 1 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), cnt(n, 0);
  vector<char> b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    if(b[i] == 'M') {
      cout << (cnt[a[i]] == 0 ? "Yes" : "No") << '\n';
      cnt[a[i]]++;
    } else cout << "No" << '\n';
  }

  return 0;
}