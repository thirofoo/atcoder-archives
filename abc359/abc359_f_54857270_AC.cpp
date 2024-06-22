/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54857270
 * Submitted at: 2024-06-23 01:03:02
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_f
 * Result: AC
 * Execution Time: 52 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // Segment Tree でなくても priority_queue で管理出来る。天才。
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    vector<ll> deg(n, 0);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(a[0], 0));

    reps(i, 1, n) {
        auto [val, idx] = pq.top(); pq.pop();
        ans += val + a[i];
        deg[idx]++, deg[i]++;
        ll ndeg = deg[idx] + 1;
        pq.push(P( (ndeg*ndeg - deg[idx]*deg[idx]) * a[idx], idx ));
        ndeg = deg[i] + 1;
        pq.push(P( (ndeg*ndeg - deg[i]*deg[i]) * a[i], i ));
    }
    cout << ans << '\n';
    
    return 0;
}