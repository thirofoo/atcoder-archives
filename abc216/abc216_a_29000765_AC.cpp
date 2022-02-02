/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc216/submissions/29000765
 * Submitted at: 2022-02-02 11:51:36
 * Problem URL: https://atcoder.jp/contests/abc216/tasks/abc216_a
 * Result: AC
 * Execution Time: 8 ms
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
    double x; cin >> x;
    int y = (x - (int)x)*10;
    x = (int)x;
    if(y <= 2)cout << x << "-" << endl;
    else if(y <= 6)cout << x << endl;
    else cout << x << "+" << endl;
    return 0;
}