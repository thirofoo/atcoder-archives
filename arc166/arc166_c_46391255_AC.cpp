/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc166/submissions/46391255
 * Submitted at: 2023-10-09 00:00:02
 * Problem URL: https://atcoder.jp/contests/arc166/tasks/arc166_c
 * Result: AC
 * Execution Time: 251 ms
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
    
    // 解説AC 
    // 実は斜めで考えると独立な辺集合になってる
    // ⇒ その辺集合の色の塗り方を考える
    // ⇒ 斜めを1直線に伸ばして左端から塗る遷移を考えるとフィボナッチになってる
    // ⇒ フィボナッチ前計算 ( 辺集合の左上・右下 は綺麗な形の積で計算可 ⇒ これも前計算 )

    ll t; cin >> t;
    vector<mint> f(3000000,0), r(3000000,0);
    f[0] = 1, f[1] = 1, r[0] = 1;
    for(ll i=2;i<=3000000;i++) f[i] = f[i-1] + f[i-2];
    for(ll i=2;i<=3000000;i+=2) r[i] = r[i-2]*f[i];

    while( t-- ) {
        ll h, w; cin >> h >> w;
        if( h >= w ) swap(h,w);
        // 左上 & 右下
        mint ans = r[2*h]*r[2*h];
        ans *= mint(f[2*h+1]).pow(w-h);
        cout << ans.val() << endl;
    }
    
    return 0;
}