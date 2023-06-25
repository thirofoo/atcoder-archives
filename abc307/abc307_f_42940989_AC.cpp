/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc307/submissions/42940989
 * Submitted at: 2023-06-25 10:23:12
 * Problem URL: https://atcoder.jp/contests/abc307/tasks/abc307_f
 * Result: AC
 * Execution Time: 346 ms
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
    rep(i,m){
        ll u,v,w; input(u,v,w);
        u--; v--;
        Graph[u].push_back(P(w,v));
        Graph[v].push_back(P(w,u));
    }
    ll k; input(k);
    vector<ll> a(k);
    rep(i,k){
        input(a[i]);
        a[i]--;
    }
    ll d; input(d);
    vector<ll> x(d+1,1e16);
    rep(i,d)input(x[i+1]);

    vector<ll> ans(n,1e16);
    priority_queue<P,vector<P>,greater<P>> edge;
    priority_queue<P> todo;
    rep(i,k){
        ans[a[i]] = 0;
        for(auto ele:Graph[a[i]]){
            edge.push(ele);
        }
    }

    vector<ll> visited(n,-1e16);
    for(ll day=1;day<=d;day++){
        // edge : P( 長さ, 片方が感染済、もう片方が未感染の辺の未感染者 )
        // 1. edgeから感染する人を列挙
        while( !edge.empty() && edge.top().first <= x[day] ){
            auto [c,to] = edge.top(); edge.pop();
            if( ans[to] <= day )continue;
            todo.push(P(x[day]-c,to));
        }
        // 2. その人から本日感染する人をdijkstra (感染力が強いものを求める)
        while( !todo.empty() ){
            auto [power,now] = todo.top(); todo.pop();
            if( ans[now] < day || power <= visited[now] )continue;
            visited[now] = power;
            ans[now] = day;

            for(auto [dis,to]:Graph[now]){
                if( ans[to] < day )continue;
                if( power < dis )edge.push(P(dis,to));
                else if( power-dis > visited[to] )todo.push(P(power-dis,to));
            }
        }
    }
    rep(i,n)print( (ans[i] >= 1e16 ? -1 : ans[i]) );

    return 0;
}