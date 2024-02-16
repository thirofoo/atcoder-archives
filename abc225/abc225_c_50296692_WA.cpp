/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc225/submissions/50296692
 * Submitted at: 2024-02-16 09:18:43
 * Problem URL: https://atcoder.jp/contests/abc225/tasks/abc225_c
 * Result: WA
 * Execution Time: 7 ms
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
    vector<vector<ll>> b(n, vector<ll>(m));
    rep(i, n) rep(j, m) cin >> b[i][j];
    bool flag = true;
    rep(i, n) rep(j, m-1) flag &= (b[i][j+1] == b[i][j]+1);
    rep(i, n-1) rep(j, m) flag &= (b[i+1][j]%7 == b[i][j]%7);
    rep(i,n) rep(j,m-1) flag &= (b[i][j+1]%7 == (b[i][j]%7)+1);
    cout << (flag ? "Yes" : "No") << '\n';
    
    return 0;
}