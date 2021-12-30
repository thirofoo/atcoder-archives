/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc173/submissions/28244958
 * Submitted at: 2021-12-31 01:42:46
 * Problem URL: https://atcoder.jp/contests/abc173/tasks/abc173_a
 * Result: AC
 * Execution Time: 4 ms
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
    int n; cin >> n;
    if(n%1000 == 0)cout << 0 << endl;
    else cout << 1000 - n%1000 << endl;
    return 0;
}