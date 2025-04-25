/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/65189972
 * Submitted at: 2025-04-25 19:50:46
 * Problem URL: https://atcoder.jp/contests/abc399/tasks/abc399_e
 * Result: WA
 * Execution Time: 2 ms
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
  string s, t;
  cin >> s >> t;
  vector<char> check(26, '?');
  rep(i, n) {
    if(check[s[i] - 'a'] != '?') {
      if(check[s[i] - 'a'] != t[i]) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      check[s[i] - 'a'] = t[i];
    }
  }

  ll ans = 0, non_used_cnt = 0, cycle_cnt = 0;
  dsu uf(26);
  rep(i, 26) {
    if(check[i] == '?') non_used_cnt++;
    else if(check[i] != i + 'a') uf.merge(check[i] - 'a', i);
  }
  vector g = uf.groups();
  rep(i, g.size()) {
    if(g[i].size() == 1) continue;
    ans += g[i].size() + 1;
    cycle_cnt++;
  }
  cout << (cycle_cnt <= non_used_cnt ? ans : -1) << endl;

  return 0;
}