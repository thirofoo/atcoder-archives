/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc078/submissions/53516193
 * Submitted at: 2024-05-16 13:47:19
 * Problem URL: https://atcoder.jp/contests/abc078/tasks/arc085_b
 * Result: AC
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, z, w; cin >> n >> z >> w;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> memo(n+1, vector<ll>(2, -1));
    auto f = [&](auto self, ll idx, ll player, ll x, ll y) -> ll {
        if(idx == n) return memo[idx][player] = abs(x-y);
        if(memo[idx][player] != -1) return memo[idx][player];
        if(player == 0) {
            ll max_v = -INF;
            reps(i, idx, n) max_v = max(max_v, self(self, i+1, 1, a[i], y));
            return memo[idx][player] = max_v;
        }
        else {
            ll min_v = INF;
            reps(i, idx, n) min_v = min(min_v, self(self, i+1, 0, x, a[i]));
            return memo[idx][player] = min_v;
        }
    };
    cout << f(f, 0, 0, z, w) << endl;
    
    return 0;
}