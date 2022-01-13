/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28486116
 * Submitted at: 2022-01-13 10:09:57
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_al
 * Result: WA
 * Execution Time: 8 ms
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

ll euclid(ll a,ll b){
    if(b != 0) return euclid(b,a%b);
    return a;
}

int main() {
    ll a,b; cin >> a >> b;
    ll ans = a/euclid(a,b);
    if(ans > 1e18/b)cout << "Large" << endl;
    else cout << ans << endl;
    return 0;
}