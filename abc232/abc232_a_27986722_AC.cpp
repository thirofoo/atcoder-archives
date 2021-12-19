/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/27986722
 * Submitted at: 2021-12-19 21:02:13
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_a
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
    string s;
    cin >> s;
    cout << (s[0] - '0') * (s[2] - '0') << endl;
    return 0;
}