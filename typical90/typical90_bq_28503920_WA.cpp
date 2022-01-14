/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28503920
 * Submitted at: 2022-01-14 16:27:08
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bq
 * Result: WA
 * Execution Time: 2205 ms
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

int s = 1000000007;

int main() {
    int n,k; cin >> n >> k;
    if(n <= 2) return cout << k*(k-1) << endl,0;
    else{
        ll ans = k*(k-1);
        rep(i,n-2)(ans *= (k-2)) %= s;
        cout << ans << endl;
    }
    return 0;
}