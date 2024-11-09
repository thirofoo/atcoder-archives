/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59634737
 * Submitted at: 2024-11-10 00:00:41
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_g
 * Result: WA
 * Execution Time: 1373 ms
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

  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  if(w > h) {
    vector<string> t(w, string(h, ' '));
    rep(i, h) rep(j, w) t[j][i] = s[i][j];
    swap(h, w);
    s = t;
  }

  // 縦横の小さい方は高々 sqrt(200) <= 14 以下
  // → bit dp で持つと上下どちらも状態として持ちつつ dp 可能
  // ※ 3^min(H,W) でなく、隣接マス条件を入れると状態数が 2 の累乗に落ちるのも重要

  vector<map<ll, ll>> dp(h * w + 1, map<ll, ll>());
  dp[0][0] = 1;
  ll pow_w = pow(10, w);
  rep(i, h) rep(j, w) {
    ll next = i * w + j + 1;
    cerr << i << " " << j << endl;
    for(auto [state, cnt]: dp[i * w + j]) {
      for(auto ch: (s[i][j] == '?' ? vector<char>{'1', '2', '3'} : vector<char>{s[i][j]})) {
        char ch_up   = (i > 0 ? '0' + (state / (pow_w / 10)) : '!');
        char ch_left = (j > 0 ? '0' + (state % 10) : '?');
        // cerr << ch_up << " " << ch_left << endl;
        if(ch == ch_up || ch == ch_left) continue;
        ll ns = (state * 10 + (ch - '0')) % pow_w;
        dp[next][ns] += cnt;
      }
    }
  }
  ll ans = 0;
  for(auto [state, cnt]: dp[h * w]) ans += cnt;
  cout << ans << endl;

  return 0;
}