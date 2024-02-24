/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc095/submissions/50551094
 * Submitted at: 2024-02-24 15:44:46
 * Problem URL: https://atcoder.jp/contests/abc095/tasks/arc096_b
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

ll n, c;
vector<ll> x, v;

ll solve() {
    vector<ll> r_max(n+1,-1e16), r_sum(n+1,0);
    ll v_total = 0;
    r_max[n] = 0;
    for(ll i=n-1; i>=0; i--) {
        v_total += v[i];
        r_max[i] = max(r_max[i+1], v_total-(c-x[i]));
    }
    rep(i, n) r_sum[i+1] = r_sum[i] + v[i];
    // Start から i 番目まで行って折り返す時の最大値
    ll ans = 0;
    rep(i,n) ans = max(ans, r_sum[i] - (i == 0 ? 0 : x[i-1])*2 + r_max[i]);
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> c;
    x.resize(n);
    v.resize(n);
    rep(i, n) cin >> x[i] >> v[i];
    ll ans = solve();
    cerr << ans << endl;
    reverse(x.begin(), x.end());
    rep(i,n) x[i] = c - x[i]; // 距離反転
    reverse(v.begin(), v.end());
    ans = max(ans, solve());
    cout << ans << endl;
    
    return 0;
}