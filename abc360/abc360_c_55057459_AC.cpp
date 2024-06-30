/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55057459
 * Submitted at: 2024-06-30 21:11:56
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_c
 * Result: AC
 * Execution Time: 22 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n), w(n);
    vector<vector<ll>> g(n+1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> w[i];
    rep(i, n) g[a[i]].emplace_back(w[i]);
    ll ans = 0;
    rep(i, n) {
        sort(g[i+1].begin(), g[i+1].end());
        reverse(g[i+1].begin(), g[i+1].end());
        while(g[i+1].size() > 1) {
            ans += g[i+1].back();
            g[i+1].pop_back();
        }
    }
    cout << ans << '\n';
    
    return 0;
}