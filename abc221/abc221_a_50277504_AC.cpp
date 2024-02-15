/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc221/submissions/50277504
 * Submitted at: 2024-02-15 10:03:05
 * Problem URL: https://atcoder.jp/contests/abc221/tasks/abc221_a
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b; cin >> a >> b;
    a -= b;
    ll ans = 1;
    while(a--) ans *= 32;
    cout << ans << endl;
    
    return 0;
}