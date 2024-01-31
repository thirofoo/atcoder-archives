/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc116/submissions/49845987
 * Submitted at: 2024-02-01 00:04:18
 * Problem URL: https://atcoder.jp/contests/abc116/tasks/abc116_c
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    ll ans = 0;
    while( true ) {
        // 左端調査 ⇒ その左端から名一杯広げる
        ll left = -1, right = n, mini = 1e9;
        rep(i,n) {
            if( h[i] == 0 ) continue;
            left = i; break;
        }
        if( left == -1 ) break;
        for(ll i=left; i<n; i++) {
            if( h[i] != 0 ) {
                mini = min(mini, h[i]);
                continue;
            }
            right = i; break;
        }
        for(ll i=left; i<right; i++) h[i] -= mini;
        ans += mini;
    }
    cout << ans << endl;
    
    return 0;
}