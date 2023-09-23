/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/45889833
 * Submitted at: 2023-09-23 23:15:00
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_f
 * Result: AC
 * Execution Time: 36 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll q, k; cin >> q >> k;
    vector<mint> dp(k+1,0);
    dp[0] = 1;
    while( q-- ) {
        char c; ll x; cin >> c >> x;
        if( c == '+' ) for(ll i=k;i>=x;i--) dp[i] += dp[i-x];
        else for(ll i=x;i<=k;i++) dp[i] -= dp[i-x];
        cout << dp[k].val() << endl;
    }
    
    return 0;
}