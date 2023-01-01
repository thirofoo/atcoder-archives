/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/37671148
 * Submitted at: 2023-01-01 13:54:25
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_e
 * Result: WA
 * Execution Time: 350 ms
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
    vector<vector<P>> Graph(n);
    map<P,ll> edge;
    dsu uf(n);
    queue<P> ans;
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        if(a > b)swap(a,b);
        Graph[a].push_back(P(b,c));
        Graph[b].push_back(P(a,c));
        edge[P(a,b)] = i+1;
        todo.push(T(c,a,b));
    }
    
    while(!todo.empty()){
        auto [c,now,pre] = todo.top(); todo.pop();
        if(pre != -1 && uf.same(now,pre))continue;
        if(pre != -1){
            ans.push(P(min(now,pre),max(now,pre)));
            uf.merge(now,pre);
        }
    }
    while(!ans.empty()){
        cout << edge[ans.front()] << " ";
        ans.pop();
    }
    print();
    
    return 0;
}