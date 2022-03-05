/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/29867511
 * Submitted at: 2022-03-05 21:05:04
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_b
 * Result: AC
 * Execution Time: 19 ms
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
    sort(s.begin(),s.end());
    cout << s << endl;
    return 0;
}