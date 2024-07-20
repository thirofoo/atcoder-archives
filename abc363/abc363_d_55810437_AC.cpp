/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc363/submissions/55810437
 * Submitted at: 2024-07-20 22:20:22
 * Problem URL: https://atcoder.jp/contests/abc363/tasks/abc363_d
 * Result: AC
 * Execution Time: 1 ms
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
  if(n <= 10) return cout << n - 1 << endl, 0;

  ll sum = 1, times = 1;
  vector<ll> r10(19, 1);
  for(ll i = 1; i < 19; i++) r10[i] = r10[i - 1] * 10;
  string ans = "";
  while(true) {
    ll cost = r10[times] - r10[times - 1];
    if(sum + cost >= n) {
      ll rest = n - sum + r10[times - 1] - 1;
      ll x1 = rest / 10, x2 = rest % 10;
      // cerr << x1 << " " << x2 << " " << n - sum << endl;
      ans = to_string(x1);
      while(ans.size() < times - 1) ans += "0";

      string tmp = ans;
      reverse(tmp.begin(), tmp.end());
      ans += to_string(x2);
      ans += tmp;
      break;
    }
    sum += cost;
    if(sum + cost >= n) {
      ll rest = n - sum + r10[times - 1];
      ll x1 = rest - 1, x2 = -1;
      // cerr << x1 << " " << x2 << " " << n - sum << endl;
      ans = to_string(x1);
      while(ans.size() < times) ans += "0";

      string tmp = ans;
      reverse(tmp.begin(), tmp.end());
      ans += tmp;
      break;
    }
    sum += cost;
    times++;
  }
  cout << ans << endl;

  return 0;
}