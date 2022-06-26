/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc143/submissions/32779359
 * Submitted at: 2022-06-26 22:20:45
 * Problem URL: https://atcoder.jp/contests/arc143/tasks/arc143_b
 * Result: AC
 * Execution Time: 59 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<mint> kaizyo(n*n+1,0);
    kaizyo[0] = 1;
    rep(i,n*n)kaizyo[i+1] = kaizyo[i]*(i+1);
    mint ans = kaizyo[n*n];
    for(int i=n;i<=n*n-n+1;i++){
        mint tmp = kaizyo[i-1]/kaizyo[(i-1)-(n-1)];
        tmp *= kaizyo[n*n-i]/kaizyo[(n*n-i)-(n-1)];
        tmp *= (mint)n; tmp *= (mint)n;
        tmp *= kaizyo[(n-1)*(n-1)];
        ans -= tmp;
    }
    cout << ans.val() << endl;

    return 0;
}