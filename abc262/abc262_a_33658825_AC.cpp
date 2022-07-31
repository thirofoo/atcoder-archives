/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/33658825
 * Submitted at: 2022-07-31 21:02:11
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_a
 * Result: AC
 * Execution Time: 6 ms
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
    
    ll y; cin >> y;
    if(y%4 <= 2)cout << y+2-y%4 << endl;
    else cout << y+3 << endl;
    
    return 0;
}