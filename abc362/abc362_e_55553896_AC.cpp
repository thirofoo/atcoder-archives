/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55553896
 * Submitted at: 2024-07-13 21:54:57
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_e
 * Result: AC
 * Execution Time: 119 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    // 等差として有り得るのは高々 N^2 通り
    vector dp(n + 1, vector(n, vector(n, vector<mint>(n + 1, 0))));
    /* dp[i][j][k][l] : i 個までみて 直近で選んだ二つが j, k で合計 l
     * 個選んだ時の場合の数 */
    rep(i, n) for(int j = i + 1; j < n; j++) dp[j + 1][i][j][2] = 1;
    rep(i, n) rep(j, i) for(int k = j + 1; k < i; k++) rep(l, n + 1) {
        // i 番目を採用しない遷移
        dp[i + 1][j][k][l] += dp[i][j][k][l];
        // i 番目を採用する遷移
        if(a[k] - a[j] == a[i] - a[k]) {
            dp[i + 1][k][i][l + 1] += dp[i][j][k][l];
        }
    }
    rep(l, n) {
        if(l == 0) {
            cout << n << " ";
            continue;
        }
        mint ans = 0;
        rep(i, n) rep(j, i) ans += dp[n][j][i][l + 1];
        cout << ans.val() << " ";
    }
    cout << endl;

    return 0;
}