/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66528938
 * Submitted at: 2025-06-07 21:18:11
 * Problem URL: https://atcoder.jp/contests/abc409/tasks/abc409_d
 * Result: WA
 * Execution Time: 20 ms
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

    ll left = -1;
    rep(i, n - 1) {
      if(s[i] < s[i + 1]) continue;
      left = i;
      break;
    }
    if(left == -1) {
      cout << s << endl;
      continue;
    }
    rep(i, left) cout << s[i];
    ll right = n - 1;
    for(ll i = left + 1; i < n; i++) {
      if(s[i] > s[left]) {
        right = i;
        cout << s[left];
        break;
      }
      cout << s[i];
    }
    if(right == n - 1) cout << s[left];
    else
      for(ll i = right; i < n; i++) cout << s[i];
    cout << endl;
  }

  return 0;
}