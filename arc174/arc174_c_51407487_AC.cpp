/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc174/submissions/51407487
 * Submitted at: 2024-03-18 10:27:23
 * Problem URL: https://atcoder.jp/contests/arc174/tasks/arc174_c
 * Result: AC
 * Execution Time: 315 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<mint> f1(n+1,0), f2(n+1,0);
    for(ll i=n-1; i>=0; i--) {
        mint p1 = mint(i)/n;
        mint p2 = mint(n-i)/n;
        mint pn = mint(1) / (1-p1*p1);
        f1[i] = pn*(p2*f2[i+1] + p1*p2*f1[i+1] + p1);
        f2[i] = pn*(p2*f1[i+1] + p1*p2*f2[i+1] + p1*p1);
    }
    cout << f1[0].val() << " " << f2[0].val() << '\n';
    
    return 0;
}