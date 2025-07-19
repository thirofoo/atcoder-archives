/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67721079
 * Submitted at: 2025-07-19 21:15:25
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_c
 * Result: AC
 * Execution Time: 47 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s       = "0" + s;
    ll size = s.size();
    vector<bool> dp(size, false);
    dp[0] = true;
    rep(i, size - 1) {
      if(s[i] == '1' || !dp[i]) continue;
      rep(j, n) {
        ll next = i | (1LL << j);
        if(s[next] == '1') continue;
        dp[next] = true;
      }
    }
    // rep(i, size + 1) cerr << dp[i] << " ";
    // cerr << endl;
    cout << (dp.back() ? "Yes" : "No") << endl;
  }

  return 0;
}