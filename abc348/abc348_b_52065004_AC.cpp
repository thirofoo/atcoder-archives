/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52065004
 * Submitted at: 2024-04-06 21:03:29
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_b
 * Result: AC
 * Execution Time: 1 ms
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
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i,n) {
        ll dis_max = 0, idx = -1;
        rep(j,n) {
            if( i == j ) continue;
            ll dis = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if(dis > dis_max) {
                dis_max = dis;
                idx = j;
            }
        }
        cout << idx+1 << endl;
    }
    
    return 0;
}