/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc182/submissions/44445993
 * Submitted at: 2023-08-11 09:15:32
 * Problem URL: https://atcoder.jp/contests/abc182/tasks/abc182_b
 * Result: AC
 * Execution Time: 9 ms
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0, maxi = -1;
    for(ll i=2;i<=1000;i++) {
        ll cand = 0;
        rep(j,n) if(a[j]%i == 0) cand++;
        if( maxi < cand ) {
            maxi = cand;
            ans = i;
        }
    }
    cout << ans << endl;
    
    return 0;
}