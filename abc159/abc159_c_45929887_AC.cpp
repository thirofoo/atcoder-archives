/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc159/submissions/45929887
 * Submitted at: 2023-09-25 09:17:21
 * Problem URL: https://atcoder.jp/contests/abc159/tasks/abc159_c
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
    cout << setprecision(10) << fixed;
    
    double l; cin >> l;
    cout << (l/3) * (l/3) * (l/3) << endl;
    
    return 0;
}