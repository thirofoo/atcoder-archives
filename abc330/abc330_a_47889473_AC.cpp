/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc330/submissions/47889473
 * Submitted at: 2023-11-25 21:00:38
 * Problem URL: https://atcoder.jp/contests/abc330/tasks/abc330_a
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n, l; cin >> n >> l;
    ll ans = 0;
    rep(i,n) {
        ll a; cin >> a;
        if( a >= l ) ans++;
    }
    cout << ans << endl;
    
    return 0;
}