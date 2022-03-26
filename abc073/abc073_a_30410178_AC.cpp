/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc073/submissions/30410178
 * Submitted at: 2022-03-26 11:39:11
 * Problem URL: https://atcoder.jp/contests/abc073/tasks/abc073_a
 * Result: AC
 * Execution Time: 6 ms
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
    string s; cin >> s;
    if(s[0]-'0' == 9 || s[1]-'0' == 9)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}