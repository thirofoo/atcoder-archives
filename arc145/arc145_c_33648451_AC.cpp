/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc145/submissions/33648451
 * Submitted at: 2022-07-31 12:55:58
 * Problem URL: https://atcoder.jp/contests/arc145/tasks/arc145_c
 * Result: AC
 * Execution Time: 10 ms
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
    
    ll n; cin >> n;

    //今回の答えは、2^n * n! * カタラン数n = 2^n * n! * 2n_C_n
    // = 2^n * (2n)! / (n+1)!
    mint ans = 1;
    rep(i,n)ans *= 2;
    vector<mint> kaizyo(2*n+1);
    kaizyo[0] = 1;
    rep(i,2*n)kaizyo[i+1] = kaizyo[i]*(i+1);

    ans *= kaizyo[2*n];
    ans /= kaizyo[n+1];

    cout << ans.val() << endl;
    
    return 0;
}