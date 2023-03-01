/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc238/submissions/39327321
 * Submitted at: 2023-03-01 13:19:48
 * Problem URL: https://atcoder.jp/contests/abc238/tasks/abc238_e
 * Result: AC
 * Execution Time: 94 ms
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
    
    ll n,q; input(n,q);
    vector<vector<ll>> Graph(n+1);
    queue<ll> todo;
    rep(i,q){
        ll l,r; input(l,r);
        l--; r--;
        Graph[l].push_back(r+1);
        Graph[r+1].push_back(l);
    }
    if(Graph[0].empty()){
        print("No");
        return 0;
    }
    vector<bool> visited(n+1,false);
    todo.push(0);
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = true;
        for(auto to:Graph[now]){
            if(visited[to])continue;
            todo.push(to);
        }
    }
    print(visited[n] ? "Yes" : "No");
    
    return 0;
}