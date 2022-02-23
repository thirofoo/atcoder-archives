/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/29606799
 * Submitted at: 2022-02-23 21:05:02
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_a
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
    int n; cin >> n;
    if(n%100 == 0)cout << n/100 << endl;
    else cout << n/100+1 << endl;
    return 0;
}