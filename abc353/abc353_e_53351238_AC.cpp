/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53351238
 * Submitted at: 2024-05-11 21:36:39
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_e
 * Result: AC
 * Execution Time: 74 ms
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
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    ll ans = 0;
    auto dfs = [&](auto self, ll idx, vector<ll> &group) -> void {
        vector<vector<ll>> next(26, vector<ll>{});
        for(ll i : group) {
            if( s[i].size() == idx ) continue;
            next[s[i][idx]-'a'].emplace_back(i);
        }
        rep(i, 26) ans += next[i].size() * (next[i].size()-1) / 2;
        rep(i, 26) if( next[i].size() > 1 ) self(self, idx+1, next[i]);
        return;
    };
    vector<ll> g;
    rep(i, n) g.emplace_back(i);
    dfs(dfs, 0, g);
    cout << ans << endl;
    
    return 0;
}