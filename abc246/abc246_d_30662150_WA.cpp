/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/30662150
 * Submitted at: 2022-04-02 22:14:39
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_d
 * Result: WA
 * Execution Time: 11 ms
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
    if(n == 0 || n == 1)return cout << n << endl,0;
    ll tmp = cbrt(n);
    tmp++;

    ll ans = 0;
    for(int i=0;i<=tmp;i++){
        ll a = i*i*i+i*i*(tmp-i)+i*(tmp-i)*(tmp-i)+(tmp-i)*(tmp-i)*(tmp-i);
        if(a < n)continue;

        if(ans == 0)ans = a;
        else ans = (ans-n <= a-n ? ans : a);
    }
    cout << ans << endl;
    return 0;
}