/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34424566
 * Submitted at: 2022-08-28 19:20:17
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bn
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; cin >> n;
    //解説AC。頭良すぎ。
    //そもそも転倒数は、ある2数を取って前者が後者より大きいものの数の総和。
    //期待値には線形性があるから、転倒数の期待値 = ある2つの位置の数における大小の期待値の和 と言える。
    // => ある2つの位置の大小はnC2 = O(N^2)で余裕で間に合うから1つ1つの選び方の期待値を求める。
    vector<P> num;
    rep(i,n){
        ll l,r; cin >> l >> r;
        num.push_back(P(l,r));
    }
    ld ans = 0;
    rep(i,n){
        for(ll j=i+1;j<n;j++){
            //i,jで2数を選んだらその期待値をO(N)で求める。
            ld tmp = 0;
            auto [l1,r1] = num[i];
            auto [l2,r2] = num[j];
            for(ll k=l1;k<=r1;k++){
                tmp += min(max(0LL,k-l2),r2-l2+1);
            }
            tmp /= (r1-l1+1)*(r2-l2+1);
            ans += tmp;
        }
    }
    cout << ans << endl;
    
    return 0;
}