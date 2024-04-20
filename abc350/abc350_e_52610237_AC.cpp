/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/52610237
 * Submitted at: 2024-04-20 22:27:42
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_e
 * Result: AC
 * Execution Time: 5 ms
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
    cout << setprecision(10) << fixed;
    
    ll n, a, x, y; cin >> n >> a >> x >> y;
    map<ll, long double> mp;
    mp[0] = 0.0;
    auto dfs = [&](auto self, ll now) -> long double {
        if( mp.count(now) ) return mp[now];
        long double cand1 = 0.0, cand2 = 0.0;
        reps(i,2,7) cand1 += self(self, now/i);
        cand1 /= 5.0, cand1 += y * 6.0 / 5.0;

        cand2 = self(self, now/a) + x;
        mp[now] = min(cand1, cand2);
        return mp[now];
    };
    cout << dfs(dfs, n) << '\n';
    
    return 0;
}