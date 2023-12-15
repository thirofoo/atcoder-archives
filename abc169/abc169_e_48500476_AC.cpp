/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc169/submissions/48500476
 * Submitted at: 2023-12-15 10:34:03
 * Problem URL: https://atcoder.jp/contests/abc169/tasks/abc169_e
 * Result: AC
 * Execution Time: 46 ms
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
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if( n%2 == 1 ) cout << b[n/2]-a[n/2]+1 << '\n';
    else cout << (b[n/2]+b[n/2-1])-(a[n/2]+a[n/2-1]) + 1 << '\n';
    
    return 0;
}