/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc320/submissions/45621772
 * Submitted at: 2023-09-16 21:47:12
 * Problem URL: https://atcoder.jp/contests/abc320/tasks/abc320_d
 * Result: WA
 * Execution Time: 311 ms
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
    vector<vector<T>> Graph(n);
    vector<ll> x(n,1e9), y(n,1e9);
    rep(i,m) {
        ll a, b, tx, ty; cin >> a >> b >> tx >> ty;
        a--; b--;
        Graph[a].emplace_back(T(b,tx,ty));
        Graph[b].emplace_back(T(a,-tx,-ty));
    }
    auto dfs = [&](auto self, ll now, ll now_x, ll now_y) -> void {
        if( x[now] != 1e9 ) return;
        x[now] = now_x;
        y[now] = now_y;
        for(auto [to, dx, dy]:Graph[now]) {
            if( x[to] != 1e9 ) continue;
            self(self, to, now_x+dx , now_y+dy);
        }
    };
    dfs(dfs, 0, 0, 0);
    bool f = true;
    rep(i,n) f &= (x[i] != 1e9);

    rep(i,n) {
        if( x[i] == 1e9 ) cout << "undecidable" << endl;
        else cout << x[i] << " " << y[i] << endl;
    }
    
    return 0;
}