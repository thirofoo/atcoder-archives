/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/47292717
 * Submitted at: 2023-11-05 12:02:15
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
 * Result: WA
 * Execution Time: 496 ms
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
    
    ll n,q,x; cin >> n >> q >> x;
    vector<ll> w(n), rui(2*n+1,0), p(n,0);
    rep(i,n) cin >> w[i];
    rep(i,2*n) rui[i+1] = rui[i] + w[i%n];

    vector<vector<ll>> d(60,vector<ll>(n,0));
    rep(i,n) p[i] = lower_bound(rui.begin(), rui.end(), rui[i]+x) - (rui.begin()+i);
    rep(i,n) d[0][i] = (lower_bound(rui.begin(), rui.end(), rui[i]+x) - (rui.begin()+i) + i)%n;
    rep(i,59) rep(j,n) d[i+1][j] = d[i][d[i][j]];

    // rep(i,n) cerr << p[i] << " ";
    // cerr << endl;
    // rep(i,3) {
    //     rep(j,n) cerr << d[i][j] << " ";
    //     cerr << endl;
    // }

    while( q-- ) {
        ll k; cin >> k; k--;
        ll idx = 0;
        rep(i,60) {
            if( !(k & (1ll << i)) ) continue;
            idx = d[i][idx];
        }
        cout << p[idx] << endl;
    }
    
    return 0;
}