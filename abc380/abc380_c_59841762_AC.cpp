/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59841762
 * Submitted at: 2024-11-16 21:12:02
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_c
 * Result: AC
 * Execution Time: 14 ms
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
  string s;
  cin >> n >> k >> s;

  vector<bool> ks(s.size(), false);
  ll cnt = 0, pre = 0, num = 0, start = 0;
  rep(i, n) {
    if(pre == 0 && s[i] == '1') {
      cnt++;
      if(cnt == k - 1) start = i;
    }
    if(cnt == k && s[i] == '1') {
      ks[i] = true;
      num++;
    }
    pre = s[i] - '0';
  }
  rep(i, n) {
    if(ks[i]) continue;
    if(start == i)
      while(num--) cout << 1;
    cout << s[i];
  }
  cout << endl;

  return 0;
}