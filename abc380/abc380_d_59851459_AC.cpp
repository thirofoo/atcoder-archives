/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59851459
 * Submitted at: 2024-11-16 21:28:42
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_d
 * Result: AC
 * Execution Time: 26 ms
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

  string s;
  ll q;
  cin >> s >> q;
  vector<ll> k(q);
  rep(i, q) {
    cin >> k[i];
    ll pop_cnt = __builtin_popcountll((k[i] - 1) / s.size()) % 2;
    char ans   = s[(k[i] - 1) % s.size()];
    if(pop_cnt) {
      if('a' <= ans && ans <= 'z') ans = toupper(ans);
      else ans = tolower(ans);
    }
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}