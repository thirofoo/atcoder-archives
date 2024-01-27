/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49703601
 * Submitted at: 2024-01-27 21:09:30
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_c
 * Result: AC
 * Execution Time: 17 ms
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
    vector<ll> q(n), a(n), b(n);
    rep(i,n) cin >> q[i];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    // 料理A の作る個数全探索
    ll ans = 0;
    rep(i,2000000) {
        vector<ll> rest = q;
        bool f = true;
        rep(j,n) {
            rest[j] -= a[j]*i;
            f &= (rest[j] >= 0);
        }
        if( !f ) break;
        // B の個数を決める
        ll cnt = 1e9;
        rep(i,n) {
            if(b[i] == 0) continue;
            cnt = min(cnt, rest[i]/b[i]);
        }
        ans = max(ans, i+cnt);
    }
    cout << ans << endl;
    
    return 0;
}