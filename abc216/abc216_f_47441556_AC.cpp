/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/47441556
 * Submitted at: 2023-11-11 13:01:33
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_f
 * Result: AC
 * Execution Time: 133 ms
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
    vector<ll> a(n), b(n);
    vector<P> p;
    rep(i,n) cin >> a[i];
    rep(i,n) {
        cin >> b[i];
        p.emplace_back(P(a[i],b[i]));
    }
    sort(p.begin(), p.end());
    vector<vector<mint>> dp(n+1,vector<mint>(5005,0));
    dp[0][0] = 1;
    // A[i] を昇順に見ることで過去のdpテーブルを利用可能
    // dp[i][j] : i番目まで見て∑B=jの場合の数
    mint ans = 0;
    rep(i,n) {
        // i番目を必ず利用する場合を足していく
        auto [na, nb] = p[i];
        for(ll j=0; j<=na; j++) if( na >= nb+j ) ans += dp[i][j];
        rep(j,5005) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][min(5004ll,j+nb)] += dp[i][j];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}