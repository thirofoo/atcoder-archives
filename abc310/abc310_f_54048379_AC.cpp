/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/54048379
 * Submitted at: 2024-05-31 19:20:52
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_f
 * Result: AC
 * Execution Time: 3 ms
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
    
    // 解説AC : 今現在のサイコロの振りで生成出来る 10 以下の整数の集合を持つ bit DP
    // 1. そもそも 10 以上の目の集合はどうでも ok
    // 2. 求めるものは 10 が作れるかどうかのみ
    // 3. 複数の 10 の作り方がある場合は重複して数えてはいけない
    // ⇒ 10 以下が作成可能かという答えに直結する状態を持つことで解ける

    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    constexpr ll threshold = 10;
    constexpr ll bit_mask = (1LL << threshold) - 1;

    vector dp(n+1, vector<mint>((1LL << threshold), 0));
    dp[0][0] = 1;
    rep(i, n) {
        mint inv = mint(1) / a[i];
        rep(j, (1LL << threshold)) {
            reps(k, 1, min(threshold, a[i])+1) {
                ll nj = (j | (j << k) | (1LL << (k-1))) & bit_mask;
                dp[i+1][nj] += dp[i][j] * inv;
            }
            if(a[i] >= threshold) {
                dp[i+1][j] += dp[i][j] * inv * (a[i] - threshold);
            }
        }
    }
    mint ans = 0;
    ll ten_bit = (1LL << (threshold-1));
    rep(i, (1LL << threshold)) {
        if( !( i & ten_bit ) ) continue;
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
    
    return 0;
}