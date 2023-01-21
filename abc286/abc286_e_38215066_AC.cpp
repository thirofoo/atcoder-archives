/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc286/submissions/38215066
 * Submitted at: 2023-01-21 21:53:47
 * Problem URL: https://atcoder.jp/contests/abc286/tasks/abc286_e
 * Result: AC
 * Execution Time: 214 ms
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
    vector<ll> a(n);
    vector<string> s(n);
    rep(i,n)input(a[i]);
    rep(i,n)input(s[i]);

    vector<vector<ll>> Graph(n);
    rep(i,n)rep(j,n)if(s[i][j] == 'Y')Graph[i].push_back(j);

    // 1度いったらもう考慮しなくてよい
    vector<vector<ll>> ans(n,vector<ll>(n,0)),visited(n,vector<ll>(n,LLONG_MAX));
    ll q; input(q);
    queue<T> todo;
    rep(i,n){
        for(auto to:Graph[i])todo.push(T(0,a[i],i));
        while(!todo.empty()){
            auto [c1,c2,now] = todo.front(); todo.pop();
            if(visited[i][now] < c1 || (visited[i][now] == c1 && ans[i][now] >= c2))continue;
            visited[i][now] = c1;
            ans[i][now] = c2;
            for(auto to:Graph[now]){
                if(visited[i][to] <= c1)continue;
                todo.push(T(c1+1,c2+a[to],to));
            }
        }
    }
    while(q--){
        ll u,v; input(u,v); u--; v--;
        print(visited[u][v] == LLONG_MAX ? "Impossible" : to_string(visited[u][v]) + " " + to_string(ans[u][v]));
    }
    
    return 0;
}