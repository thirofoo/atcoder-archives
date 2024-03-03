/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50861555
 * Submitted at: 2024-03-03 12:25:01
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_e
 * Result: AC
 * Execution Time: 44 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    const ll n = 7;
    ll v1, v2, v3; cin >> v1 >> v2 >> v3;
    ll a1 = 0, b1 = 0, c1 = 0, cnt1, cnt2, cnt3;
    reps(a2,-n,n+1) reps(b2,-n,n+1) reps(c2,-n,n+1) {
        reps(a3,-n,n+1) reps(b3,-n,n+1) reps(c3,-n,n+1) {
            // 幾何包除で重なりを求める
            cnt2 = max(0ll, n-abs(a1-a2)) * max(0ll, n-abs(b1-b2)) * max(0ll, n-abs(c1-c2));
            cnt2 += max(0ll, n-abs(a1-a3)) * max(0ll, n-abs(b1-b3)) * max(0ll, n-abs(c1-c3));
            cnt2 += max(0ll, n-abs(a2-a3)) * max(0ll, n-abs(b2-b3)) * max(0ll, n-abs(c2-c3));
            cnt3 = max(0ll, n-(max({a1,a2,a3})-min({a1,a2,a3}))) * max(0ll, n-(max({b1,b2,b3})-min({b1,b2,b3}))) * max(0ll, n-(max({c1,c2,c3})-min({c1,c2,c3})));

            cnt2 -= cnt3*3;
            cnt1 = n*n*n*3 - cnt2*2 - cnt3*3;

            if( cnt1 == v1 && cnt2 == v2 && cnt3 == v3 ) {
                cout << "Yes" << endl;
                cout << a1 << " " << b1 << " " << c1 << " ";
                cout << a2 << " " << b2 << " " << c2 << " ";
                cout << a3 << " " << b3 << " " << c3 << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}