/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/44622081
 * Submitted at: 2023-08-15 23:40:02
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_e
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n,m; cin >> n>> m;
    vector<ll> cs(n), ps(n);
    vector<vector<ll>> ss(n);
    rep(i,n){
        cin >> cs[i] >> ps[i];
        ss[i].resize(ps[i]);
        for(auto &s:ss[i]) cin >> s;
    }
    vector<ld> dp(m+1,1e18);
    dp[0] = 0;
    for(ll i=1;i<=m;i++){
        rep(j,n){
            ld now=0;
            ld np=0;
            for(auto s:ss[j]){
                if( s > 0 ) {
                    now += dp[max(0ll,i-s)];
                    np += 1;
                }
            }
            now /= ps[j];
            now += cs[j];
            dp[i] = min(dp[i],now*((ld)ps[j]/np));
        }
    }
    cout << dp[m] << endl;
    
    return 0;
}