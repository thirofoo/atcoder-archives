/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28486247
 * Submitted at: 2022-01-13 10:29:17
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_al
 * Result: AC
 * Execution Time: 7 ms
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
    if(ans <= 1000000000000000000LL/b)cout << ans*b << endl;
    else cout << "Large" << endl;
    return 0;
}