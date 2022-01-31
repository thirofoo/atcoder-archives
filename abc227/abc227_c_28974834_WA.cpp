/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/28974834
 * Submitted at: 2022-01-31 19:54:35
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_c
 * Result: WA
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,ans = 0; cin >> n;
    for(ll a=1;a<=pow(n,(double)1/3);a++){
        for(ll b=a;b<=pow(n/a,(double)1/2);b++){
            ans += floor(n/(a*b))-b+1;
        }
    }
    cout << ans << endl;
    return 0;
}