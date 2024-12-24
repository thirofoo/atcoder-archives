/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/61051376
 * Submitted at: 2024-12-24 14:08:36
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_e
 * Result: AC
 * Execution Time: 356 ms
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

  ll n, q;
  string s;
  cin >> n >> q >> s;
  s += "?";
  n++;

  vector<ll> one_rui(n + 1, 0), two_rui(n + 1, 0), slush_rui(n + 1, 0);
  rep(i, n) {
    if(s[i] == '1') one_rui[i + 1]++;
    else if(s[i] == '2') two_rui[i + 1]++;
    else slush_rui[i + 1]++;
    one_rui[i + 1] += one_rui[i];
    slush_rui[i + 1] += slush_rui[i];
    two_rui[i + 1] += two_rui[i];
  }

  while(q--) {
    ll l, r;
    cin >> l >> r;
    ll ok = 0, ng = r - l + 1;
    while(ng - ok > 1) {
      ll mid = (ok + ng) / 2;
      ll idx = lower_bound(one_rui.begin() + l, one_rui.end(), one_rui[l - 1] + mid) - one_rui.begin() + 1;
      idx = lower_bound(slush_rui.begin() + idx, slush_rui.end(), slush_rui[idx - 1] + 1) - slush_rui.begin() + 1;
      idx = lower_bound(two_rui.begin() + idx, two_rui.end(), two_rui[idx - 1] + mid) - two_rui.begin();
      if(idx <= r) ok = mid;
      else ng = mid;
    }
    cout << (slush_rui[r] - slush_rui[l - 1] == 0 ? 0 : 2 * ok + 1) << '\n';
  }

  return 0;
}