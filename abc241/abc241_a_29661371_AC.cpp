/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/29661371
 * Submitted at: 2022-02-26 21:01:47
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_a
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
    vector<int> a(10);
    rep(i,10)cin >> a[i];
    cout << a[a[a[0]]] << endl;

    return 0;
}