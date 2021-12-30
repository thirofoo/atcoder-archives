/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc121/submissions/28244000
 * Submitted at: 2021-12-31 01:07:26
 * Problem URL: https://atcoder.jp/contests/abc121/tasks/abc121_a
 * Result: AC
 * Execution Time: 8 ms
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
    int H,W,h,w;cin >> H >> W >> h >> w;
    cout << (H-h)*(W-w) << endl;
    return 0;
}