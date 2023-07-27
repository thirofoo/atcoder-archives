/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc201/submissions/43997953
 * Submitted at: 2023-07-28 02:55:33
 * Problem URL: https://atcoder.jp/contests/abc201/tasks/abc201_e
 * Result: AC
 * Execution Time: 178 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<P>> Graph(n);
    rep(i,n-1){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        Graph[u].push_back(P(v,w));
        Graph[v].push_back(P(u,w));
    }
    // xor(i,j) = xor(xor(x,i),xor(x,j))
    // → 特定の地点からの xor を前計算すれば桁事に求まる
    vector<ll> dist(n,-1);
    queue<P> todo;
    todo.push(P(0,0));
    while(!todo.empty()){
        auto [now, d] = todo.front(); todo.pop();
        if( dist[now] != -1 ) continue;
        dist[now] = d;
        for(auto [to, w]:Graph[now]){
            if( dist[to] != -1 ) continue;
            todo.push( P(to, d^w) );
        }
    }
    mint ans = 0;
    rep(i,60){
        // 各桁で考えるのは定石
        // 答えに寄与するのは xor が 1,0のものの数の積
        mint c1 = 0, c2 = 0;
        rep(j,n){
            if( dist[j] & (1LL << i) ) c1++;
            else c2++;
        }
        ans += (1LL << i) * c1 * c2;
    }
    cout << ans.val() << endl;

    return 0;
}