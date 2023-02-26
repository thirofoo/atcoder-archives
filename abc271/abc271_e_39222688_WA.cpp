/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/39222688
 * Submitted at: 2023-02-26 20:12:55
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_e
 * Result: WA
 * Execution Time: 123 ms
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
    vector<vector<T>> Graph(n);
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        Graph[a].push_back(T(b,c,i+1));
    }
    vector<vector<ll>> e(200005,vector<ll>{});
    rep(i,k){
        ll t; input(t);
        e[t].push_back(i);
    }
    vector<ll> ans(n,LLONG_MAX);
    todo.push(T(0,0,-1));
    while(!todo.empty()){
        auto [cost,now,ind] = todo.top(); todo.pop();
        if(ans[now] <= cost) continue;
        ans[now] = cost;
        for(auto [to,c,i]:Graph[now]){
            if(ans[to] <= cost+c)continue;
            if(e[i].empty())continue;
            auto itr = upper_bound(e[i].begin(),e[i].end(),ind);
            if(itr == e[i].end())continue;
            todo.push(T(cost+c,to,*itr));
        }
    }
    print(ans[n-1] == LLONG_MAX ? -1 : ans[n-1]);
    
    return 0;
}