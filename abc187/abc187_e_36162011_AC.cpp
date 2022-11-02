/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/36162011
 * Submitted at: 2022-11-03 00:05:02
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_e
 * Result: AC
 * Execution Time: 164 ms
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
    vector<vector<ll>> Graph(n);
    vector<P> edge;
    rep(i,n-1){
        ll a,b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        edge.push_back(P(a,b));
    }
    vector<ll> d(n,-1);
    queue<P> todo;
    todo.push(P(0,0));
    while(!todo.empty()){
        auto [depth,e] = todo.front(); todo.pop();
        d[e] = depth;
        for(auto to:Graph[e]){
            if(d[to] != -1)continue;
            todo.push(P(depth+1,to));
        }
    }

    ll q; input(q);
    vector<ll> c(n,0);
    while(q--){
        ll t,e,x; input(t,e,x);
        e--;
        auto [a,b] = edge[e];
        if(t == 1){
            if(d[a] < d[b]){
                c[0] += x;
                c[b] -= x;
            }
            else{
                c[a] += x;
            }
        }
        else{
            if(d[b] < d[a]){
                c[0] += x;
                c[a] -= x;
            }
            else{
                c[b] += x;
            }
        }
    }

    todo.push(P(0,-1));
    while(!todo.empty()){
        auto [now,pre] = todo.front(); todo.pop();
        if(pre != -1)c[now] += c[pre];
        for(auto to:Graph[now]){
            if(to == pre)continue;
            todo.push(P(to,now));
        }
    }
    rep(i,n)print(c[i]);
    
    return 0;
}