/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/30786872
 * Submitted at: 2022-04-08 16:06:36
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_a
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string c; cin >> c;
    if(c[0] == c[1] && c[1] == c[2])cout << "Won" << endl;
    else cout << "Lost" << endl;
    return 0;
}