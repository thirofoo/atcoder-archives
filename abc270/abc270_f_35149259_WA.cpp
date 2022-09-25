/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35149259
 * Submitted at: 2022-09-25 09:36:01
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_f
 * Result: WA
 * Execution Time: 412 ms
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
    priority_queue<T,vector<T>,greater<T>> todo,todo2;
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
    ll ans = 0,tmp = 0;
    dsu uf1(n+2),uf2(n+2),uf3(n+2),uf4(n+2);
    while(!todo.empty()){
        auto [c,at,to] = todo.top();
        todo2.push(todo.top()); todo.pop();
        if(to == -1 && !uf1.same(at,n)){
            uf1.merge(at,n);
            tmp += c;
        }
        if(to == -2 && !uf1.same(at,n+1)){
            uf1.merge(at,n+1);
            tmp += c;
        }
        if(to >= 0 && !uf1.same(at,to)){
            uf1.merge(at,to);
            tmp += c;
        }
    }
    ans = max(tmp,ans);
    tmp = 0;
    while(!todo2.empty()){
        auto [c,at,to] = todo2.top();
        todo.push(todo2.top()); todo2.pop();
        if(to == -1 && !uf2.same(at,n)){
            uf2.merge(at,n);
            tmp += c;
        }
        if(to == -2 && !uf2.same(at,n+1)){
            uf2.merge(at,n+1);
            tmp += c;
        }
        if(to >= 0 && !uf2.same(at,to)){
            uf2.merge(at,to);
            tmp += c;
        }
    }
    ans = max(tmp,ans);
    tmp = 0;
    while(!todo.empty()){
        auto [c,at,to] = todo.top();
        todo2.push(todo.top()); todo.pop();
        if(to == -1 && !uf3.same(at,n)){
            uf3.merge(at,n);
            tmp += c;
        }
        if(to == -2 && !uf3.same(at,n+1)){
            uf3.merge(at,n+1);
            tmp += c;
        }
        if(to >= 0 && !uf3.same(at,to)){
            uf3.merge(at,to);
            tmp += c;
        }
    }
    ans = max(tmp,ans);
    tmp = 0;
    while(!todo.empty()){
        auto [c,at,to] = todo2.top(); todo2.pop();
        if(to == -1 && !uf4.same(at,n)){
            uf4.merge(at,n);
            tmp += c;
        }
        if(to == -2 && !uf4.same(at,n+1)){
            uf4.merge(at,n+1);
            tmp += c;
        }
        if(to >= 0 && !uf4.same(at,to)){
            uf4.merge(at,to);
            tmp += c;
        }
    }
    ans = max(tmp,ans);
    print(ans);
    
    return 0;
}