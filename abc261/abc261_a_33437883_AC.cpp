/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/33437883
 * Submitted at: 2022-07-23 21:08:23
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_a
 * Result: AC
 * Execution Time: 12 ms
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
    if(l2 < l1){
        swap(l1,l2);
        swap(r1,r2);
    }

    ll ans = min(r1,r2)-l2;
    cout << (ans < 0 ? 0 : ans) << endl;
    
    return 0;
}