/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/31893432
 * Submitted at: 2022-05-22 15:53:47
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_e
 * Result: TLE
 * Execution Time: 2206 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll, ll> T;
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

    priority_queue<P,vector<P>,greater<P>> todo;
    todo.push(P(0,0));

    while(!todo.empty()){
        auto [c,from] = todo.top(); todo.pop();
        for(auto [nc,to]:Graph[from]){
            if(d[to] > c + nc){
                d[to] = c + nc;
                pre[to] = from;
                todo.push(P(c+nc,to));
            }
        }
    }

    rep(i,n-1)cout << edge[P(min(pre[i+1],i+1),max(pre[i+1],i+1))] << " ";
    cout << endl;

    return 0;
}