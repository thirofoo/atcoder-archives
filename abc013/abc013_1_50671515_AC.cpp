/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc013/submissions/50671515
 * Submitted at: 2024-02-27 10:13:36
 * Problem URL: https://atcoder.jp/contests/abc013/tasks/abc013_1
 * Result: AC
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
    
    char x; cin >> x;
    cout << x - 'A' + 1 << endl;
    
    return 0;
}