/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc238/submissions/29151268
 * Submitted at: 2022-02-08 00:03:12
 * Problem URL: https://atcoder.jp/contests/abc238/tasks/abc238_d
 * Result: WA
 * Execution Time: 243 ms
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
    int t; cin >> t;
    rep(i,t){
        ll a,s; cin >> a >> s;
        if(s > 2*a && ((s-a*2)&a) == 0)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}