/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64755007
 * Submitted at: 2025-04-12 21:24:27
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_d
 * Result: WA
 * Execution Time: 3 ms
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

  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  rep(i, n) {
    if(s[i] == 'o') {
      if(i != 0) s[i - 1] = '.';
      if(i != n - 1) s[i + 1] = '.';
    }
  }
  using P = pair<ll, ll>;
  vector<P> ans;
  ll left = -1, max_ans = 0;
  rep(i, n) {
    if(s[i] == '?') {
      if(left == -1) left = i;
    } else {
      if(s[i] == 'o') max_ans++;
      if(left != -1) {
        ans.push_back({left, i});
        max_ans += (i - left + 1) / 2;
        left = -1;
      }
    }
  }
  if(left != -1) {
    ans.push_back({left, n});
    max_ans += (n - left + 1) / 2;
  }
  if(max_ans != k) {
    cout << s << endl;
    return 0;
  }
  // cerr << "max_ans: " << max_ans << endl;
  for(auto [l, r]: ans) {
    if((r - l) % 2 == 0) continue;
    for(ll idx = l; idx < r; idx++) {
      if((idx - l) % 2 == 0) s[idx] = 'o';
      else s[idx] = '.';
    }
  }
  cout << s << endl;

  return 0;
}