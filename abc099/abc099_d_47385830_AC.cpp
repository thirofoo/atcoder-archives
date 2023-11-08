/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc099/submissions/47385830
 * Submitted at: 2023-11-08 23:44:18
 * Problem URL: https://atcoder.jp/contests/abc099/tasks/abc099_d
 * Result: AC
 * Execution Time: 12 ms
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
    
    ll n, c; cin >> n >> c;
    vector<vector<ll>> d(c,vector<ll>(c)), color(n,vector<ll>(n)), cnt(3,vector<ll>(c,0));
    rep(i,c) rep(j,c) cin >> d[i][j];
    rep(i,n) rep(j,n) {
        cin >> color[i][j];
        color[i][j]--;
        cnt[(i+j)%3][color[i][j]]++;
    }
    ll ans = 1e9;
    for(int i=0; i<c; i++) {
        for(int j=0; j<c; j++) {
            if( i == j ) continue;
            for(int k=0; k<c; k++) {
                if( i == k || j == k ) continue;
                ll cand = 0;
                rep(l,c) cand += d[l][i]*cnt[0][l] + d[l][j]*cnt[1][l] + d[l][k]*cnt[2][l];
                ans = min(ans, cand);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}