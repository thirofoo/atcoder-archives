/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/28117330
 * Submitted at: 2021-12-25 21:06:25
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_a
 * Result: AC
 * Execution Time: 12 ms
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
    int x,y;
    cin >> x >> y;
    if(y<=x)cout << 0 << endl;
    else if((y-x)%10 == 0)cout << (y-x)/10 << endl;
    else cout << (y-x)/10 + 1 << endl;
    return 0;
}