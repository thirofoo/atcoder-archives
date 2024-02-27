/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc319/submissions/50672206
 * Submitted at: 2024-02-27 11:13:12
 * Problem URL: https://atcoder.jp/contests/abc319/tasks/abc319_e
 * Result: AC
 * Execution Time: 1488 ms
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
    
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> p(n-1), t(n-1);
    rep(i,n-1) cin >> p[i] >> t[i];
    ll l = 1;
    reps(i,1,9) l = lcm(l,i);
    vector<vector<ll>> time(l,vector<ll>(n,1e16));
    rep(i,l) {
        time[i][0] = i;
        reps(j,1,n) time[i][j] = time[i][j-1] + (p[j-1]-time[i][j-1]%p[j-1])%p[j-1] + t[j-1];
    }
    ll q; cin >> q;
    while( q-- ) {
        ll start; cin >> start;
        start += x;
        cout << start-start%l + time[start%l][n-1] + y << endl;
    }
    
    return 0;
}