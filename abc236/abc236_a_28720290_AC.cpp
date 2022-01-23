/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc236/submissions/28720290
 * Submitted at: 2022-01-23 21:01:54
 * Problem URL: https://atcoder.jp/contests/abc236/tasks/abc236_a
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
    string s; int a,b; cin >> s >> a >> b;
    char tmp = s[a-1];
    s[a-1] = s[b-1];
    s[b-1] = tmp;
    cout << s << endl;
    return 0;
}