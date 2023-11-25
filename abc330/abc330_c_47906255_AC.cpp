/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc330/submissions/47906255
 * Submitted at: 2023-11-25 21:15:50
 * Problem URL: https://atcoder.jp/contests/abc330/tasks/abc330_c
 * Result: AC
 * Execution Time: 47 ms
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
    
    ll d; cin >> d;
    ll ans = 1e9;
    rep(x,sqrt(d)+10) {
        if( -(x*x-d) < 0 ) continue;
        ll y2 = sqrt(-(x*x-d));
        for(ll y=y2-10; y<=y2+10; y++) {
            if( y < 0 ) continue;
            ans = min(ans, abs(x*x+y*y-d));
        }
    }
    cout << ans << endl;
    
    return 0;
}