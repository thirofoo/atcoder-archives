/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35111931
 * Submitted at: 2022-09-24 21:31:30
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_c
 * Result: AC
 * Execution Time: 178 ms
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
    
    ll n,x,y; input(n,x,y); x--; y--;
    vector<vector<int>> Graph1(n),Graph2(n);
    rep(i,n-1){
        int u,v; input(u,v); u--; v--;
        Graph1[u].push_back(v);
        Graph1[v].push_back(u);
    }
    queue<int> todo;
    vector<bool> visited(n,false);
    todo.push(y);
    while(!todo.empty()){
        int now = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = true;
        for(auto to:Graph1[now]){
            if(visited[to])continue;
            todo.push(to);
            Graph2[to].push_back(now);
        }
    }
    todo.push(x);
    while(!todo.empty()){
        int now = todo.front(); todo.pop();
        cout << now+1 << " ";
        if(!Graph2[now].empty())todo.push(Graph2[now][0]);
    }
    print();
    
    return 0;
}