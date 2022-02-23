/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc202/submissions/29607109
 * Submitted at: 2022-02-23 21:17:13
 * Problem URL: https://atcoder.jp/contests/abc202/tasks/abc202_a
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int a,b,c; cin >> a >> b >> c;
    cout << 21-a-b-c << endl;
    return 0;
}