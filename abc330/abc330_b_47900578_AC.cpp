/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc330/submissions/47900578
 * Submitted at: 2023-11-25 21:08:48
 * Problem URL: https://atcoder.jp/contests/abc330/tasks/abc330_b
 * Result: AC
 * Execution Time: 163 ms
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
    
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        if( (r-a[i])*(l-a[i]) <= 0 ) cout << a[i] << " ";
        else if( l >= a[i] ) cout << l << endl;
        else cout << r << endl;
    }
    cout << endl;
    
    return 0;
}