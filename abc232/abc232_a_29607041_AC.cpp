/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/29607041
 * Submitted at: 2022-02-23 21:14:22
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_a
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string s;cin >> s;
    cout << (s[0]-'0')*(s[2]-'0') << endl;
    return 0;
}