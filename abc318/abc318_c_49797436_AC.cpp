/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc318/submissions/49797436
 * Submitted at: 2024-01-30 02:22:10
 * Problem URL: https://atcoder.jp/contests/abc318/tasks/abc318_c
 * Result: AC
 * Execution Time: 26 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, d, p; cin >> n >> d >> p;
    vector<ll> f(n);
    rep(i,n) cin >> f[i];
    f.emplace_back(0);
    sort(f.begin(), f.end());
    rep(i,n) f[i+1] += f[i];
    ll ans = 1e16;
    rep(i,n+1) ans = min(ans, f[max(n-i*d,0LL)] + p*i);
    cout << ans << endl;

    return 0;
}