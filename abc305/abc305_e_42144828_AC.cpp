/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/42144828
 * Submitted at: 2023-06-10 21:39:38
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_e
 * Result: AC
 * Execution Time: 194 ms
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
    
    ll n,m,k; input(n,m,k);
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll a,b; input(a,b);
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    priority_queue<P> todo;
    rep(i,k){
        ll p,h; input(p,h);
        p--;
        todo.push(P(h+1,p));
    }
    vector<ll> visited(n,0);
    while(!todo.empty()){
        auto [h,p] = todo.top(); todo.pop();
        if(h <= visited[p])continue;
        visited[p] = h;
        for(auto to:Graph[p]){
            if(h-1 <= visited[to])continue;
            todo.push(P(h-1,to));
        }
    }
    queue<ll> ans;
    rep(i,n)if(visited[i] > 0)ans.push(i);

    print(ans.size());
    while(!ans.empty()){
        cout << ans.front()+1 << " ";
        ans.pop();
    }
    print();
    
    return 0;
}