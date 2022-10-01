/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/35318315
 * Submitted at: 2022-10-01 22:40:08
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_e
 * Result: RE
 * Execution Time: 273 ms
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
    vector<vector<P>> Graph(n);
    vector<T> edge;
    map<T,vector<ll>> t;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        Graph[a].push_back(P(b,c));
        edge.push_back(T(a,b,c));
    }
    rep(i,k){
        ll e; input(e); e--;
        t[edge[e]].push_back(i);
    }

    priority_queue<T,vector<T>,greater<T>> todo;
    // T(重み,現在地,部分列どこまで使ったか
    vector<ll> c(n,LLONG_MAX);
    todo.push(T(0,-1,0));
    while(!todo.empty()){
        auto [cost,idx,now] = todo.top(); todo.pop();
        if(cost >= c[now])continue;
        c[now] = cost;
        for(auto [to,nc]:Graph[now]){
            auto itr = lower_bound(t[T(now,to,nc)].begin(),t[T(now,to,nc)].end(),idx+1);
            if(itr == t[T(now,to,nc)].end())continue;
            todo.push(T(cost+nc,to,*itr));
        }
    }
    print(c[n-1] == LLONG_MAX ? -1 : c[n-1]);
    
    return 0;
}