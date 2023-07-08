/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43365667
 * Submitted at: 2023-07-08 21:38:57
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_d
 * Result: AC
 * Execution Time: 166 ms
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
    
    ll n1, n2, m; input(n1,n2,m);
    vector<vector<ll>> Graph(n1+n2);
    rep(i,m){
        ll a,b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    ll d1 = 0, d2 = 0;

    queue<P> todo;
    todo.push(P(0,0));
    vector<ll> visited(n1,-1);
    while(!todo.empty()){
        auto [now, dis] = todo.front(); todo.pop();
        if( visited[now] != -1 )continue;
        visited[now] = dis;
        for(auto to:Graph[now]){
            if( visited[to] != -1 )continue;
            todo.push(P(to,dis+1));
        }
    }
    rep(i,n1)d1 = max(d1,visited[i]);

    visited.assign(n2,-1);
    todo.push(P(n2-1,0));
    while(!todo.empty()){
        auto [now, dis] = todo.front(); todo.pop();
        if( visited[now] != -1 )continue;
        visited[now] = dis;
        for(auto to:Graph[now+n1]){
            if( visited[to-n1] != -1 )continue;
            todo.push(P(to-n1,dis+1));
        }
    }
    rep(i,n2) d2 = max(d2,visited[i]);

    print(d1+d2+1);
    
    return 0;
}