/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc165/submissions/45692760
 * Submitted at: 2023-09-18 09:33:10
 * Problem URL: https://atcoder.jp/contests/arc165/tasks/arc165_c
 * Result: AC
 * Execution Time: 912 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<vector<P>> Graph(n);
    rep(i,m) {
        ll a, b, w; cin >> a >> b >> w;
        a--; b--;
        Graph[a].emplace_back(P(b,w));
        Graph[b].emplace_back(P(a,w));
    }
    ll min_2edge = 1e16;
    rep(i,n) {
        if( Graph[i].size() <= 1 ) continue;
        sort(Graph[i].begin(), Graph[i].end(), [](P p1, P p2) {
            return p1.second < p2.second;
        });
        min_2edge = min(min_2edge, Graph[i][0].second + Graph[i][1].second);
    }
    
    bool f = true;
    vector<ll> color(n,-1);
    vector<vector<ll>> Graph2(n);

    auto dfs = [&](auto self, ll now, ll pre) {
        if( pre == -1 ) color[now] = 0;
        else color[now] = 1 - color[pre];
        for(auto to:Graph2[now]) {
            if( !f ) return;
            if( color[to] == color[now] ) {
                f = false;
                return;
            }
            if( color[to] != -1 ) continue;
            self(self, to, now);
        }
    };

    ll left = 0, right = min_2edge+1;
    while( right-left > 1 ) {
        ll mid = (right+left)/2;
        f = true;

        color.assign(n,-1);
        Graph2.assign(n,{});
        rep(i,n) {
            for(auto &&[j,w]:Graph[i]) {
                if( w < mid ) {
                    Graph2[i].emplace_back(j);
                    Graph2[j].emplace_back(i);
                }
            };
        }
        rep(i,n) if(f && color[i] == -1) dfs(dfs, i, -1);

        if( f ) left = mid;
        else right = mid;
    }
    cout << left << endl;
    
    return 0;
}

