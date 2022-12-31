/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2014-morning-easy/submissions/37657190
 * Submitted at: 2022-12-31 18:44:46
 * Problem URL: https://atcoder.jp/contests/code-festival-2014-morning-easy/tasks/code_festival_morning_easy_c
 * Result: WA
 * Execution Time: 25 ms
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
    
    ll n,m,s,t; input(n,m,s,t);
    s--; t--;
    vector Graph(n,vector<P>{});
    rep(i,m){
        ll x,y,d; input(x,y,d);
        x--; y--;
        Graph[x].push_back(P(y,d));
        Graph[y].push_back(P(x,d));
    }

    priority_queue<P,vector<P>,greater<P>> todo;
    vector<ll> d1(n,LLONG_MAX),d2(n,LLONG_MAX);
    todo.push(P(s,0));
    while(!todo.empty()){
        auto [now,c] = todo.top(); todo.pop();
        if(d1[now] <= c)continue;
        d1[now] = c;
        for(auto [to,nc]:Graph[now]){
            if(d1[to] > c + nc)todo.push(P(to,c+nc));
        }
    }
    todo.push(P(t,0));
    while(!todo.empty()){
        auto [now,c] = todo.top(); todo.pop();
        if(d2[now] != LLONG_MAX)continue;
        d2[now] = c;
        for(auto [to,nc]:Graph[now]){
            if(d2[to] > c + nc)todo.push(P(to,c+nc));
        }
    }
    rep(i,n)if(d1[i] != LLONG_MAX && d1[i] == d2[i])return print(i+1),0;
    print(-1);
    
    return 0;
}