/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc385/submissions/60951035
 * Submitted at: 2024-12-21 21:10:59
 * Problem URL: https://atcoder.jp/contests/abc385/tasks/abc385_c
 * Result: AC
 * Execution Time: 8 ms
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
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  ll ans = 1;
  for(ll dis = 1; dis < n; dis++) {
    for(ll start = 0; start < dis; start++) {
      ll now = start + dis, cnt = 1;
      while(now < n) {
        if(h[now - dis] == h[now]) {
          cnt++;
        } else {
          ans = max(ans, cnt);
          cnt = 1;
        }
        now += dis;
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << '\n';

  return 0;
}