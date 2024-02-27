/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc319/submissions/50672060
 * Submitted at: 2024-02-27 11:02:03
 * Problem URL: https://atcoder.jp/contests/abc319/tasks/abc319_e
 * Result: WA
 * Execution Time: 589 ms
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
    
    ll n, x, y; cin >> n >> x >> y;
    vector<vector<T>> Graph(n);
    rep(i,n-1) {
        ll p, t; cin >> p >> t;
        Graph[i].emplace_back(T(i+1,p,t));
        Graph[i+1].emplace_back(T(i,p,t));
    }
    vector<vector<ll>> time(120,vector<ll>(n,1e16));
    // time[i][j] : 時刻 i%120 で Start についた時の j への最短時間
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i,120) {
        pq.push(P(i,0));
        while( !pq.empty() ) {
            auto [now_t, idx] = pq.top(); pq.pop();
            if( time[i][idx] <= now_t ) continue;
            time[i][idx] = now_t;
            for(auto &&[to, p, t] : Graph[idx]) {
                ll next_t = now_t + (p-now_t%p)%p + t;
                if( time[i][to] <= next_t ) continue;
                pq.push(P(next_t,to));
            }
        }
    }
    ll q; cin >> q;
    while( q-- ) {
        ll start; cin >> start;
        start += x;
        cout << start-start%120 + time[start%120][n-1] + y << endl;
    }
    
    return 0;
}