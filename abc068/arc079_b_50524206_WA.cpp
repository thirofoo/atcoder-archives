/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc068/submissions/50524206
 * Submitted at: 2024-02-23 09:50:16
 * Problem URL: https://atcoder.jp/contests/abc068/tasks/arc079_b
 * Result: WA
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // ネタ問 (前やったことあり)
    ll k; cin >> k;
    ll n = 50;
    vector<ll> ans(n);
    rep(i, n) ans[i] = (i < k%n ? 1 : -1)*(k%n) + 49 + k/n;
    cout << n << endl;
    rep(i, n) cout << ans[i] << (i == n-1 ? "\n" : " ");
    
    return 0;
}