/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/33429196
 * Submitted at: 2022-07-23 21:01:04
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_a
 * Result: WA
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
    if(r1 < l2)cout << 0 << endl;
    else cout << r1-l2 << endl;
    
    return 0;
}