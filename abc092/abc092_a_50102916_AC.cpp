/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc092/submissions/50102916
 * Submitted at: 2024-02-08 23:39:23
 * Problem URL: https://atcoder.jp/contests/abc092/tasks/abc092_a
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
#define rep(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, c, d; cin >> a >> b >> c >> d;
    cout << min(a,b) + min(c,d) << endl;
    
    return 0;
}