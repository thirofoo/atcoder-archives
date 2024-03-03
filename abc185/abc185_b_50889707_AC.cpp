/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/50889707
 * Submitted at: 2024-03-04 08:09:51
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_b
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
    
    ll n, m, t; cin >> n >> m >> t;
    vector<ll> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    ll time = 0, now_b = n;
    rep(i,m) {
        now_b -= a[i] - time;
        if( now_b <= 0 ) {
            cout << "No" << endl;
            return 0;
        }
        now_b = min(now_b+b[i]-a[i], n);
        time = b[i];
        // cerr << now_b << endl;
    }
    now_b -= t - b[m-1];
    if( now_b <= 0 ) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    
    return 0;
}