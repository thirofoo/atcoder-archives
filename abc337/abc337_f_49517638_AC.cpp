/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49517638
 * Submitted at: 2024-01-21 00:51:48
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_f
 * Result: AC
 * Execution Time: 207 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> c(n), ball(n,0);
    rep(i,n) {
        cin >> c[i], c[i]--;
        ball[c[i]]++;
    }
    rep(i,n) c.emplace_back(c[i]);
    // 解説 AC
    // 1. 色 c, 左端 l, 右端 r として f(c,l,r) := [l,r) の区間に含まれる色 c の数を作成
    // 2. M 個の箱を使い切るまでシミュ (尺取り)
    // 3. 特定の色において ⌈ f(c,l,r)/k ⌉ 個の箱を使っていることが分かる為計算可能！
    vector<ll> box(n,0);
    auto f = [&](ll color) -> ll {
        if( box[color] == 0 ) return 0;
        return (box[color]-1)/k + 1;
    };
    ll l = 0, r = 0, ans = 0, rest_box = m;
    while(l < n){
        if( r-l >= n || (rest_box == 0 && box[c[r]]%k == 0) ) {
            cout << ans << endl;
            ans -= min( f(c[l])*k, ball[c[l]] );
            box[c[l]]--;
            if( box[c[l]]%k == 0 ) rest_box++;
            ans += min( f(c[l])*k, ball[c[l]] );
            ++l;
        }
        else {
            ans -= min( f(c[r])*k, ball[c[r]] );
            if( box[c[r]]%k == 0 ) rest_box--;
            box[c[r]]++;
            ans += min( f(c[r])*k, ball[c[r]] );
            ++r;
        }
    }
    
    return 0;
}