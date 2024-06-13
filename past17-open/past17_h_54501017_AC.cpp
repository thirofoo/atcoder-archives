/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54501017
 * Submitted at: 2024-06-13 18:32:41
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_h
 * Result: AC
 * Execution Time: 150 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(n), c(n);
    vector<vector<P>> lecture(5000);
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i]; b[i]--;
        lecture[b[i]].emplace_back(P(a[i], c[i]));
    }

    vector dp(5001, vector<ll>(m+1, INF));
    dp[0][0] = 0;
    rep(i, 5000) rep(j, m+1) {
        // 授業を取らない遷移
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        // 授業を取る遷移
        for(auto [av, cv] : lecture[i]) {
            ll nj = min(m, j + cv);
            dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + av);
        }
    }
    cout << (dp[5000][m] == INF ? -1 : dp[5000][m]) << endl;
    
    return 0;
}