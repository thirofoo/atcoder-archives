/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc221/submissions/29000610
 * Submitted at: 2022-02-02 11:35:48
 * Problem URL: https://atcoder.jp/contests/abc221/tasks/abc221_a
 * Result: AC
 * Execution Time: 14 ms
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
    int a,b; cin >> a >> b;
    cout << (ll)pow(32,abs(a-b)) << endl;
    return 0;
}