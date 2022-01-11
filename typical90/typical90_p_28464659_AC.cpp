/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28464659
 * Submitted at: 2022-01-11 19:11:59
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_p
 * Result: AC
 * Execution Time: 445 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,a,b,c; cin >> n >> a >> b >> c;
    ll ans = 10000;
    rep(i,9999){
        rep(j,9999){
            if(i+j > 9999 || (n-(a*i+b*j))%c != 0  || (n-(a*i+b*j)) < 0)continue;
            ans = min(ans,i+j+(n-(a*i+b*j))/c);
        }
    }
    cout << ans << endl;
    return 0;
}