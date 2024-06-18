/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/54690214
 * Submitted at: 2024-06-18 18:16:22
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_b
 * Result: AC
 * Execution Time: 4 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10);
    
    ld a, b, d; cin >> a >> b >> d;
    d = 2 * M_PI * d / 360.0;
    d += atan2(b, a);
    ld dis = sqrt(a*a + b*b);
    cout << dis * cos(d) << " " << dis * sin(d) << endl;
    
    return 0;
}