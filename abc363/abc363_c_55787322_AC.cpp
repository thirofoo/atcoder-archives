/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc363/submissions/55787322
 * Submitted at: 2024-07-20 21:18:08
 * Problem URL: https://atcoder.jp/contests/abc363/tasks/abc363_c
 * Result: AC
 * Execution Time: 1351 ms
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
  string s;
  cin >> s;
  vector<ll> p(n, 0);
  iota(p.begin(), p.end(), 0);

  auto check = [](string &str) -> bool {
    // 回文判定
    ll l = 0, r = str.size() - 1;
    while(l < r) {
      if(str[l] != str[r]) return false;
      l++;
      r--;
    }
    return true;
  };

  ll ans = 0;
  set<string> st;
  do {
    string t = "";
    for(ll i = 0; i < n; i++) t += s[p[i]];
    if(st.count(t)) continue;
    st.insert(t);
    bool flag = false;
    for(ll i = 0; i < n - k + 1; i++) {
      string u = t.substr(i, k);
      flag |= check(u);
      if(flag) break;
    }
    if(flag) ans++;
  } while(next_permutation(p.begin(), p.end()));

  cout << st.size() - ans << endl;

  return 0;
}