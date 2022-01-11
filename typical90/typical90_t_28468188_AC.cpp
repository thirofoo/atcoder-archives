/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28468188
 * Submitted at: 2022-01-11 23:13:39
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_t
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
    ll a,b,c,d = 1; cin >> a >> b >> c;
    rep(i,b)d *= c;
    if(a < d)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}