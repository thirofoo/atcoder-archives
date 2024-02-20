/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc076/submissions/50460256
 * Submitted at: 2024-02-20 09:02:41
 * Problem URL: https://atcoder.jp/contests/abc076/tasks/abc076_a
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
    
    ll r, g; cin >> r >> g;
    cout << 2 * g - r << endl;
    
    return 0;
}