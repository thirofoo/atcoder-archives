/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc139/submissions/31249659
 * Submitted at: 2022-04-24 23:59:28
 * Problem URL: https://atcoder.jp/contests/arc139/tasks/arc139_a
 * Result: AC
 * Execution Time: 32 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n; cin >> n;
    vector<ll> t(n);
    rep(i,n)cin >> t[i];
    ll cnt,ans = 1LL << t[0];
    for(int i=1;i<n;i++){
        ll tmp1 = (ans/(1LL << t[i]) + 1)*(1LL << t[i]);
        ll tmp2 = tmp1 + (1LL << t[i]);
        ans = (tmp1%(1LL << (t[i]+1)) == 0 ? tmp2 : tmp1);
    }
    cout << ans << endl;
    return 0;
}