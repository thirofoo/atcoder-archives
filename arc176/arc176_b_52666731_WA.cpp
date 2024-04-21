/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc176/submissions/52666731
 * Submitted at: 2024-04-21 22:55:14
 * Problem URL: https://atcoder.jp/contests/arc176/tasks/arc176_b
 * Result: WA
 * Execution Time: 119 ms
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
    
    ll t; cin >> t;
    vector<ll> r = {2,4,8,6};
    while( t-- ) {
        ll n, m, k; cin >> n >> m >> k;
        ll tmp = (n-m) / (m-k) + 1;
        tmp = n - tmp * (m-k);
        cout << r[((tmp-1)%4+4)%4] << endl;
    }
    
    return 0;
}
