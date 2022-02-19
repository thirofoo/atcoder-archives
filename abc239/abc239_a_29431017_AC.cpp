/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/29431017
 * Submitted at: 2022-02-19 21:04:03
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_a
 * Result: AC
 * Execution Time: 8 ms
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
    cout << setprecision(20) << endl;
    ll h; cin >> h;
    ll a = h*(12800000+h);
    cout << (double)sqrt(a) << endl;
    return 0;
}