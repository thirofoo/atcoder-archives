/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc279/submissions/36838698
 * Submitted at: 2022-11-27 11:33:15
 * Problem URL: https://atcoder.jp/contests/abc279/tasks/abc279_f
 * Result: AC
 * Execution Time: 74 ms
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

    // point : ufでボールの集合、vectorで箱を別々で管理。(ufだけじゃ無理)
    dsu uf(6e5);
    vector<int> ld(6e5),inv(6e5);
    iota(ld.begin(),ld.end(),0);
    iota(inv.begin(),inv.end(),0);
    while(q--){
        ll t,x; input(t,x); x--;
        if(t == 1){
            ll y; input(y); y--;
            if(ld[y] == -1)continue;
            if(ld[x] == -1){
                // 箱のleaderをyのleaderに移す
                ld[x] = ld[y];
                // 箱のleaderから箱を求めるinvも更新
                inv[ld[x]] = x;
                ld[y] = -1;
            }
            else{
                uf.merge(ld[x],ld[y]);
                ld[x] = uf.leader(ld[x]);
                inv[ld[x]] = x;
                ld[y] = -1;
            }
        }
        else if(t == 2){
            if(ld[x] == -1){
                ld[x] = n;
                inv[ld[x]] = x;
            }
            else{
                uf.merge(ld[x],ld[n]);
                ld[x] = uf.leader(ld[x]);
                inv[ld[x]] = x;
            }
            n++;
        }
        else print(inv[uf.leader(x)]+1);
    }
    
    return 0;
}