/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc064/submissions/44593273
 * Submitted at: 2023-08-14 22:52:17
 * Problem URL: https://atcoder.jp/contests/agc064/tasks/agc064_b
 * Result: AC
 * Execution Time: 99 ms
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
    
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, char>> e(m);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i += 1) {
        auto &[u, v, c] = e[i];
        cin >> u >> v >> c;
        g[u].push_back(i);
        g[v].push_back(i);
    }
    string s;
    cin >> s;
    s = " " + s;
    dsu d(n + 1);
    vector<int> done(n + 1), ans;
    for (int i = 0; i < m; i += 1) {
        auto [u, v, c] = e[i];
        if (s[u] == c and s[v] == c and not d.same(u, v)) {
            ans.push_back(i);
            done[u] = done[v] = 1;
            d.merge(u, v);
        }
    }
    
    for (int i = 1; i <= n; i += 1) {
        if (done[i]) {
            function<void(int)> dfs = [&](int u) {
                for (int i : g[u]) {
                    auto [eu, ev, c] = e[i];
                    int v = eu ^ ev ^ u;
                    if (not done[v] and s[v] == c) {
                        ans.push_back(i);
                        done[v] = 1;
                        d.merge(u, v);
                        dfs(v);
                    }
                }
            };
            dfs(i);
        }
    }
    for (int i = 0; i < m; i += 1) {
        auto [u, v, c] = e[i];
        if (not d.same(u, v)) {
            ans.push_back(i);
            d.merge(u, v);
        }
    }
    if (ranges::count(done, 1) == n) {
        cout << "Yes\n";
        for (int x : ans) {
            cout << x + 1 << " ";
        }
    } else {
        cout << "No";
    }
    
    return 0;
}