/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc386/submissions/61159569
 * Submitted at: 2024-12-28 21:17:17
 * Problem URL: https://atcoder.jp/contests/abc386/tasks/abc386_c
 * Result: RE
 * Execution Time: 75 ms
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

  ll k;
  string s, t;
  cin >> k >> s >> t;
  if(abs((int) s.size() - (int) t.size()) > 1) {
    cout << "No" << '\n';
    return 0;
  }

  ll ss = 0, st = 0;
  if(s.size() != t.size()) {
    if(s.size() < t.size()) swap(s, t);
    ll cnt = 0;
    while(ss < s.size() || st < t.size()) {
      if(ss == s.size() || st == t.size()) {
        ss++;
        st++;
        cnt++;
      } else if(s[ss] == t[st]) {
        ss++;
        st++;
      } else {
        ss++;
        cnt++;
      }
    }
    // cerr << cnt << '\n';
    cout << (cnt > 1 ? "No" : "Yes") << '\n';
  } else {
    ll cnt = 0;
    rep(i, s.size()) cnt += (s[i] != t[i]);
    cout << (cnt > 1 ? "No" : "Yes") << '\n';
  }

  return 0;
}