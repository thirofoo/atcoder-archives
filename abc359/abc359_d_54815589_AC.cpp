/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54815589
 * Submitted at: 2024-06-22 21:24:45
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_d
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    // 直近 k 個分を bit でもつ bitDP
    ll mask = (1LL << k)-1;
    vector dp(n+1, vector<mint>((1LL << k), 0));
    dp[0][0] = 1;

    rep(i, n) {
        rep(j, (1LL << k)) {
            if(s[i] == '?') {
                ll nj1 = ((j << 1) | 1) & mask;
                // この nj1 が回文かどうかを確認
                bool ng = true;
                rep(l, k) {
                    if((nj1 >> l & 1) != (nj1 >> (k-l-1) & 1)) {
                        ng = false;
                        break;
                    }
                }
                ng &= (i >= k-1);
                if(!ng) dp[i+1][nj1] += dp[i][j];

                ll nj2 = (j << 1) & mask;
                // この nj2 が回文かどうかを確認
                ng = true;
                rep(l, k) {
                    if((nj2 >> l & 1) != (nj2 >> (k-l-1) & 1)) {
                        ng = false;
                        break;
                    }
                }
                ng &= (i >= k-1);
                if(!ng) dp[i+1][nj2] += dp[i][j];
            }
            else {
                ll nj = ((j << 1) | s[i] == 'A') & mask;
                // この nj が回文かどうかを確認
                bool ng = true;
                rep(l, k) {
                    if((nj >> l & 1) != (nj >> (k-l-1) & 1)) {
                        ng = false;
                        break;
                    }
                }
                ng &= (i >= k-1);
                if(!ng) dp[i+1][nj] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(j, (1LL << k)) {
        bool ng = true;
        rep(l, k) {
            if((j >> l & 1) != (j >> (k-l-1) & 1)) {
                ng = false;
                break;
            }
        }
        if(ng) continue;
        ans += dp[n][j];
    }
    cout << ans.val() << '\n';
    
    return 0;
}