/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29923166
 * Submitted at: 2022-03-06 21:35:00
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_a
 * Result: AC
 * Execution Time: 32 ms
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
    int n; cin >> n;
    vector<ll> h(n),dp(n+5,INT_MAX);
    dp[1] = h[0];
    rep(i,n)cin >> h[i];
    for(int i=1;i<=n;i++){
        if(i+1 <= n)dp[i+1] = min(dp[i+1],dp[i]+abs(h[i-1]-h[i]));
        if(i+2 <= n)dp[i+2] = min(dp[i+2],dp[i]+abs(h[i-1]-h[i+1]));
    }
    cout << dp[n] << '\n';
    return 0;
}