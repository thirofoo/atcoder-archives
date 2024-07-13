/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55517009
 * Submitted at: 2024-07-13 21:04:54
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll r, g, b;
    string c;
    cin >> r >> g >> b >> c;
    if(c == "Red")
        cout << min(g, b) << endl;
    else if(c == "Green")
        cout << min(r, b) << endl;
    else
        cout << min(r, g) << endl;

    return 0;
}