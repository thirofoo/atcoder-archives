/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc178/submissions/30021440
 * Submitted at: 2022-03-12 17:20:03
 * Problem URL: https://atcoder.jp/contests/abc178/tasks/abc178_c
 * Result: AC
 * Execution Time: 7 ms
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

int mod = 1000000007;

int main() {
    ll n; cin >> n;
    ll ans = pow_mod(10,n,mod)-pow_mod(9,n,mod)*2+pow_mod(8,n,mod);
    ans %= mod;
    cout << (ans+mod)%mod << endl;
    return 0;
}