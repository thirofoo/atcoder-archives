/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc071/submissions/29606936
 * Submitted at: 2022-02-23 21:10:31
 * Problem URL: https://atcoder.jp/contests/abc071/tasks/abc071_a
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
    int x,a,b; cin >> x >> a >> b;
    cout << (abs(x-a) > abs(x-b) ? "B" : "A") << endl;
    return 0;
}