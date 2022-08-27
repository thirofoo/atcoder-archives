/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34372425
 * Submitted at: 2022-08-27 21:03:38
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_b
 * Result: AC
 * Execution Time: 15 ms
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

ll mod = 998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    cout << (n%mod + mod) % mod << endl;
    
    return 0;
}