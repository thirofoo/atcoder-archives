/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc202/submissions/29818824
 * Submitted at: 2022-03-03 12:19:48
 * Problem URL: https://atcoder.jp/contests/abc202/tasks/abc202_c
 * Result: AC
 * Execution Time: 76 ms
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
    vector<ll> a(n),b(n),c(n),d(n,0);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> c[i];
    rep(i,n)d[b[c[i]-1]-1]++;
    ll ans = 0;
    rep(i,n)ans += d[a[i]-1];
    cout << ans << '\n';
    return 0;
}