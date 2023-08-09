/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc166/submissions/44399278
 * Submitted at: 2023-08-09 09:15:37
 * Problem URL: https://atcoder.jp/contests/abc166/tasks/abc166_c
 * Result: AC
 * Execution Time: 38 ms
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
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<ll> good(n,1);
    rep(i,m) {
        ll a,b; cin >> a >> b;
        a--; b--;
        if( h[a] > h[b] ) good[b] = 0;
        else if( h[a] < h[b] ) good[a] = 0;
        else {
            good[a] = 0;
            good[b] = 0;
        }
    }
    ll ans = 0;
    rep(i,n) ans += good[i];
    cout << ans << endl;
    
    return 0;
}