/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc334/submissions/48741002
 * Submitted at: 2023-12-23 21:06:07
 * Problem URL: https://atcoder.jp/contests/abc334/tasks/abc334_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, m, l, r; cin >> a >> m >> l >> r;
    l-= a, r -= a;
    r -= (r%m+m)%m;
    l += (m-(l%m+m)%m)%m;
    cout << r/m-l/m+1 << endl;
    
    return 0;
}