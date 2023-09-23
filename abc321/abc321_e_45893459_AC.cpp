/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/45893459
 * Submitted at: 2023-09-24 00:33:27
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_e
 * Result: AC
 * Execution Time: 154 ms
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
    
    ll t, n; cin >> t;
    bool left;
    auto f = [&](ll now, ll down) -> ll {
        if( down == 0 ) return 1;
        down--;
        ll e1, e2;
        if( left ) {
            e1 = 2*now + 1;
            e2 = 2*now + 1;
        }
        else {
            e1 = 2*now;
            e2 = 2*now;
        }
        while( down-- ) {
            e1 = 2*e1, e2 = 2*e2+1;
            if( e1 > n ) break;
        }
        return min(e2,n) - min(e1,n+1) + 1;
    };

    while( t-- ) {
        ll x, k, ans = 0; cin >> n >> x >> k;
        if( k == 0 ) {
            cout << 1 << endl;
            continue;
        }
        ll now = x;
        left = true, ans += f(now, k);
        left = false, ans += f(now, k);
        for(ll i=1;i<=k;i++) {
            left = (now%2 == 0);
            now /= 2;
            if( now == 0 ) break;
            ans += f(now, k-i);
        }
        cout << ans << endl;
    }
    
    return 0;
}