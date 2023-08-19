/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/44728744
 * Submitted at: 2023-08-19 21:24:29
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_e
 * Result: AC
 * Execution Time: 59 ms
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
    rep(i,n) {
        ll c; cin >> c;
        rep(j,c) {
            ll p; cin >> p;
            p--;
            Graph[i].push_back(p);
        }
    }
    vector<bool> visited(n,false);
    queue<ll> ans;
    auto dfs = [&](auto self, ll now) -> void {
        visited[now] = true;
        for(auto to:Graph[now]) {
            if( visited[to] ) continue;
            self(self,to);
        }
        ans.push(now);
    };
    dfs(dfs,0);
    while( !ans.empty() ) {
        ll ele = ans.front(); ans.pop();
        if( ele == 0 ) continue;
        cout << ele+1 << " ";
    }
    cout << endl;
    
    return 0;
}