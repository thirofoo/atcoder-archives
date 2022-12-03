/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/36944074
 * Submitted at: 2022-12-03 18:11:27
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_e
 * Result: AC
 * Execution Time: 79 ms
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
    
    ll n,m,x,y; input(n,m,x,y);
    x--; y--;
    vector<vector<T>> Graph(n);
    rep(i,m){
        ll a,b,t,k; input(a,b,t,k);
        a--; b--;
        Graph[a].push_back(T(b,t,k));
        Graph[b].push_back(T(a,t,k));
    }
    // P(経過時間,出発点)
    vector<ll> ans(n,LLONG_MAX);
    priority_queue<P,vector<P>,greater<P>> todo;
    todo.push(P(0,x));
    while(!todo.empty()){
        auto [time,now] = todo.top(); todo.pop();
        if(time >= ans[now])continue;
        ans[now] = time;
        for(auto [to,c,T]:Graph[now]){
            if(time + (T-time%T)%T + c < ans[to]){
                todo.push(P(time + (T-time%T)%T + c,to));
            }
        }
    }
    print((ans[y] == LLONG_MAX ? -1 : ans[y]));
    
    return 0;
}