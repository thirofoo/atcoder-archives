/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55078697
 * Submitted at: 2024-06-30 21:49:49
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_e
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<vector<mint>> dp(k+1, vector<mint>(2, 0));
    dp[0][0] = 1;
    mint rev = mint(1) / (n*n);
    reps(i, 1, k+1) {
        dp[i][0] = dp[i-1][0] * mint(n*n - 2*n + 2) * rev + dp[i-1][1] * mint(2) * rev;
        dp[i][1] = dp[i-1][0] * mint(2*n-2) * rev + dp[i-1][1] * mint(n*n-2) * rev;
        // cerr << dp[i][0].val() << ' ' << dp[i][1].val() << '\n';
    }
    mint num = mint(n+1) * n / 2 - 1;
    mint ans = dp[k][0];
    if(n != 1) ans += dp[k][1] * num / (n-1);
    cout << ans.val() << '\n';
    
    return 0;
}