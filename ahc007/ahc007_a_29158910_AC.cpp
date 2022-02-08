/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc007/submissions/29158910
 * Submitted at: 2022-02-08 15:12:22
 * Problem URL: https://atcoder.jp/contests/ahc007/tasks/ahc007_a
 * Result: AC
 * Execution Time: 42 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); ++i)
 
int main() {
  int n = 400, m = 1995;
  vector<P> a(n);
  rep(i, n) cin >> a[i].first >> a[i].second;
  vector<P> b(m);
  rep(i, m) cin >> b[i].first >> b[i].second;
  rep(i, m) {
    int x;
    cin >> x;
    cout << 1 << endl;
    fflush(stdout);
  }
  return 0;
}