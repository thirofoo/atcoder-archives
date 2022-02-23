/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc098/submissions/29606678
 * Submitted at: 2022-02-23 21:00:39
 * Problem URL: https://atcoder.jp/contests/abc098/tasks/abc098_a
 * Result: AC
 * Execution Time: 7 ms
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
    cout << max(a+b,max(a-b,a*b)) << endl;
    return 0;
}