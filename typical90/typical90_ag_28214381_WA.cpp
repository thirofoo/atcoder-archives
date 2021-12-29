/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28214381
 * Submitted at: 2021-12-29 11:54:46
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ag
 * Result: WA
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
    int h,w;
    cin >> h >> w;
    cout << ((h-1)/2+1)*((w-1)/2+1) << endl;
    return 0;
}