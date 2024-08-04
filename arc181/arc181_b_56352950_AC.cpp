/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc181/submissions/56352950
 * Submitted at: 2024-08-04 22:10:17
 * Problem URL: https://atcoder.jp/contests/arc181/tasks/arc181_b
 * Result: AC
 * Execution Time: 132 ms
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
    string s, x, y;
    cin >> s >> x >> y;
    ll zero_x = 0, zero_y = 0, one_x = 0, one_y = 0;
    for(ll i = 0; i < x.size(); i++) {
      if(x[i] == '0') zero_x++;
      else one_x++;
    }
    for(ll i = 0; i < y.size(); i++) {
      if(y[i] == '0') zero_y++;
      else one_y++;
    }
    if(zero_x == zero_y) {
      cout << "Yes" << endl;
      continue;
    }
    // zero の個数が一致しないで one の個数が一致する場合 ⇒ No
    if(one_x == one_y) {
      cout << "No" << endl;
      continue;
    }
    // 一方に偏ってしまっている場合 ⇒ No
    if((zero_x > zero_y && one_x > one_y) || (zero_x < zero_y && one_x < one_y)) {
      cout << "No" << endl;
      continue;
    }
    ll v1 = s.size() * (zero_x - zero_y);
    ll v2 = (one_y - one_x);
    if(v1 < 0) v1 *= -1, v2 *= -1;
    if(v1 % v2 == 0) {
      ll t_size = v1 / v2;
      // s_size と t_size の最大公約数で互いに周期的になるかどうかを判定する
      ll s_size = s.size();
      ll g      = gcd(s_size, t_size);
      bool f    = true;
      rep(i, s_size) f &= (s[i] == s[i % g]);
      cout << (f ? "Yes" : "No") << endl;
    } else {
      // 文字数がどうやっても合わない場合 ⇒ No
      cout << "No" << endl;
      continue;
    }
  }

  return 0;
}