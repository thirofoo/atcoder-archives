/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc072/submissions/29607187
 * Submitted at: 2022-02-23 21:20:23
 * Problem URL: https://atcoder.jp/contests/abc072/tasks/abc072_a
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int x,t; cin >> x >> t;
    if(x <= t)cout << 0 << endl;
    else cout << x-t << endl;
    return 0;
}