/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc168/submissions/37277298
 * Submitted at: 2022-12-15 10:12:38
 * Problem URL: https://atcoder.jp/contests/abc168/tasks/abc168_d
 * Result: AC
 * Execution Time: 81 ms
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
    vector Graph(n,vector<ll>({}));
    vector<ll> pre(n,LLONG_MAX);
    rep(i,m){
        ll a,b; input(a,b); a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    queue<P> todo;
    todo.push(P(0,0));
    while(!todo.empty()){
        auto [now,p] = todo.front(); todo.pop();
        if(pre[now] != LLONG_MAX)continue;
        pre[now] = p+1;
        for(auto to:Graph[now]){
            if(pre[to] != LLONG_MAX)continue;
            todo.push(P(to,now));
        }
    }
    for(int i=1;i<n;i++)if(pre[i] == LLONG_MAX)return print("No"),0;
    print("Yes");
    for(int i=1;i<n;i++)print(pre[i]);
    
    return 0;
}