/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc280/submissions/48441612
 * Submitted at: 2023-12-12 14:02:42
 * Problem URL: https://atcoder.jp/contests/abc280/tasks/abc280_e
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// ※ AtCoderのコードテスト上だと動きます
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
    ll n, p; cin >> n >> p;
    // dp[i][j] : 体力iのモンスターを倒すのに必要な攻撃回数の期待値
    vector<mint> dp(n+1,0);
    dp[0] = 0, dp[1] = 1; // 初期値設定
    mint p1 = mint(100-p)/100, p2 = mint(p)/100;
    for(ll i=2; i<=n; i++) {
        dp[i] = p2*(dp[i-2]+1) + p1*(dp[i-1]+1);
    }
    cout << dp[n].val() << endl;
    return 0;
}