/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52106311
 * Submitted at: 2024-04-06 22:20:41
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_f
 * Result: TLE
 * Execution Time: 2212 ms
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
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];

    ll ans = 0;
    rep(i,n) reps(j,i+1,n) {
        ll cnt = 0;
        rep(k,m) cnt += ( a[i][k] == a[j][k] );
        if( cnt%2 == 1 ) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}