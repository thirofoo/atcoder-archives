/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc225/submissions/28802842
 * Submitted at: 2022-01-26 11:06:30
 * Problem URL: https://atcoder.jp/contests/abc225/tasks/abc225_a
 * Result: AC
 * Execution Time: 5 ms
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
    string s; cin >> s;
    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[0])cout << 1 << endl;
    else if(s[0] != s[1] && s[1] != s[2] && s[2] != s[0])cout << 6 << endl;
    else cout << 3 << endl;
    return 0;
}