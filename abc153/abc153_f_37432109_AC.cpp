/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc153/submissions/37432109
 * Submitted at: 2022-12-22 01:38:09
 * Problem URL: https://atcoder.jp/contests/abc153/tasks/abc153_f
 * Result: AC
 * Execution Time: 113 ms
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

// S が data, F が lazy
using S = ll;
using F = ll;
// operator(作用素)
S op(S a,S b){
    return a+b;
}
// 遅延データ反映
S mapping(F f,S x){
    return f+x;
}
// 遅延データ作用
F composition(F f,F g){
    return f+g;
}
S e(){ return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,d,a; input(n,d,a);
    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(n);
    vector<P> enemy;
    rep(i,n){
        ll x,h; input(x,h);
        enemy.push_back(P(x,h));
    }
    sort(enemy.begin(),enemy.end());

    ll ans = 0;
    rep(i,n){
        auto [place,HP] = enemy[i];
        ll already = lsg.get(i);
        if(HP > already){
            // 残り体力を削れる回数をインクリメント
            ll atack_cnt = (HP - already - 1) / a + 1;
            ans += atack_cnt;
            auto itr = lower_bound(enemy.begin(),enemy.end(),P(place+2*d,LLONG_MAX));
            lsg.apply(i,itr-enemy.begin(),atack_cnt*a);
        }
    }
    print(ans);
    
    return 0;
}