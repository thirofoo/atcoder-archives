/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/30743419
 * Submitted at: 2022-04-06 00:02:25
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_a
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
    int m,h; cin >> m >> h;
    if(h%m == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}