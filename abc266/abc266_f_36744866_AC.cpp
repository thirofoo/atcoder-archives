/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/36744866
 * Submitted at: 2022-11-24 01:44:31
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_f
 * Result: AC
 * Execution Time: 140 ms
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
    vector<int> dig(n,0);
    vector<vector<ll>> Graph(n,vector<ll>{});
    rep(i,n){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        dig[u]++;
        dig[v]++;
    }

    dsu uf(n);
    vector<bool> vi1(n,false);
    queue<ll> todo;
    rep(i,n)if(dig[i] == 1)todo.push(i);
    while(!todo.empty()){
        auto now = todo.front(); todo.pop();
        if(vi1[now])continue;
        vi1[now] = true;
        dig[now]--;
        for(auto to:Graph[now]){
            dig[to]--;
            if(dig[to] == 1)todo.push(to);
        }
    }
    rep(i,n){
        if(vi1[i])continue;
        vi1[i] = true;
        todo.push(i);
        while(!todo.empty()){
            auto now = todo.front(); todo.pop();
            if(!vi1[now])continue;
            vi1[now] = false;
            for(auto to:Graph[now]){
                if(vi1[to]){
                    uf.merge(now,to);
                    todo.push(to);
                }
            }
        }
    }

    ll q; input(q);
    while(q--){
        ll x,y; input(x,y);
        x--; y--;
        if(uf.same(x,y))print("Yes");
        else print("No");
    }
    
    return 0;
}