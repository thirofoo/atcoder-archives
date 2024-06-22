/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54857154
 * Submitted at: 2024-06-23 00:58:05
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_d
 * Result: AC
 * Execution Time: 20 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // check とか構造化束縛をうまく使うと綺麗に書くこと可能
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    // 回文かどうかを判定する関数
    auto check = [&](ll state) -> bool {
        bool flag = true;
        rep(l, k) flag &= ((state >> l & 1) == (state >> (k-l-1) & 1));
        return flag;
    };

    ll mask = (1LL << k)-1;
    vector dp(n+1, vector<mint>((1LL << k), 0));
    dp[0][0] = 1;
    rep(i, n) {
        rep(j, (1LL << k)) {
            for(auto ch:{'A', 'B'}) {
                if(s[i] != '?' && s[i] != ch) continue;
                ll nj = ((j << 1) | ch == 'A') & mask;
                // 回文でない or k 文字まで未探索の場合
                if(!check(nj) || i < k-1) dp[i+1][nj] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(j, (1LL << k)) if(!check(j)) ans += dp[n][j];
    cout << ans.val() << '\n';
    
    return 0;
}