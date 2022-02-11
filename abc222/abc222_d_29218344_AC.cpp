/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/29218344
 * Submitted at: 2022-02-11 19:18:46
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_d
 * Result: AC
 * Execution Time: 58 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<mint>> dp(3005,vector<mint>(3005,0));

int main() {
    int n; cin >> n;
    vector<int> A(n),B(n);
    rep(i,n)cin >> A[i];
    rep(i,n)cin >> B[i];
    rep(i,3005)dp[0][i] = 1;
    for(int i=1;i<=n;i++){
        int a = A[i-1],b = B[i-1];
        for(int j=a;j<=b;j++)dp[i][j] += dp[i-1][j];
        rep(j,3000)dp[i][j+1] += dp[i][j];
    }
    cout << dp[n][B[n-1]].val() << endl;
    return 0;
}