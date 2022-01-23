/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc172/submissions/28715482
 * Submitted at: 2022-01-23 19:20:37
 * Problem URL: https://atcoder.jp/contests/abc172/tasks/abc172_a
 * Result: AC
 * Execution Time: 9 ms
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
    int a; cin >> a;
    cout << a + pow(a,2) + pow(a,3) << endl;
    return 0;
}