/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/61252773
 * Submitted at: 2024-12-30 21:12:50
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_f
 * Result: AC
 * Execution Time: 30 ms
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

  string s;
  cin >> s;
  vector<ll> next(s.size(), -1);
  stack<ll> st;
  ll flip_cnt = 0;
  vector<ll> flip(s.size(), 0);
  rep(i, s.size()) {
    if(s[i] == '(') {
      st.push(i);
      flip_cnt++;
    } else if(s[i] == ')') {
      next[st.top()] = i;
      next[i]        = st.top();
      st.pop();
      flip_cnt--;
    } else flip[i] = flip_cnt;
  }

  string ans = "";
  auto f     = [&](auto self, ll left, ll right, bool rev) -> void {
    for(ll idx = (rev ? right - 1 : left); (rev ? left <= idx : idx < right); (rev ? idx-- : idx++)) {
      if(s[idx] == '(' || s[idx] == ')') {
        ll nl = min(idx, next[idx]) + 1;
        ll nr = max(idx, next[idx]);
        self(self, nl, nr, !rev);
        idx = next[idx];
      } else {
        if(flip[idx] % 2 == 0) ans += s[idx];
        else ans += (islower(s[idx]) ? toupper(s[idx]) : tolower(s[idx]));
      }
    }
  };
  f(f, 0, s.size(), false);
  cout << ans << '\n';

  return 0;
}