/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34490159
 * Submitted at: 2022-09-01 16:53:52
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ch
 * Result: AC
 * Execution Time: 14 ms
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
typedef tuple<ll, ll, ll, ll> T;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    //解説AC。各要素の桁事に調べるという観点が無かった。aの要素1つずつで見てしまっていた。
    ll n,q; input(n,q);
    vector<T> query;
    while(q--){
        ll x,y,z,w; input(x,y,z,w);
        x--; y--; z--;
        query.push_back(T(x,y,z,w));
    }

    // n個のaの要素を各桁ごとにbit全探索
    mint ans = 1;
    rep(i,60){
        mint cnt = 0;
        //j : aのi桁目をbitで表現したもの
        rep(j,(1LL << n)){
            bool f = true;
            for(auto [x,y,z,w]:query){
                // jのx,y,z番目のorのbool値
                bool tf = ( (1 << x & j) || (1 << y & j) || (1 << z & j) );

                // ↑の値とwのi桁目が一致するかの確認
                // ※右の式はbool値としては1だが、整数のままだと2^iになる為bool値にキャストする(注意)
                f &= !(tf ^ (bool)(1LL << i & w));
                if(!f)break;
            }
            if(f)cnt++;
        }
        ans *= cnt;
    }
    print(ans.val());
    
    return 0;
}