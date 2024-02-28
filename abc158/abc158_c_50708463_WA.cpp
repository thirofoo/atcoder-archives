/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc158/submissions/50708463
 * Submitted at: 2024-02-28 23:37:42
 * Problem URL: https://atcoder.jp/contests/abc158/tasks/abc158_c
 * Result: WA
 * Execution Time: 1 ms
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
    
    ld a, b; cin >> a >> b;
    // 0.08x = a, 0.10x = b
    ld av = floor(a*100 / 8.0), bv = floor(b*100 / 10.0);
    ld ans = max(av, bv);
    if( (ll)ans*8/100 == a && (ll)ans*10/100 == b ) cout << (ll)ans << endl;
    else cout << -1 << endl;
    
    return 0;
}