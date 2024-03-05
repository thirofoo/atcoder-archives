/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50921093
 * Submitted at: 2024-03-05 16:42:40
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_c
 * Result: AC
 * Execution Time: 37 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    rep(i, n-1) {
        ll a, b; cin >> a >> b; a--; b--;
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }
    queue<P> que;
    que.push(P(0,0));
    vector<ll> dist(n, 1e16);
    while( !que.empty() ) {
        auto [dis, now] = que.front(); que.pop();
        if( dist[now] <= dis ) continue;
        dist[now] = dis;
        for(auto next : Graph[now]) {
            if( dist[next] <= dis+1 ) continue;
            que.push(P(dis+1, next));
        }
    }
    ll max_dis = 0, start = 0;
    rep(i,n) {
        if( dist[i] <= max_dis ) continue;
        max_dis = dist[i];
        start = i;
    }
    que.push(P(0,start));
    dist.assign(n, 1e16);
    while( !que.empty() ) {
        auto [dis, now] = que.front(); que.pop();
        if( dist[now] <= dis ) continue;
        dist[now] = dis;
        for(auto next : Graph[now]) {
            if( dist[next] <= dis+1 ) continue;
            que.push(P(dis+1, next));
        }
    }
    ll ans = 0;
    rep(i,n) ans = max(ans, dist[i]);
    cout << ans+1 << endl;
    
    return 0;
}