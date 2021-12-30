/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc074/submissions/28243404
 * Submitted at: 2021-12-31 00:49:00
 * Problem URL: https://atcoder.jp/contests/abc074/tasks/abc074_b
 * Result: AC
 * Execution Time: 7 ms
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

int main() {
    int n,k,ans = 0; cin >> n >> k;
    vector<int> distance(n);
    rep(i,n)cin >> distance[i];
    rep(i,n)ans += 2*min(abs(distance[i]),abs(k-distance[i]));
    cout << ans << endl;
    return 0;
}