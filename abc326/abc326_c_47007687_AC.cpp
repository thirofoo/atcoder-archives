/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47007687
 * Submitted at: 2023-10-28 21:11:47
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_c
 * Result: AC
 * Execution Time: 64 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = -1;
    rep(i,n) {
        ll i1 = upper_bound(a.begin(), a.end(), a[i]+m-1) - a.begin();
        ll i2 = lower_bound(a.begin(), a.end(), a[i]-(m-1)) - a.begin();
        ans = max({ans, i1-i, i-i2});
    }
    cout << ans << endl;
    
    return 0;
}