/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc221/submissions/29607082
 * Submitted at: 2022-02-23 21:16:06
 * Problem URL: https://atcoder.jp/contests/abc221/tasks/abc221_a
 * Result: WA
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
    cout << pow(32,a-b) << endl;
    return 0;
}