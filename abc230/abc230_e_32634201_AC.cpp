/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/32634201
 * Submitted at: 2022-06-21 11:07:21
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_e
 * Result: AC
 * Execution Time: 23 ms
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
    
    ll n,ans = 0; cin >> n;
    rep(i,(ll)sqrt(n)){
        ans += (ll)floor(n/(i+1))-(ll)sqrt(n);
    }
    ans *= 2; ans += pow((ll)sqrt(n),2);
    cout << ans << endl;

    return 0;
}