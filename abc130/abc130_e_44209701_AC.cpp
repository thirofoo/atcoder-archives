/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc130/submissions/44209701
 * Submitted at: 2023-08-03 21:34:39
 * Problem URL: https://atcoder.jp/contests/abc130/tasks/abc130_e
 * Result: AC
 * Execution Time: 155 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<ll> s(n), t(m);
    rep(i,n) cin >> s[i];
    rep(i,m) cin >> t[i];
    vector<fenwick_tree<mint>> dp(n+1,fenwick_tree<mint>(m+1));
    rep(i,n+1) dp[i].add(0,1);
    // 部分列の場合の数を更新しつつ区間和で求めれば行けそう
    mint ans = 0;
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            if( s[i-1] == t[j-1] ) {
                ans += dp[i-1].sum(0,j);
                dp[i].add(j,dp[i-1].sum(0,j));
            }
            dp[i].add(j,dp[i-1].sum(j,j+1));
        }
    }
    // rep(i,n+1) {
    //     rep(j,m+1) {
    //         cout << dp[i].sum(j,j+1).val() << " ";
    //     }
    //     cout << endl;
    // }
    cout << (ans+1).val() << endl;
    
    return 0;
}