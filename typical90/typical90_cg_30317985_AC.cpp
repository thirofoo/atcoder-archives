/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30317985
 * Submitted at: 2022-03-21 11:32:45
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cg
 * Result: AC
 * Execution Time: 1159 ms
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
    ll k; cin >> k;
    ll ans = 0;
    for(ll a=1;a*a*a<=k;a++){
        for(ll b=a;a*b*b<=k;b++){
            if(k % (a*b) == 0 && k/(a*b) >= b)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}