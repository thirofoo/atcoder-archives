/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/39555289
 * Submitted at: 2023-03-09 18:48:04
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_d
 * Result: WA
 * Execution Time: 50 ms
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
    
    ll n; input(n);
    dsu uf(n);
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,n-1){
        ll u,v,w; input(u,v,w);
        u--; v--;
        todo.push(T(w,u,v));
    }
    ll ans = 0;
    while(!todo.empty()){
        auto [w,u,v] = todo.top(); todo.pop();
        ans += uf.size(u)*uf.size(v)*w;
        uf.merge(u,v);
    }
    print(ans);
    
    return 0;
}