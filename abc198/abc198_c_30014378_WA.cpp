/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc198/submissions/30014378
 * Submitted at: 2022-03-12 10:19:46
 * Problem URL: https://atcoder.jp/contests/abc198/tasks/abc198_c
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cout << fixed << setprecision(10);
    double r,x,y; cin >> r >> x >> y;
    double d = sqrt(x*x+y*y);
    cout << ceil(d/r) << endl;
    return 0;
}