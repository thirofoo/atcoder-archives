/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc137/submissions/36753604
 * Submitted at: 2022-11-24 17:59:33
 * Problem URL: https://atcoder.jp/contests/abc137/tasks/abc137_e
 * Result: WA
 * Execution Time: 110 ms
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
    
    ll n,m,p; input(n,m,p);
    vector<vector<int>> Graph(n),r_Graph(n);
    vector<T> edge;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--; c-= p;
        edge.push_back(T(a,b,c));
        Graph[a].push_back(b);
        r_Graph[b].push_back(a);
    }
 
    // vector<ll> cost(n,-LLONG_MAX);
    // cost[0] = 0;
    // rep(i,n-1){
    //     rep(j,m){
    //         auto [from,to,c] = edge[j];
    //         if(cost[from] == -LLONG_MAX)continue;
    //         if(cost[to] < cost[from]+c){
    //             cost[to] = cost[from]+c;
    //         }
    //     }
    // }
 
    // vector<bool> ng(n,false);
    // rep(i,n){
    //     rep(j,m){
    //         auto [from,to,c] = edge[j];
    //         if(cost[from] == -LLONG_MAX)continue;
    //         if(cost[to] < cost[from]+c){
    //             cost[to] = cost[from]+c;
    //             ng[to] = true;
    //         }
    //     }
    // }

    // 従来のベルマンフォードの閉路検出だと複数回のサイクルで更新出来るケースがWA
    // => start~goal経路間にサイクルがあったら-1になるようにする
    // => start~goal経路以外を無視 (誤認しないようにする為)
    // => 順辺でstartから、逆辺でgoalから到達可能な点だけでベルマン

    queue<int> todo;
    vector<bool> reachable_1(n,false),reachable_n(n,false);
    todo.push(0);
    while(!todo.empty()){
        int now = todo.front(); todo.pop();
        if(reachable_1[now])continue;
        reachable_1[now] = true;
        for(auto to:Graph[now]){
            todo.push(to);
        }
    }
    todo.push(n-1);
    while(!todo.empty()){
        int now = todo.front(); todo.pop();
        if(reachable_n[now])continue;
        reachable_n[now] = true;
        for(auto to:r_Graph[now]){
            todo.push(to);
        }
    }

    vector<ll> cost(n,-LLONG_MAX);
    cost[0] = 0;
    rep(i,n-1){
        rep(j,m){
            if(!(reachable_1[j] & reachable_n[j]))continue;
            auto [from,to,c] = edge[j];
            if(cost[from] == -LLONG_MAX)continue;
            if(cost[to] < cost[from]+c){
                cost[to] = cost[from]+c;
            }
        }
    }

    vector<bool> ng(n,false);
    rep(i,n){
        rep(j,m){
            if(!(reachable_1[j] & reachable_n[j]))continue;
            auto [from,to,c] = edge[j];
            if(cost[from] == -LLONG_MAX)continue;
            if(cost[to] < cost[from]+c){
                cost[to] = cost[from]+c;
                ng[to] = true;
            }
        }
    }

    print((ng[n-1] ? -1 : max(cost[n-1],0LL)));
    
    return 0;
}