/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc150/submissions/28236236
 * Submitted at: 2021-12-30 18:22:12
 * Problem URL: https://atcoder.jp/contests/abc150/tasks/abc150_a
 * Result: AC
 * Execution Time: 6 ms
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
    int k,x;
    cin >> k >> x;
    if(500*k >= x)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}