/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc100/submissions/53548918
 * Submitted at: 2024-05-17 18:12:27
 * Problem URL: https://atcoder.jp/contests/abc100/tasks/abc100_d
 * Result: AC
 * Execution Time: 2 ms
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
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> v(n,vector<ll>(3));
    rep(i, n) rep(j, 3) cin >> v[i][j];

    ll ans = -1;
    rep(i, 1LL << 3) {
        vector<ll> max_v;
        rep(j,n) {
            ll tmp = 0;
            rep(k, 3) {
                if(i & (1LL << k)) tmp += v[j][k];
                else tmp -= v[j][k];
            }
            max_v.emplace_back(tmp);
        }
        ll cand = 0;
        sort(max_v.begin(), max_v.end(), greater<>());
        rep(j, m) cand += max_v[j];
        ans = max(ans, cand);
    }
    cout << ans << endl;
    
    return 0;
}