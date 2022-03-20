/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/30269471
 * Submitted at: 2022-03-20 21:01:30
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_a
 * Result: AC
 * Execution Time: 4 ms
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
    int n; string s; cin >> n >> s;
    cout << s[n-1] << endl;
    return 0;
}