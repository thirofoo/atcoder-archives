/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/50333412
 * Submitted at: 2024-02-17 21:02:24
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_b
 * Result: AC
 * Execution Time: 34 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n), s(n-1), t(n-1);
    rep(i, n) cin >> a[i];
    rep(i, n-1) {
        cin >> s[i] >> t[i];
        a[i+1] += (a[i]/s[i])*t[i];
    }
    cout << a[n-1] << '\n';
    
    return 0;
}