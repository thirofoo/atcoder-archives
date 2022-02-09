/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc211/submissions/29174633
 * Submitted at: 2022-02-09 11:43:59
 * Problem URL: https://atcoder.jp/contests/abc211/tasks/abc211_a
 * Result: AC
 * Execution Time: 4 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cout << setprecision(9);
    double a,b; cin >> a >> b;
    cout << (a-b)/3 + b << endl;
    return 0;
}