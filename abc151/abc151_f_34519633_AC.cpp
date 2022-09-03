/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc151/submissions/34519633
 * Submitted at: 2022-09-03 10:30:42
 * Problem URL: https://atcoder.jp/contests/abc151/tasks/abc151_f
 * Result: AC
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> P;
typedef tuple<ll, ll, ll> T;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    //3部探索
    ll n; input(n);
    vector<P> v;
    rep(i,n){
        ld x,y; input(x,y);
        v.push_back(P(x,y));
    }
    auto dist = [](ld x1,ld y1,ld x2,ld y2){
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    };

    //1重目はx座標の3部探索
    ld l = 0,r = 2001,nl1,nr1,nl2,nr2,ns1,ns2;
    while(r-l >= 0.0000001){
        ld m1 = (l+l+r)/3,m2 = (l+r+r)/3;

        //2重目はy座標の3部探索(x = m1,m2の場合のうちdistMaxが大きい方のxを狭める)
        //x = m1 の時の最大距離
        nl1 = 0,nr1 = 2001,ns1 = LLONG_MAX;
        while(nr1-nl1 >= 0.0000001){
            ld nm1 = (nl1+nl1+nr1)/3,nm2 = (nl1+nr1+nr1)/3;
            
            ld ls = 0,rs = 0;
            for(auto [x,y]:v){
                ls = max(ls,dist(x,y,m1,nm1));
                rs = max(rs,dist(x,y,m1,nm2));
            }
            if(ls >= rs)nl1 = nm1;
            else nr1 = nm2;
            ns1 = min({ns1,ls,rs});
        }

        //x = m2 の時の最大距離
        nl2 = 0,nr2 = 2001,ns2 = LLONG_MAX;
        while(nr2-nl2 >= 0.0000001){
            ld nm1 = (nl2+nl2+nr2)/3,nm2 = (nl2+nr2+nr2)/3;
            
            ld ls = 0,rs = 0;
            for(auto [x,y]:v){
                ls = max(ls,dist(x,y,m2,nm1));
                rs = max(rs,dist(x,y,m2,nm2));
            }
            if(ls >= rs)nl2 = nm1;
            else nr2 = nm2;
            ns2 = min({ns2,ls,rs});
        }

        //x = m1の時の方が最大距離が大きい時、少なくともrの方が極値に近い為lを更新
        if(ns1 >= ns2)l = m1;
        //そうでないならrを更新
        else r = m2;
    }
    print(min(sqrt(ns1),sqrt(ns2)));

    return 0;
}