/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/jsc2025advance-final/submissions/69111032
 * Submitted at: 2025-09-07 13:34:07
 * Problem URL: https://atcoder.jp/contests/jsc2025advance-final/tasks/abc422_d
 * Result: WA
 * Execution Time: 58 ms
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
  ll size = (1LL << n);
  ll ele1 = k / size, ele2 = ele1 + 1;
  ll cnt2 = k % size, cnt1 = size - cnt2;
  if(cnt1 == 0) {
    cnt1 = size;
    cnt2 = 0;
  }

  vector<ll> ans(size, ele2);
  ll total = 0;
  vector<bool> used(size, false);
  if(cnt1 != 0) {
    for(ll i = n - 1; i >= 0; i--) {
      ll bit = (1LL << i);
      for(ll j = 0; j < size; j += bit) {
        if(used[j]) continue;
        ans[j]  = ele1;
        used[j] = true;
        total++;
        if(total >= cnt1) break;
      }
      if(total >= cnt1) break;
    }
  }

  ll init_max = 0, init_min = INF;
  rep(i, size) {
    init_max = max(init_max, ans[i]);
    init_min = min(init_min, ans[i]);
  }
  ll balance = init_max - init_min;

  vector<ll> now = ans, next;
  while(now.size() > 1) {
    next.clear();
    ll max_e = 0, min_e = INF;
    for(ll i = 0; i < now.size(); i += 2) {
      next.emplace_back(now[i] + now[i + 1]);
      max_e = max(max_e, next.back());
      min_e = min(min_e, next.back());
    }
    balance = max(balance, max_e - min_e);
    now     = next;
  }

  cout << balance << "\n";
  rep(i, size) cout << ans[i] << " ";
  cout << endl;

  return 0;
}