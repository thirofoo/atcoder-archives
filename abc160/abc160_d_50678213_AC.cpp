/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc160/submissions/50678213
 * Submitted at: 2024-02-27 17:06:56
 * Problem URL: https://atcoder.jp/contests/abc160/tasks/abc160_d
 * Result: AC
 * Execution Time: 62 ms
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
    
    ll n, x, y; cin >> n >> x >> y; x--; y--;
    // BFS を N 回
    vector<ll> ans(n, 0);
    queue<P> q;
    rep(s,n) {
        vector<ll> dis(n, -1);
        q.push(P(0,s));
        while( !q.empty() ) {
            auto [d, v] = q.front(); q.pop();
            if( dis[v] != -1 ) continue;
            dis[v] = d;
            if( v != 0 ) q.push(P(d+1,v-1));
            if( v != n-1 ) q.push(P(d+1,v+1));
            if( v == x ) q.push(P(d+1,y));
            if( v == y ) q.push(P(d+1,x));
        }
        rep(i,n) ans[dis[i]]++;
    }
    reps(i,1,n) cout << ans[i]/2 << endl;
    
    return 0;
}