/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/61250685
 * Submitted at: 2024-12-30 19:48:29
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_f
 * Result: WA
 * Execution Time: 28 ms
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
    } else flip[i] = flip_cnt;
  }
  vector<bool> visited(s.size(), false);
  string ans = "";
  auto f     = [&](auto self, ll now, bool right) -> void {
    if(now < 0 || s.size() <= now || visited[now]) return;
    // cerr << now << ' ' << right << '\n';
    for(ll idx = now; (0 <= idx && idx < s.size()); idx += (right ? 1 : -1)) {
      if(visited[idx]) return;
      if(s[idx] == '(' || s[idx] == ')') {
        visited[idx]       = true;
        visited[next[idx]] = true;
        self(self, next[idx] + (right ? -1 : 1), !right);
        idx = next[idx];
      } else {
        if(flip[idx] % 2 == 0) ans += s[idx];
        else {
          if(islower(s[idx])) ans += toupper(s[idx]);
          else ans += tolower(s[idx]);
        }
        visited[idx] = true;
      }
    }
    return;
  };
  f(f, 0, true);
  cout << ans << '\n';

  return 0;
}