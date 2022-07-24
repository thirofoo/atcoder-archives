/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/33486514
 * Submitted at: 2022-07-24 10:47:29
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_e
 * Result: AC
 * Execution Time: 372 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,c; cin >> n >> c;
    //各桁において1から始まるときの合成関数を求める。(s0とs1) ※s1は二進数で11111...
    ll s0 = 0,s1 = LLONG_MAX,now = c;
    rep(i,n){
        ll t,a; cin >> t >> a;
        //tに応じて合成関数を更新
        if(t == 1){
            s0 &= a;
            s1 &= a;
        }
        else if(t == 2){
            s0 |= a;
            s1 |= a;
        }
        else{
            s0 ^= a;
            s1 ^= a;
        }
        //前回の操作後(now)の各桁のbitに応じて合成関数を割り当てる
        ll ans = 0;
        for(int j=31;j>=0;j--){
            ans *= 2;
            if(((now & (1LL << j)) && (s1 & (1LL << j))) || (!(now & (1LL << j)) && (s0 & (1LL << j))) )ans++;
        }
        cout << ans << endl;
        //nowを更新
        now = ans;
    }
    
    return 0;
}