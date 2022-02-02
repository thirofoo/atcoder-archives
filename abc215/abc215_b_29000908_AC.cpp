/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc215/submissions/29000908
 * Submitted at: 2022-02-02 12:03:59
 * Problem URL: https://atcoder.jp/contests/abc215/tasks/abc215_b
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
    ll n; cin >> n;
    int ans = 0;
    rep(i,63){
        if((1LL << i) <= n)ans = i;
        else break;
    }
    cout << ans << endl;
    return 0;
}