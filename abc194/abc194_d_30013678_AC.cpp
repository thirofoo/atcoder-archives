/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/30013678
 * Submitted at: 2022-03-12 08:55:21
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_d
 * Result: AC
 * Execution Time: 5 ms
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
    cout << fixed << setprecision(10);
    double n; cin >> n;
    double ans = 0;
    for(double k=1;k<n;k++){
        ans += (1/((n-k)/n));
    }
    cout << ans << endl;
    return 0;
}