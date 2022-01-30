/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28901796
 * Submitted at: 2022-01-30 21:03:13
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_a
 * Result: AC
 * Execution Time: 12 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n; cin >> n;
    if(-(1LL << 31) <= n && n < (1LL << 31))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}