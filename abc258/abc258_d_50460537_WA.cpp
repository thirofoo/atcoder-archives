/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/50460537
 * Submitted at: 2024-02-20 09:27:02
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_d
 * Result: WA
 * Execution Time: 23 ms
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
    
    ll n, x; cin >> n >> x;
    ll ans = 1e16, total = 0;
    rep(i,n) {
        ll a, b; cin >> a >> b;
        total += a+b;
        ans = min(ans, max(0LL, total + b*(x-i-1)));
    }
    cout << ans << endl;
    
    return 0;
}