/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54501436
 * Submitted at: 2024-06-13 18:48:04
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_j
 * Result: AC
 * Execution Time: 277 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    vector<P> time;
    rep(i, n) {
        cin >> a[i] >> b[i];
        time.emplace_back(P(a[i], INF));
        time.emplace_back(P(b[i], -INF));
    }
    ll q; cin >> q;
    rep(i, q) {
        ll t; cin >> t;
        time.emplace_back(P(t, i));
    }
    sort(time.begin(), time.end(), [](P x, P y) {
        auto &[t1, v1] = x;
        auto &[t2, v2] = y;
        if(t1 != t2) return t1 < t2;
        return v1 > v2;
    });

    ll cnt = 0;
    vector<ll> ans(q);
    rep(i, time.size()) {
        auto [t, v] = time[i];
        if(v == INF) cnt++;
        else if(v == -INF) cnt--;
        else ans[v] = cnt;
    }
    rep(i, q) cout << ans[i] << endl;
    
    return 0;
}