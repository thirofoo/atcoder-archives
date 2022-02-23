/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc208/submissions/29599471
 * Submitted at: 2022-02-23 14:26:51
 * Problem URL: https://atcoder.jp/contests/abc208/tasks/abc208_a
 * Result: AC
 * Execution Time: 8 ms
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
    int a,b; cin >> a >> b;
    if(a <= b && b <= a*6)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}