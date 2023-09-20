/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/45740312
 * Submitted at: 2023-09-20 09:47:33
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_c
 * Result: AC
 * Execution Time: 96 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll ans = 0;
    for(ll a=1;a<=cbrt(n)+5;a++) {
        for(ll b=a;b<=sqrt(n/a)+5;b++) {
            ans += max(n/(a*b) - b + 1, 0ll);
        }
    }
    cout << ans << endl;
    
    return 0;
}