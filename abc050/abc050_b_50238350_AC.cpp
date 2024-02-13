/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc050/submissions/50238350
 * Submitted at: 2024-02-13 09:02:59
 * Problem URL: https://atcoder.jp/contests/abc050/tasks/abc050_b
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vector<ll> t(n);
    ll total = 0;
    rep(i, n) {
        cin >> t[i];
        total += t[i];
    }
    ll m; cin >> m;
    ll ans = total;
    rep(i,m) {
        ll p, x; cin >> p >> x;
        cout << total-t[p-1]+x << '\n';
    }
    
    return 0;
}