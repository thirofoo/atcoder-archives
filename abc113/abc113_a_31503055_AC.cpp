/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc113/submissions/31503055
 * Submitted at: 2022-05-08 10:57:41
 * Problem URL: https://atcoder.jp/contests/abc113/tasks/abc113_a
 * Result: AC
 * Execution Time: 3 ms
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
    
    int x,y; cin >> x >> y;
    cout << x + y/2 << endl;
    return 0;
}