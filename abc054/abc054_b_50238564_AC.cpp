/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc054/submissions/50238564
 * Submitted at: 2024-02-13 09:20:16
 * Problem URL: https://atcoder.jp/contests/abc054/tasks/abc054_b
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n, m; cin >> n >> m;
    vector<string> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    rep(ax,n-m+1) rep(ay,n-m+1) {
        bool ok = true;
        rep(bx,m) rep(by,m) ok &= (a[ax+bx][ay*by] == b[bx][by]);
        if(ok) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    
    return 0;
}