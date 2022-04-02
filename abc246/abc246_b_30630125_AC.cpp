/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/30630125
 * Submitted at: 2022-04-02 21:05:56
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_b
 * Result: AC
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
    double a,b; cin >> a >> b;
    double v = sqrt(a*a+b*b);
    cout << a/v << " " << b/v << endl;

    return 0;
}