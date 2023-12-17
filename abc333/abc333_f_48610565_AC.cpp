/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc333/submissions/48610565
 * Submitted at: 2023-12-17 15:53:25
 * Problem URL: https://atcoder.jp/contests/abc333/tasks/abc333_f
 * Result: AC
 * Execution Time: 486 ms
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
    
    ll n; cin >> n;
    vector<mint> dp(n+1,0), r(n+1,1), fact(n+1,1), r_fact(n+1,1);
    for(ll i=1; i<=n; i++) r[i] = r[i-1]*2;
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r){
        return fact[n] * r_fact[r] * r_fact[n-r];
    };
    
    // dp[i] : 列にi人いる時の先頭が最後まで残る確率
    dp[0] = 1, dp[1] = 1;
    for(ll i=2; i<=n; i++) {
        for(ll j=1; j<=i-1; j++) {
            dp[i] += dp[j] * nCr(i-1,j-1);
        }
        dp[i] /= r[i]-1;
    }
    vector<mint> ans(n+1,0);
    ans[1] = dp[n];
    // i : 先頭からi番目の人が最後に残る確率
    for(ll i=2; i<=n; i++) {
        // j : i番目の人が先頭に来るまでに何人脱落したか
        for(ll j=0; j<=i-1; j++) {
            ans[i] += dp[n-j]*nCr(i-1,j)/r[i-1];
        }
    }
    rep(i,n) cout << ans[i+1].val() << " ";
    cout << endl;
    
    return 0;
}