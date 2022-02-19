/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/29435603
 * Submitted at: 2022-02-19 21:07:39
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_b
 * Result: AC
 * Execution Time: 7 ms
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
    ll x; cin >> x;
    if(x >= 0 || x%10 == 0)cout << x/10 << endl;
    else cout << (x/10)-1 << endl;
    return 0;
}