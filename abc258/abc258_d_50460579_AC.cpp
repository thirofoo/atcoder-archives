/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/50460579
 * Submitted at: 2024-02-20 09:32:19
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_d
 * Result: AC
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
    ll ans = 2e18, total = 0, mini_b = 1e18;
    rep(i,n) {
        ll a, b; cin >> a >> b;
        total += a+b;
        mini_b = min(mini_b, b);
        if( x-i-1 < 0 ) continue;
        ans = min(ans, max(0LL, total + mini_b*(x-i-1)));
    }
    cout << ans << endl;
    
    return 0;
}