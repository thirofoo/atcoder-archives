/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/29607010
 * Submitted at: 2022-02-23 21:13:26
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_a
 * Result: AC
 * Execution Time: 7 ms
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
    int a,b; cin >> a >> b;
    if(a+b >= 15 && b >= 8)cout << 1 << endl;
    else if(a+b >= 10 && b >= 3)cout << 2 << endl;
    else if(a+b >= 3)cout << 3 << endl;
    else cout << 4 << endl;
    return 0;
}