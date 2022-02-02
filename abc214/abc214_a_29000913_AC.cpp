/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/29000913
 * Submitted at: 2022-02-02 12:05:00
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_a
 * Result: AC
 * Execution Time: 8 ms
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
    int n; cin >> n;
    if(n <= 125)cout << 4 << endl;
    else if(n <= 211)cout << 6 << endl;
    else cout << 8 << endl;
    return 0;
}