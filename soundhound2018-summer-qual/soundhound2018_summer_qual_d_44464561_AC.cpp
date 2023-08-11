/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/soundhound2018-summer-qual/submissions/44464561
 * Submitted at: 2023-08-11 22:06:34
 * Problem URL: https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d
 * Result: AC
 * Execution Time: 247 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // i年後を降順に調べると、交換場所候補が増える感じ
    // sからの円と tからのスヌーク を求めれば行けそう
    ll n,m,s,t; cin >> n >> m >> s >> t;
    s--; t--;
    vector<vector<T>> Graph(n);
    rep(i,m) {
        ll u,v,a,b; cin >> u >> v >> a >> b;
        u--; v--;
        Graph[u].push_back(T(v,a,b));
        Graph[v].push_back(T(u,a,b));
    }
    vector<ll> en(n,1e16), snuke(n,1e16);
    priority_queue<P,vector<P>,greater<P>> todo;
    todo.push(P(0,s));
    while( !todo.empty() ) {
        auto [cost,now] = todo.top(); todo.pop();
        if( en[now] <= cost ) continue;
        en[now] = cost;
        for(auto [to,a,b]:Graph[now]) {
            if( en[to] <= cost + a ) continue;
            todo.push(P(cost+a,to));
        }
    }
    todo.push(P(0,t));
    while( !todo.empty() ) {
        auto [cost,now] = todo.top(); todo.pop();
        if( snuke[now] <= cost ) continue;
        snuke[now] = cost;
        for(auto [to,a,b]:Graph[now]) {
            if( snuke[to] <= cost + b ) continue;
            todo.push(P(cost+b,to));
        }
    }
    vector<ll> ans(n,0);
    for(ll i=n-1;i>=0;i--) {
        if( i != n-1 ) ans[i] = max(ans[i],ans[i+1]);
        ans[i] = max(ans[i], (ll)(1e15-(en[i]+snuke[i])));
    }
    rep(i,n) cout << ans[i] << endl;
    
    return 0;
}