/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49747712
 * Submitted at: 2024-01-28 00:17:11
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_d
 * Result: WA
 * Execution Time: 14 ms
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
    vector<ll> x(m);
    rep(i,m) cin >> x[i];
    // imos 法で cost[i] : i個目の道を封鎖した時のコスト
    vector<ll> cost(2*n+2,0);
    ll cand = 0;
    rep(i,m-1) {
        ll l = x[i], r = x[i+1];
        if(l > r) swap(l,r);
        // 時計回りと反時計回りどちらが早いかを判定
        if( r-l < l+n-r ) {
            cost[l] += abs((r-l)-(l+n-r));
            cost[r] -= abs((r-l)-(l+n-r));
            cand += r-l;
        } else {
            cost[r] += abs((r-l)-(l+n-r));
            cost[l+n] -= abs((r-l)-(l+n-r));
            cand += l+n-r;
        }
    }
    // imos 法をして 1~n にまとめる
    rep(i,2*n+1) cost[i+1] += cost[i];
    rep(i,2*n) cost[i%n+1] += cost[i+1];
    ll ans = 1e16;
    for(ll i=1; i<=n; i++) ans = min(ans, cand + cost[i]);
    cout << ans << endl;
    
    return 0;
}