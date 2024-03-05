/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50923486
 * Submitted at: 2024-03-05 18:05:01
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_g
 * Result: AC
 * Execution Time: 373 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll q; cin >> q;
    while( q-- ) {
        ll b; cin >> b;
        auto it = lower_bound(a.begin(), a.end(), b);
        ll ans = 1e16;
        if( it != a.end() ) ans = min(ans, abs((*it)-b));
        if( it != a.begin() ) ans = min(ans, abs(b-(*(it-1))));
        cout << ans << endl;
    }
    
    return 0;
}