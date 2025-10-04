/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc426/submissions/69851694
 * Submitted at: 2025-10-04 21:33:01
 * Problem URL: https://atcoder.jp/contests/abc426/tasks/abc426_d
 * Result: AC
 * Execution Time: 57 ms
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
    string s;
    cin >> n >> s;
    vector<ll> zero_idx, one_idx;
    rep(i, n) {
      if(s[i] == '0') zero_idx.emplace_back(i);
      else one_idx.emplace_back(i);
    }

    ll ans = INF;
    ll r_idx, r_cnt0, r_cnt1, l_idx, l_cnt0, l_cnt1;
    // all 1 の時
    rep(i, n) {
      auto it = upper_bound(zero_idx.begin(), zero_idx.end(), i);
      if(it != zero_idx.end()) {
        r_idx  = *it;
        r_cnt0 = zero_idx.end() - it;
        r_cnt1 = n - r_idx - r_cnt0;
      } else {
        r_idx  = n;
        r_cnt0 = 0;
        r_cnt1 = 0;
      }

      if(it != zero_idx.begin()) {
        it--;
        l_idx  = *it;
        l_cnt0 = it - zero_idx.begin() + 1;
        l_cnt1 = l_idx - l_cnt0 + 1;
      } else {
        l_idx  = -1;
        l_cnt0 = 0;
        l_cnt1 = 0;
      }
      ans = min(ans, l_cnt0 + r_cnt0 + 2 * (l_cnt1 + r_cnt1));
    }
    // all 0 の時
    rep(i, n) {
      auto it = upper_bound(one_idx.begin(), one_idx.end(), i);
      if(it != one_idx.end()) {
        r_idx  = *it;
        r_cnt1 = one_idx.end() - it;
        r_cnt0 = n - r_idx - r_cnt1;
      } else {
        r_idx  = n;
        r_cnt1 = 0;
        r_cnt0 = 0;
      }
      if(it != one_idx.begin()) {
        it--;
        l_idx  = *it;
        l_cnt1 = it - one_idx.begin() + 1;
        l_cnt0 = l_idx - l_cnt1 + 1;
      } else {
        l_idx  = -1;
        l_cnt1 = 0;
        l_cnt0 = 0;
      }
      ans = min(ans, l_cnt1 + r_cnt1 + 2 * (l_cnt0 + r_cnt0));
    }
    cout << ans << "\n";
  }

  return 0;
}