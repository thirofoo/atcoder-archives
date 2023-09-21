/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/45762080
 * Submitted at: 2023-09-21 09:18:56
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_b
 * Result: AC
 * Execution Time: 12 ms
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
    vector<set<ll>> Graph(n);
    rep(i,m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].insert(v);
        Graph[v].insert(u);
    }
    ll ans = 0;
    rep(i,n) {
        for(ll j=i+1;j<n;j++) {
            for(ll k=j+1;k<n;k++) {
                if( Graph[i].count(j) && Graph[i].count(k) && Graph[j].count(k) ) ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}