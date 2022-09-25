/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35148996
 * Submitted at: 2022-09-25 09:14:10
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_f
 * Result: WA
 * Execution Time: 276 ms
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

    ll n,m; input(n,m);
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,n){
        ll x; input(x);
        todo.push(T(x,i,-1));
    }
    rep(i,n){
        ll y; input(y);
        todo.push(T(y,i,-2));
    }
    while(m--){
        ll a,b,z; input(a,b,z); a--; b--;
        todo.push(T(z,a,b));
    }
    // n,2*n+1をそれぞれ空港、港の超頂点とする。
    ll ans = 0;
    dsu uf(n+2);
    while(!todo.empty()){
        auto [c,at,to] = todo.top(); todo.pop();
        if(to == -1 && !uf.same(at,n)){
            uf.merge(at,n);
            ans += c;
            print(c,at,to);
        }
        if(to == -2 && !uf.same(at,n+1)){
            uf.merge(at,n+1);
            ans += c;
            print(c,at,to);
        }
        if(to >= 0 && !uf.same(at,to)){
            uf.merge(at,to);
            ans += c;
            print(c,at,to);
        }
        if((uf.same(n,n+1) && uf.size(n) == n+2) || (!uf.same(n,n+1) && uf.size(n) == n+1))break;
    }
    print(ans);
    
    return 0;
}