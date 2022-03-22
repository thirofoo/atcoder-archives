/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30346157
 * Submitted at: 2022-03-22 17:41:18
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_n
 * Result: AC
 * Execution Time: 74 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans = 0;
    rep(i,n)ans += abs(a[i]-b[i]);
    cout << ans << endl;
    return 0;
}