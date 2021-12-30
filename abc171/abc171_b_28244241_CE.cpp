/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc171/submissions/28244241
 * Submitted at: 2021-12-31 01:15:11
 * Problem URL: https://atcoder.jp/contests/abc171/tasks/abc171_b
 * Result: CE
 * Execution Time: None ms
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
    int n,kans = 0; cin >> n >> k;
    vector<int> price(n);
    rep(i,n)cin >> price[i];
    sort(price.begin(),price.end());
    rep(i,k)ans += price[i];
    cout << ans << endl;
    return 0;
}