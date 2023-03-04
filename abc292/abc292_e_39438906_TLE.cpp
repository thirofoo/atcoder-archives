/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc292/submissions/39438906
 * Submitted at: 2023-03-04 22:23:55
 * Problem URL: https://atcoder.jp/contests/abc292/tasks/abc292_e
 * Result: TLE
 * Execution Time: 2207 ms
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
    vector Graph(n,vector<ll>{});
    vector<vector<bool>> edge(n,vector<bool>(n,false)),used(n,vector<bool>(n,false));
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        edge[u][v] = true;
        used[u][v] = true;
    }
    queue<P> todo;
    rep(i,n){
        for(auto ele:Graph[i]){
            for(auto to:Graph[ele]){
                if(i == to || edge[i][to])continue;
                used[i][to] = true;
                todo.push(P(i,to));
            }
        }
    }
    ll ans = 0;
    while(!todo.empty()){
        auto [u,v] = todo.front(); todo.pop();
        if(edge[u][v])continue;
        edge[u][v] = true;
        Graph[u].push_back(v);
        ans++;
        for(auto ele:Graph[v]){
            if(u == ele || used[u][ele])continue;
            used[u][ele] = true;
            todo.push(P(u,ele));
        }
    }
    print(ans);
    
    return 0;
}