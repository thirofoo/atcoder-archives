/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc017/submissions/48613275
 * Submitted at: 2023-12-17 17:44:18
 * Problem URL: https://atcoder.jp/contests/abc017/tasks/abc017_3
 * Result: AC
 * Execution Time: 15 ms
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
    vector<ll> imos(m+1,0);
    ll total = 0;
    rep(i,n) {
        ll l, r, s; cin >> l >> r >> s; l--;
        total += s;
        imos[l] += s;
        imos[r] -= s;
    }
    rep(i,m) imos[i+1] += imos[i];
    ll ans = 0;
    rep(i,m) ans = max(ans,total-imos[i]);
    cout << ans << endl;
    
    return 0;
}