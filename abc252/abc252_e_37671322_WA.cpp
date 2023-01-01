/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/37671322
 * Submitted at: 2023-01-01 14:05:35
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_e
 * Result: WA
 * Execution Time: 351 ms
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
    map<P,ll> edge;
    vector<vector<P>> Graph(n);
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        if(a > b)swap(a,b);
        Graph[a].push_back(P(b,c));
        Graph[b].push_back(P(a,c));
        edge[P(a,b)] = i+1;
        if(a == 0)todo.push(T(c,a,b));
    }
    
    dsu uf(n);
    while(!todo.empty()){
        auto [c,pre,now] = todo.top(); todo.pop();
        if(uf.same(now,pre))continue;
        cout << edge[P(min(now,pre),max(now,pre))] << " ";
        uf.merge(now,pre);

        for(auto [to,nc]:Graph[now]){
            if(uf.same(now,to))continue;
            todo.push(T(nc,now,to));
        }
    }
    print();
    
    return 0;
}