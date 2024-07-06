/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55293437
 * Submitted at: 2024-07-06 21:49:20
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_e
 * Result: AC
 * Execution Time: 107 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<P>> Graph(n);
    ll sum = 0;
    rep(i, n-1) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        Graph[a].emplace_back(P(b, c));
        Graph[b].emplace_back(P(a, c));
        sum += c;
    }
    // 直径だけ引けばよい
    vector<ll> dist(n, INF);
    queue<P> que;
    que.push(P(0, 0));
    while(!que.empty()) {
        auto [now, d] = que.front(); que.pop();
        if(dist[now] != INF) continue;
        dist[now] = d;
        for(auto [next, cost] : Graph[now]) {
            if(dist[next] != INF) continue;
            que.push(P(next, d+cost));
        }
    }
    ll s = 0;
    rep(i, n) if(dist[i] > dist[s]) s = i;
    fill(dist.begin(), dist.end(), INF);
    que.push(P(s, 0));
    while(!que.empty()) {
        auto [now, d] = que.front(); que.pop();
        if(dist[now] != INF) continue;
        dist[now] = d;
        for(auto [next, cost] : Graph[now]) {
            if(dist[next] != INF) continue;
            que.push(P(next, d+cost));
        }
    }

    ll ans = 0;
    rep(i, n) ans = max(ans, dist[i]);
    cout << sum*2-ans << endl;
    
    return 0;
}