/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66534956
 * Submitted at: 2025-06-07 21:24:17
 * Problem URL: https://atcoder.jp/contests/abc409/tasks/abc409_d
 * Result: AC
 * Execution Time: 21 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    string s;
    cin >> n >> s;
    ll idx = -1;
    rep(i, n - 1) {
      if(s[i + 1] < s[i]) {
        idx = i;
        break;
      }
    }
    if(idx == -1) {
      cout << s << endl;
      continue;
    }
    char c = s[idx];
    ll j  = idx + 1;
    while(j < n && s[j] <= c) ++j;
    string res;
    res.reserve(n);
    res.append(s.begin(), s.begin() + idx);
    res.append(s.begin() + idx + 1, s.begin() + j);
    res += c;
    res.append(s.begin() + j, s.end());
    cout << res << endl;
  }

  return 0;
}
