/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc209/submissions/29200530
 * Submitted at: 2022-02-10 21:27:09
 * Problem URL: https://atcoder.jp/contests/abc209/tasks/abc209_a
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
    int a,b; cin >> a >> b;
    if(a > b)cout << 0 << endl;
    else cout << b- a + 1 << endl;
    return 0;
}