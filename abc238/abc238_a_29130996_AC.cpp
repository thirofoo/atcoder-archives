/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc238/submissions/29130996
 * Submitted at: 2022-02-06 22:06:47
 * Problem URL: https://atcoder.jp/contests/abc238/tasks/abc238_a
 * Result: AC
 * Execution Time: 7 ms
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
    int n; cin >> n;
    if(n == 1 || n >= 5)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}