/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30346585
 * Submitted at: 2022-03-22 18:03:29
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_p
 * Result: AC
 * Execution Time: 419 ms
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
    int n,a,b,c; cin >> n >> a >> b >> c;
    ll ans = LLONG_MAX;
    for(ll i=9999;i>=0;i--){
        for(ll j=9999-i;j>=0;j--){
            if(n-a*i-b*j >= 0 && (n-a*i-b*j)%c == 0){
                ans = min(ans,i+j+(n-a*i-b*j)/c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}