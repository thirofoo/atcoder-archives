/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc107/submissions/49846415
 * Submitted at: 2024-02-01 00:22:31
 * Problem URL: https://atcoder.jp/contests/abc107/tasks/arc101_a
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> x;
    rep(i,n) {
        ll p; cin >> p;
        if( p == 0 ) k--;
        else x.emplace_back(p);
    }
    if( k == 0 ) return cout << 0 << endl, 0;
    // 左 ⇒ 右 or 右 ⇒ 左 を全探索
    ll sidx = lower_bound(x.begin(), x.end(), 0) - x.begin();
    ll ans = 1e16;
    rep(i,x.size()) {
        if( x[i] > 0 ) break;
        ll rest = max(0ll, k-(sidx-i));
        if( rest == 0 ) ans = min(ans, abs(x[i]));
        else if( sidx+rest-1 < n ) ans = min(ans, abs(x[i])+abs(x[sidx+rest-1]-x[i]));
    }
    rep(i,x.size()) {
        if( x[i] < 0 ) continue;
        ll rest = max(0ll, k-(i-sidx+1));
        if( rest == 0 ) ans = min(ans, x[i]);
        else if( sidx-rest >= 0 ) ans = min(ans, x[i]+abs(x[i]-x[sidx-rest]));
    }
    cout << ans << endl;
    
    return 0;
}