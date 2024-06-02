/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc179/submissions/54176832
 * Submitted at: 2024-06-02 22:26:14
 * Problem URL: https://atcoder.jp/contests/arc179/tasks/arc179_b
 * Result: AC
 * Execution Time: 290 ms
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
    
    ll m, n; cin >> m >> n;
    vector<ll> x(m), mask(m, 0);
    rep(i,m) {
        cin >> x[i];
        x[i]--;
        mask[x[i]] |= (1LL << i);
    }
    vector dp(n+1, vector<mint>((1LL << m), 0));
    // dp[i][j] : i までみて j が条件を満たしている場合の数
    dp[0][(1LL << m) - 1] = 1;
    rep(i,n) {
        rep(j, (1LL << m)) {
            rep(k,m) {
                if( !(j & (1LL << k)) ) continue;
                ll nj = j ^ (1LL << k);
                nj |= mask[k];
                dp[i+1][nj] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(j, (1LL << m)) ans += dp[n][j];
    cout << ans.val() << endl;
    
    return 0;
}