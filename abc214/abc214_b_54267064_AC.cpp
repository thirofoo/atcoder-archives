/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/54267064
 * Submitted at: 2024-06-06 14:02:11
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_b
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll s, t; cin >> s >> t;
    ll ans = 0;
    rep(a,101) rep(b,101) rep(c,101) {
        if(a+b+c <= s && a*b*c <= t) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}