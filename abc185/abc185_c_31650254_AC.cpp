/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/31650254
 * Submitted at: 2022-05-14 17:26:47
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_c
 * Result: AC
 * Execution Time: 5 ms
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
    
    ll l,ans = 1; cin >> l;
    rep(i,11){
        ans *= l-1-i;
        ans /= i+1;
    }
    cout << ans << endl;
    return 0;
}