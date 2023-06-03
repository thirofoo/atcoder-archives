/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/41941742
 * Submitted at: 2023-06-03 21:10:43
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_c
 * Result: AC
 * Execution Time: 36 ms
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
    
    ll n,d; input(n,d);
    vector<bool> ans(n,false);
    vector<P> p;
    rep(i,n){
        ll x,y; input(x,y);
        p.push_back(P(x,y));
    }
    queue<ll> todo;
    todo.push(0);
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if(ans[now])continue;
        ans[now] = true;
        auto &&[x1,y1] = p[now];
        rep(i,n){
            if(ans[i])continue;
            auto &&[x2,y2] = p[i];
            if( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= d*d ){
                todo.push(i);
            }
        }
    }
    rep(i,n)print( (ans[i] ? "Yes" : "No") );
    
    return 0;
}