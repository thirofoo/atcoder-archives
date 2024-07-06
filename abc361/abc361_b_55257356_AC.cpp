/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55257356
 * Submitted at: 2024-07-06 21:04:16
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_b
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
    
    ll a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    if( (a <= g && g < d) || (g <= a && a < j) ) {
        if( (b <= h && h < e) || (h <= b && b < k) ) {
            if( (c <= i && i < f) || (i <= c && c < l) ) {
                cout << "Yes" << '\n';
                return 0;
            }
            else cout << "No" << '\n';
        }
        else cout << "No" << '\n';
    }
    else cout << "No" << '\n';
    
    return 0;
}