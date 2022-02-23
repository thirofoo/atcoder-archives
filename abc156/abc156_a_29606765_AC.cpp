/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc156/submissions/29606765
 * Submitted at: 2022-02-23 21:03:49
 * Problem URL: https://atcoder.jp/contests/abc156/tasks/abc156_a
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
    int n,r; cin >> n >> r;
    if(n >= 10)cout << r << endl;
    else cout << r+100*(10-n) << endl;
    return 0;
}