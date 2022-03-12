/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc178/submissions/30020678
 * Submitted at: 2022-03-12 16:51:33
 * Problem URL: https://atcoder.jp/contests/abc178/tasks/abc178_b
 * Result: AC
 * Execution Time: 19 ms
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
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll x = max(b*c,b*d);
    ll y = max(a*d,x);
    cout << (ll)max(a*c,y) << endl;
    return 0;
}