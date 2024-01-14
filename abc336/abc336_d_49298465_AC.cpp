/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc336/submissions/49298465
 * Submitted at: 2024-01-14 21:28:32
 * Problem URL: https://atcoder.jp/contests/abc336/tasks/abc336_d
 * Result: AC
 * Execution Time: 13 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        // 大きい方を小さい方 +1 に合わせる
        if( i != 0 ) {
            ll tmp = min(a[i-1], a[i]);
            if( a[i] < a[i-1] ) a[i-1] = tmp + 1;
            else if( a[i] > a[i-1] ) a[i] = tmp + 1;
        }
        if( i != n-1 ) {
            ll tmp = min(a[i], a[i+1]);
            if( a[i] < a[i+1] ) a[i+1] = tmp + 1;
            else if( a[i] > a[i+1] ) a[i] = tmp + 1;
        }
    }
    for(ll i=n-1; i>=0; i--) {
        // 大きい方を小さい方 +1 に合わせる
        if( i != 0 ) {
            ll tmp = min(a[i-1], a[i]);
            if( a[i] < a[i-1] ) a[i-1] = tmp + 1;
            else if( a[i] > a[i-1] ) a[i] = tmp + 1;
        }
        if( i != n-1 ) {
            ll tmp = min(a[i], a[i+1]);
            if( a[i] < a[i+1] ) a[i+1] = tmp + 1;
            else if( a[i] > a[i+1] ) a[i] = tmp + 1;
        }
    }
    ll ans = 1;
    rep(i,n) {
        // ピラミッド型になるようにする
        ans = max(ans,min({a[i],i+1,n-i}));
    }
    cout << ans << endl;
    
    return 0;
}