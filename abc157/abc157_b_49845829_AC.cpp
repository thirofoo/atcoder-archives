/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc157/submissions/49845829
 * Submitted at: 2024-01-31 23:57:56
 * Problem URL: https://atcoder.jp/contests/abc157/tasks/abc157_b
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
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<vector<ll>> a(3,vector<ll>(3));
    rep(i,3) rep(j,3) cin >> a[i][j];
    ll n; cin >> n;
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    vector<vector<bool>> c(3,vector<bool>(3,false));
    rep(i,n) rep(j,3) rep(k,3) if(a[j][k] == b[i]) c[j][k] = true;
    bool ans = false;
    rep(i,3) if(c[i][0] && c[i][1] && c[i][2]) ans = true;
    rep(i,3) if(c[0][i] && c[1][i] && c[2][i]) ans = true;
    if(c[0][0] && c[1][1] && c[2][2]) ans = true;
    if(c[0][2] && c[1][1] && c[2][0]) ans = true;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}