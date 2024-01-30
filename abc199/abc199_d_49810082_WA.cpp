/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/49810082
 * Submitted at: 2024-01-30 17:59:28
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: WA
 * Execution Time: 2212 ms
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
    vector<vector<ll>> Graph(n);
    dsu uf(n);
    rep(i,m) {
        ll a, b; cin >> a >> b; a--, b--;
        uf.merge(a, b);
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }
    vector group = uf.groups();
    vector<ll> color(n,-1);
    ll ans = 1, cand;
    set<vector<ll>> st;
    
    auto f = [&](auto self, ll now) -> void {
        ll cnt = 0;
        for(auto to:Graph[now]) {
            if( color[to] != -1 ) continue;
            rep(j,3) {
                if( j == color[now] ) continue;
                color[to] = j;
                self(self,to);
                color[to] = -1;
            }
            cnt++;
        }
        if( cnt == 0 ) {
            bool f = true;
            rep(i,Graph.size()) {
                for(auto ele:Graph[i]) {
                    f &= (color[i] != color[ele]);
                }
            }
            if( f ) st.insert(color);
        }
        return;
    };
    for(auto g:group) {
        cand = 0;
        st.clear();
        rep(i,3) {
            color[g[0]] = i;
            f(f, g[0]);
            color[g[0]] = -1;
        }
        ans *= st.size();
    }
    cout << ans << endl;
    
    return 0;
}