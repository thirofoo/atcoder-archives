/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc130/submissions/29607065
 * Submitted at: 2022-02-23 21:15:19
 * Problem URL: https://atcoder.jp/contests/abc130/tasks/abc130_a
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
    int x,a; cin >> x >> a;
    if(x < a)cout << 0 << endl;
    else cout << 10 << endl;
    return 0;
}