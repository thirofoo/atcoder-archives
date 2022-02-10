/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc209/submissions/29200571
 * Submitted at: 2022-02-10 21:29:33
 * Problem URL: https://atcoder.jp/contests/abc209/tasks/abc209_b
 * Result: WA
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,x,ans = 0; cin >> n >> x;
    rep(i,n){
        int a; cin >> a;
        ans += a;
    }
    if(ans+n/2 > x)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}