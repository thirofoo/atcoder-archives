/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/50238427
 * Submitted at: 2024-02-13 09:10:23
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_c
 * Result: AC
 * Execution Time: 26 ms
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
    
    ll n, d, p; cin >> n >> d >> p;
    vector<ll> f(n, 0);
    rep(i,n) cin >> f[i];
    f.emplace_back(0);
    sort(f.begin(), f.end());
    rep(i,n) f[i+1] += f[i];
    ll have = 0, ans = 1e16;
    for(ll i=0; i<=n+1; i++) {
        ans = min(ans, f[max(n-have,0ll)]+i*p);
        have += d;
    }
    cout << ans << '\n';
    
    return 0;
}