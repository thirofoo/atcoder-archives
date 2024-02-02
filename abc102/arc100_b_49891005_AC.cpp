/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc102/submissions/49891005
 * Submitted at: 2024-02-02 23:21:15
 * Problem URL: https://atcoder.jp/contests/abc102/tasks/arc100_b
 * Result: AC
 * Execution Time: 31 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n+1,0);
    rep(i,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    // 真ん中切断部分全探索 ⇒ PQ, RS を最小に切る
    // PQ, RS の総和が小さい方の下限の最大化、大きい方の上限の最小化？
    ll ans = 1e16;
    for(ll i=2; i<n-1; i++) {
        ll pq = a[i], rs = a.back() - a[i];
        ll i1 = lower_bound(a.begin(), a.end(), pq/2) - a.begin();
        ll i2 = lower_bound(a.begin(), a.end(), a[i] + rs/2) - a.begin();
        ll pq_min = -1e16, pq_max = 1e16, rs_min = -1e16, rs_max = 1e16;
        for(ll j=i1-3; j<=i1+3; j++) {
            if( j < 0 || i < j ) continue;
            ll l = a[j], r = pq-l;
            // pq <= rs → pq_min の最大化, pq > rs → pq_max の最小化
            if( (pq <= rs && pq_min < min(l,r)) || (pq > rs && max(l,r) < pq_max) ) {
                pq_min = min(l,r);
                pq_max = max(l,r);
            }
        }
        for(ll j=i2-3; j<=i2+3; j++) {
            if( j <= i || n < j ) continue;
            ll l = a[j]-a[i], r = rs-l;
            // pq <= rs → rs_max の最小化, pq > rs → rs_min の最大化
            if( (pq <= rs && max(l,r) < rs_max) || (pq > rs && rs_min < min(l,r)) ) {
                rs_min = min(l,r);
                rs_max = max(l,r);
            }
        }
        ans = min(ans, max(pq_max,rs_max) - min(pq_min,rs_min));
    }
    cout << ans << endl;
    
    return 0;
}