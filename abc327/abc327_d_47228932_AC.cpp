/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc327/submissions/47228932
 * Submitted at: 2023-11-04 21:14:55
 * Problem URL: https://atcoder.jp/contests/abc327/tasks/abc327_d
 * Result: AC
 * Execution Time: 51 ms
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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m);
    vector<vector<ll>> Graph(n);
    rep(i,m) cin >> a[i];
    rep(i,m) cin >> b[i];
    rep(i,m) {
        a[i]--, b[i]--;
        Graph[a[i]].emplace_back(b[i]);
        Graph[b[i]].emplace_back(a[i]);
    }
    vector<ll> visited(n,-1);
    queue<P> todo;
    rep(i,n) {
        if( visited[i] != -1 ) continue;
        todo.push(P(i,0));
        while( !todo.empty() ) {
            auto [now, c] = todo.front(); todo.pop();
            if( visited[now] != c && visited[now] != -1 ) {
                return cout << "No" << endl, 0;
            }
            if( visited[now] != -1 ) continue;
            visited[now] = c;
            for(auto to:Graph[now]) {
                if( visited[to] != 1-c && visited[to] != -1 ) return cout << "No" << endl, 0;
                if( visited[to] != -1 ) continue;
                todo.push(P(to,1-c));
            }
        }
    }
    cout << "Yes" << endl;

    
    return 0;
}