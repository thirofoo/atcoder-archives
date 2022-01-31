/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/28975217
 * Submitted at: 2022-01-31 20:21:09
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_c
 * Result: WA
 * Execution Time: 2205 ms
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
    cout << setprecision(10);
    ll n,ans = 0; cin >> n;
    for(int a=1;a<=pow(n,(double)1/3);a++){
        for(int b=a;b<=pow(n/a,(double)1/2);b++){
            ans += n/a/b-b+1;
        }
    }
    cout << ans << endl;
    return 0;
}