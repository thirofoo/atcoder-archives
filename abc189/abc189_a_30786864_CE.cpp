/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/30786864
 * Submitted at: 2022-04-08 16:06:11
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_a
 * Result: CE
 * Execution Time: None ms
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
    if(s[0] == s[1] && s[1] == s[2])cout << "Won" << endl;
    else cout << "Lost" << endl;
    return 0;
}