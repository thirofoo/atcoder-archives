/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/44762341
 * Submitted at: 2023-08-19 22:37:56
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_f
 * Result: WA
 * Execution Time: 278 ms
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
    vector<ld> r(n+2,0);
    r[1] = 1;
    rep(i,n) r[i+2] = min(r[i+1]*2,(ld)1e16);

    vector<P> dp(n,P(1e16,0));
    dp[0] = P(0,0);
    for(ll i=1;i<n;i++) {
        auto [x1,y1] = check[i];
        for(ll j=0;j<i;j++) {
            auto [x2,y2] = check[j];
            ld dis1 = dp[i].first + r[dp[i].second];
            ld dis2 = dp[j].first+sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) + r[dp[j].second + i-j-1];
            if( dis2 < dis1 ) {
                dp[i] = P(dp[j].first+sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),dp[j].second + i-j-1);
            }
        }
    }
    // rep(i,n) cout << dp[i].first + r[dp[i].second] << " ";
    // cout << endl;
    
    cout << (ld)(dp[n-1].first + r[dp[n-1].second]) << endl;
    
    return 0;
}