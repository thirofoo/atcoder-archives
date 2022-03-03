/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc202/submissions/29818800
 * Submitted at: 2022-03-03 12:16:46
 * Problem URL: https://atcoder.jp/contests/abc202/tasks/abc202_c
 * Result: WA
 * Execution Time: 69 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> a(n),b(n),c(n),d(n+1,0);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> c[i];
    rep(i,n)d[b[c[i]-1]]++;
    int ans = 0;
    rep(i,n)ans += d[a[i]];
    cout << ans << '\n';
    return 0;
}