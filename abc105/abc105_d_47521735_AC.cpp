/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc105/submissions/47521735
 * Submitted at: 2023-11-12 14:03:41
 * Problem URL: https://atcoder.jp/contests/abc105/tasks/abc105_d
 * Result: AC
 * Execution Time: 29 ms
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
    vector<ll> a(n), r(n+1,0);
    rep(i,n) {
        cin >> a[i];
        r[i+1] = (r[i] + a[i])%m;
    }
    map<ll,ll> mp;
    mp[0] = 1;
    // 左端全探索
    ll ans = 0;
    rep(i,n) {
        ans += mp[r[i+1]];
        mp[r[i+1]]++;
    }
    cout << ans << endl;

    
    return 0;
}