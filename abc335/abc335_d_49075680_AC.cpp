/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc335/submissions/49075680
 * Submitted at: 2024-01-06 21:12:12
 * Problem URL: https://atcoder.jp/contests/abc335/tasks/abc335_d
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll cnt = 1;
    vector<vector<ll>> ans(n,vector<ll>(n,0));
    for(ll i=0; i<n/2; i++) {
        // N*N の長方形の周囲を for 分で回す
        for(ll j=i; j<n-i-1; j++) {
            ans[i][j] = cnt;
            cnt++;
        }
        for(ll j=i; j<n-i-1; j++) {
            ans[j][n-i-1] = cnt;
            cnt++;
        }
        for(ll j=n-i-1; j>i; j--) {
            ans[n-i-1][j] = cnt;
            cnt++;
        }
        for(ll j=n-i-1; j>i; j--) {
            ans[j][i] = cnt;
            cnt++;
        }
    }
    rep(i,n) {
        rep(j,n) {
            if( i == n/2 && j == n/2 ) cout << "T ";
            else cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}