/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/28631073
 * Submitted at: 2022-01-19 16:37:17
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_a
 * Result: AC
 * Execution Time: 5 ms
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
    int a,p; cin >> a >> p;
    cout << (3*a+p)/2 << endl;
    return 0;
}