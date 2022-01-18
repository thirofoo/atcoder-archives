/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/28618087
 * Submitted at: 2022-01-18 19:37:53
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_e
 * Result: AC
 * Execution Time: 593 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)
typedef tuple<int, int, int, int> t4;
 
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<t4> e;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    e.push_back(t4(c, --a, --b, e.size()));
  }
  rep(i, q) {
    int a, b, c;
    cin >> a >> b >> c;
    e.push_back(t4(c, --a, --b, e.size()));
  }
  dsu d(n);
  sort(e.begin(), e.end());
  vector<bool> queryUse(q, false);
  rep(i, e.size()) {
    auto [c, a, b, idx] = e[i];
    if (idx >= m) {
      queryUse[idx - m] = !d.same(a, b);
    }
    else {
      d.merge(a, b);
    }
  }
  rep(i, q) {
    cout << (queryUse[i] ? "Yes" : "No") << endl;
  }
  return 0;
}