/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc288/submissions/44213110
 * Submitted at: 2023-08-03 23:47:12
 * Problem URL: https://atcoder.jp/contests/abc288/tasks/abc288_e
 * Result: AC
 * Execution Time: 800 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

//セグ木状に乗せる型。
using S = ll;
S op(S a,S b){return min(a,b);} // operator(作用素)
S e(){return 1e16;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC ~ 購入順序を考慮せず広い目で見る → 実は下界が達成可能 ~

    // ある商品を購入する時、購入の順序で C がずれるのが今回の難点。
    // → i番目の購入予定商品を購入する時の C として有り得るのは、
    //   それより前の購入済み商品の個数分ずれた範囲の中

    // → この範囲をどの順序で操作するかを考えるが、
    //   実は "この範囲" にある最小のCを、実際のCとすることが実現可能！(下界達成可能)
    // ※ 購入する商品集合があったとして、今現在で 最小のCを実現してる最大の番号のものを選ぶといける！
    // ※ Ｃを最小化出来るものにおいて、一番後半にしないと、後半にあるCが最小となっているものがずれてしまう為。

    // → 実現可能であれば、後は区間minを前計算すればただの DP に帰着可能！

    ll n,m; cin >> n >> m;
    vector<ll> a(n,0), x(n+1,0);
    segtree<S,op,e> c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        ll ec; cin >> ec;
        c.set(i,ec);
    }
    rep(i,m) {
        ll ex; cin >> ex; 
        x[ex]++;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,1e16));
    // dp[i][j] : 商品iまで考慮して、j個の商品を買ってきた時の最小費用
    dp[0][0] = 0;
    for(ll i=1;i<=n;i++) {
        for(ll j=0;j<=n;j++) {
            if( j != 0 )dp[i][j] = min(dp[i][j], dp[i-1][j-1] + c.prod(max(i-j,0ll),i) + a[i-1]);
            // 買わなくても良い時
            if( !x[i] ) dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }
    // rep(i,n+1) {
    //     rep(j,n+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = 1e16;
    rep(i,n+1) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    
    return 0;
}