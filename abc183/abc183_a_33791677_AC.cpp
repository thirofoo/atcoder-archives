/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/33791677
 * Submitted at: 2022-08-06 11:19:26
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_a
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll x; cin >> x;
    if(x >= 0)cout << x << endl;
    else cout << 0 << endl;
    
    return 0;
}