/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/37671355
 * Submitted at: 2023-01-01 14:07:47
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_e
 * Result: AC
 * Execution Time: 278 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<vector<P>> Graph(n);

    //mapで辺の番号を保持しておく。
    map<P,ll> edge;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        Graph[a].push_back(P(c,b));
        Graph[b].push_back(P(c,a));
        edge[P(min(a,b),max(a,b))] = i+1;
    }

    vector<ll> pre(n,-1),d(n,LLONG_MAX);
    d[0] = 0;

    priority_queue<T,vector<T>,greater<T>> todo;
    for(auto [c,to]:Graph[0])todo.push(T(c,0,to));

    while(!todo.empty()){
        auto [c,from,to] = todo.top(); todo.pop();
        if(d[to] <= c)continue;
        d[to] = c;
        pre[to] = from;

        for(auto [nc,nto]:Graph[to]){
            todo.push(T(c+nc,to,nto));
        }
    }

    rep(i,n-1)cout << edge[P(min(pre[i+1],i+1),max(pre[i+1],i+1))] << " ";
    cout << endl;

    return 0;
}