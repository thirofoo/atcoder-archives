/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/29865808
 * Submitted at: 2022-03-05 21:04:01
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_a
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
    double a,b,c,x; cin >> a >> b >> c >> x;
    cout << setprecision(10);
    if(x <= a)cout << (double)1 << endl;
    else if(x > b)cout << (double)0 << endl;
    else cout << c/(b-(a+1)+1) << endl;
    return 0;
}