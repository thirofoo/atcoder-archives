/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc292/submissions/39421016
 * Submitted at: 2023-03-04 21:22:43
 * Problem URL: https://atcoder.jp/contests/abc292/tasks/abc292_d
 * Result: WA
 * Execution Time: 104 ms
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
    vector<ll> dig(n,0);
    dsu uf(n);
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        uf.merge(u,v);
        dig[u]++;
        dig[v]++;
    }
    if(n != m){
        print("No");
        return 0;
    }
    vector g = uf.groups();
    vector<bool> visited(n,false);
    queue<ll> todo;
    for(auto group:g){
        for(auto ele:group)if(dig[ele] == 1)todo.push(ele);
        while(!todo.empty()){
            ll now = todo.front(); todo.pop();
            if(visited[now])continue;
            visited[now] = true;
            for(auto to:Graph[now]){
                dig[now]--;
                dig[to]--;
                if(dig[to] == 1)todo.push(to);
            }
        }
        bool f = false;
        for(auto ele:group){
            if(!visited[ele]){
                f = true;
                break;
            }
        }
        if(!f){
            print("No");
            return 0;
        }
    }
    print("Yes");
    
    return 0;
}