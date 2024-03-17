/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc174/submissions/51400213
 * Submitted at: 2024-03-17 23:29:45
 * Problem URL: https://atcoder.jp/contests/arc174/tasks/arc174_a
 * Result: AC
 * Execution Time: 18 ms
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
    
    ll n, c; cin >> n >> c;
    vector<ll> a(n+1);
    ll total = 0;
    rep(i,n) {
        cin >> a[i+1];
        total += a[i+1];
        a[i+1] += a[i];
    }
    ll ans = total;
    if( c > 0 ) {
        ll min_left = 0;
        rep(i,n+1) {
            min_left = min(min_left, a[i]);
            ans = max(ans, total + (a[i]-min_left)*(c-1));
        }
    }
    else {
        ll max_left = 0;
        rep(i,n+1) {
            max_left = max(max_left, a[i]);
            ans = max(ans, total + (a[i]-max_left)*(c-1));
        }
    }
    cout << ans << '\n';
    
    return 0;
}