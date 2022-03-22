/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30347572
 * Submitted at: 2022-03-22 18:54:53
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_t
 * Result: AC
 * Execution Time: 14 ms
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
    ll a,b,c; cin >> a >> b >> c;
    if(a < powl(c,b))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}