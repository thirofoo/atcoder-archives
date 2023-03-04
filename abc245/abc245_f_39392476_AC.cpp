/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/39392476
 * Submitted at: 2023-03-04 15:04:55
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_f
 * Result: AC
 * Execution Time: 135 ms
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
    vector r_Graph(n,vector<ll>{});
    scc_graph graph(n);
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        graph.add_edge(u,v);
        r_Graph[v].push_back(u);
    }

    vector<bool> visited(n,false);
    vector SCC = graph.scc();
    queue<ll> todo;
    for(auto group:SCC){
        if(group.size() <= 1)continue;
        for(auto ele:group)todo.push(ele);
    }
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        visited[now] = true;
        for(auto to:r_Graph[now]){
            if(!visited[to])todo.push(to);
        }
    }

    ll ans = 0;
    rep(i,n)if(visited[i])ans++;
    print(ans);

    return 0;
}