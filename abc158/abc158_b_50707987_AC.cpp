/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc158/submissions/50707987
 * Submitted at: 2024-02-28 23:18:08
 * Problem URL: https://atcoder.jp/contests/abc158/tasks/abc158_b
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    
    ll n, a, b; cin >> n >> a >> b;
    ll ans = n / (a + b) * a;
    ans += min(n % (a + b), a);
    cout << ans << endl;
    
    return 0;
}