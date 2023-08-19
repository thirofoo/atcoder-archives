/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/44769879
 * Submitted at: 2023-08-19 23:55:31
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_f
 * Result: AC
 * Execution Time: 57 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ld, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; cin >> n;
    vector<P> check;
    rep(i,n) {
        ld x,y; cin >> x >> y;
        check.emplace_back(P(x,y));
    }
    vector<ld> r(60,0);
    r[1] = 1;
    rep(i,40) r[i+2] = min(r[i+1]*2,(ld)1e16);

    vector<vector<ld>> dp(n,vector<ld>(40,1e16));
    dp[0][0] = 0;
    for(ll i=1;i<n;i++) {
        auto [x1,y1] = check[i];
        rep(j,40) {
            // k : 何個連続で飛ばしたか
            rep(k,j+1) {
                if( i-k-1 < 0 ) break;
                auto [x2,y2] = check[i-k-1];
                ld dis = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                dp[i][j] = min(dp[i][j],dp[i-k-1][j-k]+dis);
            }
        }
    }

    ld ans = 1e16;
    rep(i,40) ans = min(ans, dp[n-1][i]+r[i]);
    cout << ans << endl;
    
    return 0;
}