/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29923300
 * Submitted at: 2022-03-06 21:40:29
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_b
 * Result: AC
 * Execution Time: 45 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,k; cin >> n >> k;
    vector<ll> h(n),dp(n+5,INT_MAX);
    dp[1] = h[0];
    rep(i,n)cin >> h[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i+j > n)break;
            dp[i+j] = min(dp[i+j],dp[i]+abs(h[i-1]-h[i+j-1]));
        }
    }
    cout << dp[n] << '\n';
    return 0;
}