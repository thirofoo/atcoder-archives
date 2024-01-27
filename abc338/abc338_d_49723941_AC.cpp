/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49723941
 * Submitted at: 2024-01-27 21:53:30
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_d
 * Result: AC
 * Execution Time: 21 ms
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
    // imos 法で cnt[i] : i個目の道の通った回数, cost[i] : i個目の道を取った時のコストとする
    // ⇒ 道が1つも工事しない時の最小値を求めて、工事する道を全探索
    vector<ll> cnt(2*n+2,0), cost(2*n+2,0);
    ll cand = 0;
    rep(i,m-1) {
        ll l = x[i], r = x[i+1];
        if(l > r) swap(l,r);
        // 時計回りと反時計回りどちらが早いかを判定
        if( r-l < l+n-r ) {
            cnt[l]++, cnt[r]--;
            cost[l] += r-l, cost[r] -= r-l;
            cand += r-l;
        } else {
            cnt[r]++, cnt[l+n]--;
            cost[r] += l+n-r, cost[l+n] -= l+n-r;
            cand += l+n-r;
        }
    }
    // imos 法をして 1~n にまとめる
    rep(i,2*n+1) {
        cnt[i+1] += cnt[i];
        cost[i+1] += cost[i];
    }
    vector<ll> ncnt(n+1,0), ncost(n+1,0);
    rep(i,2*n) {
        ncnt[i%n+1] += cnt[i+1];
        ncost[i%n+1] += cost[i+1];
    }
    ll ans = 1e16;
    for(ll i=1; i<=n; i++) {
        ll pre = ncost[i], next = ncnt[i]*n - ncost[i];
        ans = min(ans, cand - pre + next);
    }
    cout << ans << endl;
    
    return 0;
}