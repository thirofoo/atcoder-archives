/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53326187
 * Submitted at: 2024-05-11 21:04:48
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_b
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    ll ans = 0, rest = k;
    rep(i, n) {
        cin >> a[i];
        if( rest >= a[i] ) {
            rest -= a[i];
        } else {
            ans++;
            rest = k - a[i];
        }
    }
    if( rest != k ) ans++;
    cout << ans << '\n';
    
    return 0;
}