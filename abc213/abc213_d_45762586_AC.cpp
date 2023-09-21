/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/45762586
 * Submitted at: 2023-09-21 09:58:22
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_d
 * Result: AC
 * Execution Time: 97 ms
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
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    rep(i,n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }
    rep(i,n) sort(Graph[i].begin(), Graph[i].end());
    auto dfs = [&](auto self, ll now, ll pre) -> void {
        cout << now+1 << " ";
        for(auto to:Graph[now]) {
            if( to == pre ) continue;
            self(self, to, now);
            cout << now+1 << " ";
        }
    };
    dfs(dfs, 0, -1);
    cout << endl;
    
    return 0;
}