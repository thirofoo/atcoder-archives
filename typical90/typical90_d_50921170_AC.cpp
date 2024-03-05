/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50921170
 * Submitted at: 2024-03-05 16:44:37
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_d
 * Result: AC
 * Execution Time: 357 ms
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
    
    ll h, w; cin >> h >> w;
    vector<ll> row(h,0), col(w,0);
    vector<vector<ll>> a(h,vector<ll>(w));
    rep(i,h) rep(j,w) {
        cin >> a[i][j];
        row[i] += a[i][j];
        col[j] += a[i][j];
    }
    rep(i,h) {
        rep(j,w) cout << row[i] + col[j] - a[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}