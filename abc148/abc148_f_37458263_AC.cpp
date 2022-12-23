/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc148/submissions/37458263
 * Submitted at: 2022-12-23 18:36:06
 * Problem URL: https://atcoder.jp/contests/abc148/tasks/abc148_f
 * Result: AC
 * Execution Time: 52 ms
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
    
    ll n,u,v; input(n,u,v); u--; v--;
    vector<vector<ll>> Graph(n);
    rep(i,n-1){
        ll a,b; input(a,b); a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    vector<ll> dc(n,-1),da(n,-1);
    queue<P> todo;
    todo.push(P(u,0));
    while(!todo.empty()){
        auto [i,d] = todo.front(); todo.pop();
        if(dc[i] != -1)continue;
        dc[i] = d;
        for(auto to:Graph[i]){
            if(dc[to] != -1)continue;
            todo.push(P(to,d+1));
        }
    }
    todo.push(P(v,0));
    while(!todo.empty()){
        auto [i,d] = todo.front(); todo.pop();
        if(da[i] != -1)continue;
        da[i] = d;
        for(auto to:Graph[i]){
            if(da[to] != -1)continue;
            todo.push(P(to,d+1));
        }
    }

    ll ans = -1;
    rep(i,n){
        if(dc[i] < da[i])ans = max(ans,da[i]-1);
    }
    print(ans);
    
    return 0;
}