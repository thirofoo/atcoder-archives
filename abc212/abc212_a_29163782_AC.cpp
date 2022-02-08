/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc212/submissions/29163782
 * Submitted at: 2022-02-08 19:56:21
 * Problem URL: https://atcoder.jp/contests/abc212/tasks/abc212_a
 * Result: AC
 * Execution Time: 6 ms
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
    if(a == 0)cout << "Silver" << endl;
    else if(b == 0)cout << "Gold" << endl;
    else cout << "Alloy" << endl;
    return 0;
}