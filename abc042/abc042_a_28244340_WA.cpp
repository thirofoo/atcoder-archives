/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc042/submissions/28244340
 * Submitted at: 2021-12-31 01:18:53
 * Problem URL: https://atcoder.jp/contests/abc042/tasks/abc042_a
 * Result: WA
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
    int a,b,c; cin >> a >> b >> c;
    if(a == 5 && b == 5 && c == 7)return cout << "Yes" << endl,0;
    if(a == 5 && b == 7 && c == 5)return cout << "Yes" << endl,0;
    if(a == 7 && b == 5 && c == 5)return cout << "Yes" << endl,0;
    cout << "No" << endl;
    return 0;
}