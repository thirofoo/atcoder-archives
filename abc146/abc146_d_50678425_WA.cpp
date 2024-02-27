/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc146/submissions/50678425
 * Submitted at: 2024-02-27 17:16:20
 * Problem URL: https://atcoder.jp/contests/abc146/tasks/abc146_d
 * Result: WA
 * Execution Time: 122 ms
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
    
    ll n; cin >> n;
    vector<vector<P>> Graph(n);
    rep(i,n-1) {
        ll a, b; cin >> a >> b; a--; b--;
        Graph[a].emplace_back(b, i);
        Graph[b].emplace_back(a, i);
    }
    vector<ll> ans(n-1, -1);
    auto dfs = [&](auto self, ll now, ll pre, ll now_color) -> void {
        ll color = 0;
        for(auto [to, idx] : Graph[now]) {
            if( to == pre ) continue;
            if( color == now_color ) color++;
            ans[idx] = color;
            self(self, to, now, color);
            color++;
        }
        return;
    };
    dfs(dfs, 0, -1, -1);
    cout << max_element(ans.begin(), ans.end()) - ans.begin() + 1 << endl;
    rep(i,n-1) cout << ans[i]+1 << endl;
    
    return 0;
}