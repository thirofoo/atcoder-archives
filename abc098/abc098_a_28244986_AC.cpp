/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc098/submissions/28244986
 * Submitted at: 2021-12-31 01:43:58
 * Problem URL: https://atcoder.jp/contests/abc098/tasks/abc098_a
 * Result: AC
 * Execution Time: 5 ms
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
    int a,b; cin >> a >> b;
    cout << max(max(a+b,a-b),a*b) << endl;
    return 0;
}