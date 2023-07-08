/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43377107
 * Submitted at: 2023-07-08 22:05:41
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_e
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
    vector<vector<ll>> Graph(n);
    rep(i,n-1){
        ll p; input(p);
        p--;
        Graph[i+1].push_back(p);
        Graph[p].push_back(i+1);
    }

    vector<ll> visited(n,0);
    vector<ll> hoken(n,0);
    rep(i,m){
        ll x,y; input(x,y);
        x--;
        hoken[x] = max(hoken[x],y);
    }

    queue<T> todo;
    todo.push(T(0,-1,hoken[0]+1));
    while(!todo.empty()){
        auto [now,pre,h] = todo.front(); todo.pop();
        visited[now] = h;
        for(auto to:Graph[now]){
            if( to == pre )continue;
            todo.push(T(to,now, max(max(h-1,hoken[to]),0ll) ));
        }
    }
    ll ans = 0;
    rep(i,n)ans += (visited[i] > 0);
    print(ans);
    
    return 0;
}