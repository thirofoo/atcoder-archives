/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc332/submissions/48411874
 * Submitted at: 2023-12-11 00:43:43
 * Problem URL: https://atcoder.jp/contests/abc332/tasks/abc332_e
 * Result: AC
 * Execution Time: 873 ms
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

using ld = long double;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n, d; cin >> n >> d;
    vector<ll> w(n);
    ld total = 0;
    rep(i,n) {
        cin >> w[i];
        total += w[i];
    }
    vector<vector<ld>> dp(d+1, vector<ld>(1LL << n, 1e18));
    rep(i,1LL << n) {
        dp[1][i] = 0.0;
        rep(j,n) if( i & (1LL << j) ) dp[1][i] += w[j];
        dp[1][i] *= dp[1][i];
    }
    for(ll i=2; i<=d; i++) {
        rep(j,(1LL << n)) {
            for(ll k=j; k>0; k--, k&=j ) {
                dp[i][j] = min(dp[i][j], dp[1][j^k]+dp[i-1][k]);
            }
        }
    }
    cout << (d*dp[d][(1LL << n)-1]-total*total)/(d*d) << endl;
    
    return 0;
}