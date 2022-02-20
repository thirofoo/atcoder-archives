/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/29503925
 * Submitted at: 2022-02-20 21:01:49
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_a
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
    if(abs(a-b) == 1 || (a == 1 && b == 10) || (a == 10 && b == 1))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}