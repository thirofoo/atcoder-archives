/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63014627
 * Submitted at: 2025-02-22 21:12:15
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_d
 * Result: AC
 * Execution Time: 4 ms
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

  map<char, char> mp = {
      {'(', ')'},
      {'[', ']'},
      {'<', '>'}
  };

  stack<char> st;
  rep(i, s.size()) {
    if(!st.empty() && mp[st.top()] == s[i]) st.pop();
    else {
      if(mp.find(s[i]) == mp.end()) {
        return cout << "No" << '\n', 0;
      }
      st.push(s[i]);
    }
  }
  cout << (st.empty() ? "Yes" : "No") << '\n';

  return 0;
}