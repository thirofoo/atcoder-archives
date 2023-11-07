/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc280/submissions/47352602
 * Submitted at: 2023-11-07 16:10:36
 * Problem URL: https://atcoder.jp/contests/abc280/tasks/abc280_e
 * Result: AC
 * Execution Time: 3 ms
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
    
    ll n, p; cin >> n >> p;
    vector<mint> dp(n+1,0);
    mint p1 = mint{p} / 100, p2 = mint{100-p} / 100;
    for(ll i=1; i<=n; i++) {
        dp[i] += (dp[max(i-2,0ll)]+1) * p1;
        dp[i] += (dp[i-1]+1) * p2;
    }
    cout << dp[n].val() << endl;
    
    return 0;
}