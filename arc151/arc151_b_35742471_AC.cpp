/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc151/submissions/35742471
 * Submitted at: 2022-10-17 10:08:29
 * Problem URL: https://atcoder.jp/contests/arc151/tasks/arc151_b
 * Result: AC
 * Execution Time: 45 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<ll> p(n);
    rep(i,n){
        input(p[i]);
        p[i]--;
    }
    vector<mint> exp(60);
    exp[0] = m;
    for(int i=1;i<60;i++)exp[i] = exp[i-1]*exp[i-1];

    dsu uf(n);
    mint ans = 0,tmp;
    // cnt : 現在の同値成分の数
    ll cnt = 0;
    rep(i,n){
        if(uf.same(i,p[i]))continue;
        uf.merge(i,p[i]);

        // i,p[i]番目の選び方 : mC2
        tmp = m*(m-1)/2;
        // 残りのn-cnt-2項の選び方 : m^(n-cnt-2)
        rep(j,30)if((n-cnt-2) & (1LL << j))tmp *= exp[j];
        ans += tmp;
        cnt++;
    }
    print(ans.val());
    
    return 0;
}