/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc135/submissions/49805117
 * Submitted at: 2024-01-30 14:33:35
 * Problem URL: https://atcoder.jp/contests/arc135/tasks/arc135_c
 * Result: AC
 * Execution Time: 33 ms
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
    vector<ll> a(n), cnt(30,0), r(30,1);
    ll ans = 0;
    rep(i,n) {
        cin >> a[i];
        rep(j,30) cnt[j] += ((a[i] & (1LL << j)) > 0);
        ans += a[i];
    }
    rep(i,29) r[i+1] = 2*r[i];
    rep(i,n) {
        ll cand = 0;
        rep(j,30) cand += ( a[i] & (1LL << j) ? n-cnt[j] : cnt[j] ) * r[j];
        ans = max(ans, cand);
    }
    cout << ans << endl;
    
    return 0;
}