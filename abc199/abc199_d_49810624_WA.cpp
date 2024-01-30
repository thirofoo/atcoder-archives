/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/49810624
 * Submitted at: 2024-01-30 18:22:25
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: WA
 * Execution Time: 2210 ms
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
    vector<ll> rui(n+1,1);
    rep(i,n) rui[i+1] = 4*rui[i];
    // color: 4 進数の各桁が 0: 未設定, 1,2,3: RGB
    ll ans = 1, cand, g_idx, color = 0;
    set<ll> st;
    
    auto f = [&](auto self, ll now) -> void {
        ll cnt = 0;
        for(auto to:Graph[now]) {
            if( (color/rui[to])%4 != 0 ) continue;
            for(ll j=1; j<=3; j++) {
                if( j == (color/rui[now])%4 ) continue;
                color += rui[to] * j;
                self(self,to);
                color -= rui[to] * j;
            }
            cnt++;
        }
        if( cnt == 0 ) {
            bool f = true;
            auto && g = group[g_idx];
            rep(i,g.size()) {
                for(auto ele:Graph[g[i]]) {
                    f &= ((color/rui[g[i]])%4 != (color/rui[ele])%4);
                }
            }
            if( f ) st.insert(color);
        }
        return;
    };
    rep(i,group.size()) {
        cand = 0;
        g_idx = i;
        st.clear();
        for(ll j=1; j<=3; j++) {
            color += rui[group[i][0]] * j;
            f(f, group[i][0]);
            color -= rui[group[i][0]] * j;
        }
        ans *= st.size();
    }
    cout << ans << endl;
    
    return 0;
}