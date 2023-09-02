/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/45133561
 * Submitted at: 2023-09-02 21:04:47
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_b
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
    vector<vector<ll>> f(105,vector<ll>(105,0));
    rep(i,n) {
        ll a,b,c,d; cin >> a >> b >> c >> d;
        for(ll j=a;j<b;j++) {
            for(ll k=c;k<d;k++) {
                f[j][k]++;
            }
        }
    }
    ll ans = 0;
    rep(i,105) {
        rep(j,105) {
            if( f[i][j] ) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}