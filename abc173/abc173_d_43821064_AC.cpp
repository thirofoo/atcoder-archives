/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc173/submissions/43821064
 * Submitted at: 2023-07-22 16:58:27
 * Problem URL: https://atcoder.jp/contests/abc173/tasks/abc173_d
 * Result: AC
 * Execution Time: 67 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
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
    sort( a.begin(), a.end(), [](ll e1, ll e2){
        return e1 > e2;
    } );
    rep(i,n-1) a.push_back( a[i+1] );
    sort( a.begin(), a.end(), [](ll e1, ll e2){
        return e1 > e2;
    } );
    ll ans = 0;
    rep(i,n-1) ans += a[i];
    cout << ans << endl;
    
    return 0;
}