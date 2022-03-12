/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc198/submissions/30014504
 * Submitted at: 2022-03-12 10:32:50
 * Problem URL: https://atcoder.jp/contests/abc198/tasks/abc198_c
 * Result: AC
 * Execution Time: 3 ms
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
    long double r,x,y; cin >> r >> x >> y;
    long double d = sqrt(x*x+y*y);
    cout << (d/r < 1 ? 2 : (int)ceil(d/r)) << endl;
    return 0;
}