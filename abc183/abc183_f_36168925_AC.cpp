/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/36168925
 * Submitted at: 2022-11-03 12:59:35
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_f
 * Result: AC
 * Execution Time: 248 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    ll n,q; input(n,q);
    vector<map<ll,ll>> dict(n);
    rep(i,n){
        ll c; input(c); c--;
        // 連結成分iにおけるクラスcの個数
        dict[i][c] = 1;
    }
    dsu uf(n);

    while(q--){
        ll t,a,b; input(t,a,b);
        a--; b--;
        if(t == 1){
            if(uf.same(a,b))continue;

            // 成分a > 成分b の状況作成
            // ACLのuf.mergeはdefaultで大きい方の親成分をrootとすることを利用
            ll x = uf.leader(a),y = uf.leader(b);
            if(y == uf.merge(a,b))swap(x,y);

            // 大きい成分に小さい成分を足す様に回す
            // => for文が合計O(N)になる
            for(auto [cla,num]:dict[y]){
                dict[x][cla] += num;
            }
        }
        else{
            print(dict[uf.leader(a)][b]);
        }
    }
    
    return 0;
}