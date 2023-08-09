/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/44399470
 * Submitted at: 2023-08-09 09:28:35
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_d
 * Result: AC
 * Execution Time: 48 ms
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
    
    ll n,m; cin >> n >> m;
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    a.push_back(0);
    a.push_back(n+1);
    sort(a.begin(), a.end());
    ll min_w = 1e16;
    rep(i,a.size()-1) {
        if( a[i+1] - a[i] != 1 ) min_w = min(min_w, a[i+1]-a[i]-1);
    }
    ll ans = 0;
    rep(i,a.size()-1) {
        if( a[i+1]-a[i] != 1 ) ans += (a[i+1]-a[i]-2)/min_w + 1;
    }
    cout << ans << endl;
    
    return 0;
}