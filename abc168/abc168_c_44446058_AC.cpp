/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc168/submissions/44446058
 * Submitted at: 2023-08-11 09:22:04
 * Problem URL: https://atcoder.jp/contests/abc168/tasks/abc168_c
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << setprecision(10) << fixed;
    
    double a,b,h,m; cin >> a >> b >> h >> m;
    double rad1 = M_PI / 180 * (m * 6);
    double rad2 = M_PI / 180 * ((h*60 + m) / 2);
    double ans = sqrt( a*a + b*b - 2*a*b*cos(rad1-rad2) );
    cout << ans << endl;
    
    return 0;
}