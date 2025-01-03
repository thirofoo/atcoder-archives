/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc110/submissions/61344532
 * Submitted at: 2025-01-03 23:41:36
 * Problem URL: https://atcoder.jp/contests/abc110/tasks/abc110_c
 * Result: AC
 * Execution Time: 30 ms
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

  string s, t;
  cin >> s >> t;
  vector<ll> taiou(26);
  iota(taiou.begin(), taiou.end(), 0);
  ll time = 30;
  while(time--) {
    rep(i, s.size()) {
      if(taiou[s[i] - 'a'] == t[i] - 'a') continue;
      swap(taiou[s[i] - 'a'], taiou[t[i] - 'a']);
    }
  }
  string test = "";
  rep(i, s.size()) test += (char) ('a' + taiou[s[i] - 'a']);
  // cerr << test << endl;
  cout << (t == test ? "Yes" : "No") << endl;
  return 0;
}