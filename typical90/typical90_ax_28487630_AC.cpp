/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28487630
 * Submitted at: 2022-01-13 13:07:15
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ax
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> dp(100010,0);

int main() {
    int n,l,mod = 1000000007; cin >> n >> l;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        (dp[i] += dp[i-1]) %= mod;
        if(i-l >= 0) (dp[i] += dp[i-l]) %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}