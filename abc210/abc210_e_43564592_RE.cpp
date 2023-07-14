/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/43564592
 * Submitted at: 2023-07-15 02:54:44
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_e
 * Result: RE
 * Execution Time: 2294 ms
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
    
    // 愚直探索が調和級数で通りそう
    ll n,m; input(n,m);
    priority_queue<P,vector<P>,greater<P>> todo;
    rep(i,m){
        ll a,c; input(a,c);
        todo.push( P(a,c) );
    }

    ll ans = 0;
    dsu uf(n);
    while(!todo.empty()){
        auto [a,c] = todo.top(); todo.pop();
        for(ll i=0;i<a;i++){
            if( !uf.same(i,(i+a)%n) ){
                uf.merge(i,(i+a)%n);
                ans += c;
            }
        }
    }
    print( (uf.size(0) == n ? ans : -1) );
    
    return 0;
}