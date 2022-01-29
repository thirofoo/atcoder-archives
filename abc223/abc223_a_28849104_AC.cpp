/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/28849104
 * Submitted at: 2022-01-29 10:54:06
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_a
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
    int x; cin >> x;
    if(x == 0)cout << "No" << endl;
    else if(x%100 == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}