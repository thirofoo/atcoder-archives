/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc206/submissions/45980382
 * Submitted at: 2023-09-27 14:47:21
 * Problem URL: https://atcoder.jp/contests/abc206/tasks/abc206_e
 * Result: AC
 * Execution Time: 20 ms
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

    // 解説AC (天才) ~ 素因数の種類数で包除原理 ~
    // 各素数を因数にもつ数字を1つの集合としたベン図を考える
    // ⇒ 互いに素でない (x,y) の個数は包除原理で求まる
    // ⇒ 各素因数を複数個持たないものにおいて、
    // 素因数の種類が奇数 : a_C_2 を足す
    //       〃     偶数 : a_C_2 を引く
    // ※ 例えば 2,3 を持つ奇数種類の数を足すと、6の時を数えすぎる為、偶数種類の時のペアを引いてあげる感じ

    // ⇒ x < y とすると ↑ のように Conbination の数に等しくなる為そう考える
    // ⇒ g = x となってしまうものを引けば ok

    ll l, r; cin >> l >> r;
    vector<ll> p_cnt(r+1, 0);
    for(ll i=2;i<=r;i++) {
        // ~~eratothenes と同じ要領で行う~~

        // 素数で無い時は continue
        if( p_cnt[i] ) continue;
        for(ll j=i;j<=r;j+=i) {
            if( p_cnt[j] == -1 ) continue;
            p_cnt[j]++;
        }

        // 2つ以上同じ素因数を含む数は今回無視したいので求める
        for(ll j=i*i;j<=r;j+=i*i) p_cnt[j] = -1;
    }

    ll ans = 0;
    for(ll i=2;i<=r;i++) {
        if( p_cnt[i] == -1 ) continue;

        // 素因数の種類数で包除
        ll tmp = ( r/i ) - ( (l-1)/i );
        if( p_cnt[i]%2 ) ans += tmp*(tmp-1)/2;
        else ans -= tmp*(tmp-1)/2;
    }
    // 最後に x=g || y=g になるケースを除く
    for(ll g=2;g<=r;g++) {
        if( g < l ) continue;
        ans -= r/g - 1;
    }
    cout << 2 * ans << endl;
    
    return 0;
}