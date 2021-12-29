/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28214455
 * Submitted at: 2021-12-29 12:06:21
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ag
 * Result: AC
 * Execution Time: 7 ms
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
    if(h == 1 || w == 1)cout << h*w << endl;
    else cout << (h+1)/2*((w+1)/2) << endl;
    return 0;
}