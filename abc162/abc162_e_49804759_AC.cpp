/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc162/submissions/49804759
 * Submitted at: 2024-01-30 14:09:18
 * Problem URL: https://atcoder.jp/contests/abc162/tasks/abc162_e
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<mint> dp(k+1, 0);
    mint ans = 0;
    for(ll i=k; i>=1; i--) {
        dp[i] = mint(k/i).pow(n);
        for(ll j=2*i; j<=k; j+=i) dp[i] -= dp[j];
        ans += dp[i] * i;
    }
    cout << ans.val() << endl;

    return 0;
}