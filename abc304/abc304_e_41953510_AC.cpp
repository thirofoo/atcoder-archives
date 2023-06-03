/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/41953510
 * Submitted at: 2023-06-03 21:31:13
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_e
 * Result: AC
 * Execution Time: 575 ms
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
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    vector<P> edge;
    ll k; input(k);
    rep(i,k){
        ll x,y; input(x,y);
        x--; y--;
        edge.push_back(P(x,y));
    }

    vector<ll> ele(n,-1);
    queue<ll> todo;
    ll cnt = 0;
    rep(i,n){
        if(ele[i] != -1)continue;
        todo.push(i);
        while(!todo.empty()){
            ll now = todo.front(); todo.pop();
            if(ele[now] != -1)continue;
            ele[now] = cnt;
            for(auto to:Graph[now]){
                if(ele[to] != -1)continue;
                todo.push(to);
            }
        }
        cnt++;
    }
    vector<set<ll>> st(cnt);
    rep(i,k){
        auto [x,y] = edge[i];
        if(ele[x] == ele[y])continue;
        st[ele[x]].insert(ele[y]);
        st[ele[y]].insert(ele[x]);
    }

    ll q; input(q);
    while(q--){
        ll p,q; input(p,q);
        p--; q--;
        if(st[ele[p]].count(ele[q]))print("No");
        else print("Yes");
    }
    
    return 0;
}