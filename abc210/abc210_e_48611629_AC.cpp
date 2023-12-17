/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/48611629
 * Submitted at: 2023-12-17 16:40:56
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_e
 * Result: AC
 * Execution Time: 20 ms
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
    vector<P> edge;
    rep(i,m) {
        ll a, c; cin >> a >> c;
        edge.emplace_back(P(c,a));
    }
    sort(edge.begin(), edge.end());
    ll ans = 0;
    rep(i,m) {
        auto [c,a] = edge[i];
        ans += (n-gcd(n,a)) * c;
        n = gcd(n,a);
        if( n == 1 ) break;
    }
    cout << ( n == 1 ? ans : -1 ) << endl;
    
    return 0;
}