/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc358/submissions/54593720
 * Submitted at: 2024-06-15 21:53:26
 * Problem URL: https://atcoder.jp/contests/abc358/tasks/abc358_e
 * Result: AC
 * Execution Time: 22 ms
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
    
    ll k; cin >> k;
    vector<ll> c(26);
    rep(i, 26) cin >> c[i];

    vector<mint> kaizyo(k+1,0), rev_kaizyo(k+1,0);
    kaizyo[0] = 1;
    rev_kaizyo[0] = mint(1);
    for(ll i=1; i<=k; i++) {
        kaizyo[i] = kaizyo[i-1]*i;
        rev_kaizyo[i] = mint(1) / kaizyo[i];
    }

    vector dp(27, vector<mint>(k+1, 0));
    dp[0][0] = 1;
    rep(i, 26) {
        rep(j, k+1) {
            rep(l, c[i]+1) {
                ll nj = j+l;
                if(nj > k) break;
                dp[i+1][nj] += dp[i][j] * rev_kaizyo[l];
            }
        }
    }
    mint ans = 0;
    reps(i, 1, k+1) ans += dp[26][i] * kaizyo[i];
    cout << ans.val() << '\n';
    
    return 0;
}