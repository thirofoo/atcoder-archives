/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc334/submissions/48748053
 * Submitted at: 2023-12-23 21:15:16
 * Problem URL: https://atcoder.jp/contests/abc334/tasks/abc334_d
 * Result: AC
 * Execution Time: 255 ms
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
    
    ll n, q; cin >> n >> q;
    vector<ll> r(n+1,0);
    rep(i, n) cin >> r[i+1];
    sort(r.begin(), r.end());
    rep(i,n) r[i+1] += r[i];
    while( q-- ) {
        ll x; cin >> x;
        cout << upper_bound(r.begin(), r.end(), x)-r.begin()-1 << endl;
    }
    
    return 0;
}