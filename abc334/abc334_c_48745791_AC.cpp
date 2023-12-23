/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc334/submissions/48745791
 * Submitted at: 2023-12-23 21:12:40
 * Problem URL: https://atcoder.jp/contests/abc334/tasks/abc334_c
 * Result: AC
 * Execution Time: 10 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> a(k);
    rep(i,k) cin >> a[i];
    if( k%2 == 0 ) {
        ll ans = 0;
        for(ll i=0; i<k; i+=2) ans += abs(a[i]-a[i+1]);
        cout << ans << endl;
    }
    else {
        ll cand = 0, ans;
        for(ll i=1; i<k; i+=2) cand += abs(a[i]-a[i+1]);
        ans = cand;
        for(ll i=2; i<k; i+=2) {
            cand -= abs(a[i]-a[i-1]);
            cand += abs(a[i-2]-a[i-1]);
            ans = min(ans, cand);
        }
        cout << ans << endl;
    }
    
    return 0;
}