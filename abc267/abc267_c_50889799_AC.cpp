/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc267/submissions/50889799
 * Submitted at: 2024-03-04 08:23:47
 * Problem URL: https://atcoder.jp/contests/abc267/tasks/abc267_c
 * Result: AC
 * Execution Time: 14 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n), r(n+1,0);
    ll sum = 0, ans = -1e16;
    rep(i, n) {
        cin >> a[i];
        r[i+1] = r[i] + a[i];
        if( i < m ) sum += a[i] * (i+1);
    }
    rep(i,n) {
        ans = max(ans, sum);
        // cerr << sum << endl;
        if( i+m >= n ) break;
        sum -= r[i+m] - r[i];
        sum += a[i+m] * m;
    }
    cout << ans << endl;
    
    return 0;
}