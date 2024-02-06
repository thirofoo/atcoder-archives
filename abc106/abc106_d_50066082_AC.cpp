/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc106/submissions/50066082
 * Submitted at: 2024-02-07 00:48:39
 * Problem URL: https://atcoder.jp/contests/abc106/tasks/abc106_d
 * Result: AC
 * Execution Time: 162 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> cnt(n+1,vector<ll>(n+1,0));
    rep(i,0,m) {
        ll l, r; cin >> l >> r;
        cnt[l][r]++;
    }
    rep(l,1,n+1) rep(r,l,n) cnt[l][r+1] += cnt[l][r];
    while( q-- ) {
        ll p, q, ans = 0; cin >> p >> q;
        rep(l,p,q+1) ans += cnt[l][q];
        cout << ans << endl;
    }
    
    return 0;
}