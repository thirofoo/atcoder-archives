/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/37673965
 * Submitted at: 2023-01-01 16:52:37
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_e
 * Result: AC
 * Execution Time: 207 ms
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
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,q; input(n,m,q);
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        todo.push(T(c,a,b,-1));
    }
    rep(i,q){
        ll u,v,w; input(u,v,w);
        u--; v--;
        todo.push(T(w,u,v,i));
    }

    vector<string> ans(q);
    dsu uf(n);
    while(!todo.empty()){
        auto [c,a,b,i] = todo.top(); todo.pop();
        if(i != -1){
            if(uf.same(a,b))ans[i] = "No";
            else ans[i] = "Yes";
        }
        else{
            if(uf.same(a,b))continue;
            uf.merge(a,b);
        }
    }
    rep(i,q)print(ans[i]);
    
    return 0;
}