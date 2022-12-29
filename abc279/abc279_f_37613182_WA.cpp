/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc279/submissions/37613182
 * Submitted at: 2022-12-29 16:49:08
 * Problem URL: https://atcoder.jp/contests/abc279/tasks/abc279_f
 * Result: WA
 * Execution Time: 81 ms
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
    
    ll n,q; input(n,q);
    // ボールの集合,箱を別で管理
    // 箱はボールの集合のleaderを基準にする
    // => query1がO(1)で出来る(集合の移動が一括で出来る)

    // box[i] : leaderがボールi である集合の箱
    // leader[i] : 箱i に入ってる集合のleader
    vector<ll> box(n+1+q),leader(n+1+q);
    iota(box.begin(),box.end(),0);
    iota(leader.begin(),leader.end(),0);

    dsu uf(n+1+q);
    n++;
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll x,y; input(x,y);
            ll xl = leader[x],yl = leader[y];

            if(yl == -1)continue;
            else if(xl == -1){
                leader[x] = yl;
                box[leader[x]] = x;
            }
            else{
                // 新たな集合の方
                uf.merge(xl,yl);
                leader[x] = uf.leader(xl);
                box[leader[x]] = x;

                // 消えた集合の方
                leader[y] = -1;
            }
        }
        else if(t == 2){
            ll x; input(x);
            if(leader[x] == -1){
                leader[x] = n;
            }
            else{
                uf.merge(leader[x],n);
                leader[x] = uf.leader(n);
            }
            box[leader[x]] = x;
            n++;
        }
        else{
            ll x; input(x);
            print(box[uf.leader(x)]);
        }
    }
    
    return 0;
}