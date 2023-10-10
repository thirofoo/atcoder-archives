/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc146/submissions/46439806
 * Submitted at: 2023-10-11 01:33:01
 * Problem URL: https://atcoder.jp/contests/abc146/tasks/abc146_e
 * Result: RE
 * Execution Time: 718 ms
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
    vector<ll> a(n), r(n+1,0);
    rep(i,n) {
        cin >> a[i];
        r[i+1] = r[i] + a[i];
    }
    map<ll,ll> mp;
    rep(i,k-1) mp[(r[i+1]-(i+1))%k]++;
    ll ans = 0;
    rep(i,n) {
        ans += mp[(r[i]-i)%k];
        mp[(r[i+1]-(i+1))%k]--;
        if( i+k <= n ) mp[(r[i+k]-(i+k))%k]++;
    }
    cout << ans << endl;
    
    return 0;
}

//    r[right]-r[left] = right-left (mod k)
//  ⇒ r[right]-right = r[left]-left (mod k)