/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc045/submissions/33218796
 * Submitted at: 2022-07-14 18:16:11
 * Problem URL: https://atcoder.jp/contests/abc045/tasks/abc045_a
 * Result: AC
 * Execution Time: 5 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    double a,b,h; cin >> a >> b >> h;
    cout << (a+b)*h/2 << endl;
    
    return 0;
}