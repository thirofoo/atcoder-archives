/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc193/submissions/29606845
 * Submitted at: 2022-02-23 21:06:50
 * Problem URL: https://atcoder.jp/contests/abc193/tasks/abc193_a
 * Result: AC
 * Execution Time: 9 ms
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
    cout << fixed << setprecision(15);
    double a,b; cin >> a >> b;
    cout << (1-b/a)*100 << endl;
    return 0;
}