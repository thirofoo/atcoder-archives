/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc356/submissions/54077037
 * Submitted at: 2024-06-01 21:02:27
 * Problem URL: https://atcoder.jp/contests/abc356/tasks/abc356_b
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
    vector<ll> a(m), x(m);
    rep(i, m) cin >> a[i];
    rep(i,n) {
        rep(j, m) {
            ll tx; cin >> tx;
            x[j] += tx;
        }
    }
    bool f = true;
    rep(i,m) f &= (x[i] >= a[i]);
    cout << (f ? "Yes" : "No") << '\n';
    
    return 0;
}