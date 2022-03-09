/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc197/submissions/29973358
 * Submitted at: 2022-03-09 21:39:53
 * Problem URL: https://atcoder.jp/contests/abc197/tasks/abc197_d
 * Result: AC
 * Execution Time: 8 ms
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
    double n,x0,y0,x1,y1; cin >> n >> x0 >> y0 >> x1 >> y1;
    double r = sqrt(pow(x0-x1,2)+pow(y0-y1,2))/2;
    cout << r*cos(2*M_PI/n + atan((y0-y1)/(x0-x1)) + (x0 < x1 ? M_PI : 0))+(x0+x1)/2 << " " << r*sin(2*M_PI/n + atan((y0-y1)/(x0-x1)) + (x0 < x1 ? M_PI : 0))+(y0+y1)/2 << endl;
    return 0;
}