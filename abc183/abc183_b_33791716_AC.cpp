/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/33791716
 * Submitted at: 2022-08-06 11:22:35
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_b
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    long double sx,sy,gx,gy; cin >> sx >> sy >> gx >> gy;
    cout << sx + (gx-sx)*sy/(sy+gy) << endl;
    
    return 0;
}