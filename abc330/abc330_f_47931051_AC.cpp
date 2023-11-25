/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc330/submissions/47931051
 * Submitted at: 2023-11-25 22:07:52
 * Problem URL: https://atcoder.jp/contests/abc330/tasks/abc330_f
 * Result: AC
 * Execution Time: 2199 ms
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
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    auto fx = [&](ll nx, ll b) -> ll {
        ll cand = 0;
        rep(i,n) {
            if( nx <= x[i] && x[i] <= nx+b ) continue;
            cand += max(nx-x[i], x[i]-(nx+b));
        }
        return cand;
    };
    auto fy = [&](ll ny, ll b) {
        ll cand = 0;
        rep(i,n) {
            if( ny <= y[i] && y[i] <= ny+b ) continue;
            cand += max(ny-y[i], y[i]-(ny+b));
        }
        return cand;
    };

    ll left = -1, right = 1e10;
    while( right-left > 1 ) {
        ll mid = (right+left)/2;

        // 三分探索
        ll l1 = 0, r1 = 1e10;
        while( r1-l1 > 2 ){
            ll m1 = (l1+r1)/2,m2 = m1+1;
            if( fx(m1,mid) > fx(m2,mid) ) l1 = m1;
            else r1 = m2;
        }
        ll l2 = 0, r2 = 1e10;
        while( r2-l2 > 2 ){
            ll m1 = (l2+r2)/2,m2 = m1+1;
            if( fy(m1,mid) > fy(m2,mid) ) l2 = m1;
            else r2 = m2;
        }

        ll mini = 1e16;
        for(ll i=l1-5; i<=l1+5; i++) {
            for(ll j=l2-5; j<=l2+5; j++) {
                mini = min(mini, fx(i,mid) + fy(j,mid) );
            }
        }

        if( mini <= k ) right = mid;
        else left = mid;
    }
    cout << right << endl;
    
    return 0;
}