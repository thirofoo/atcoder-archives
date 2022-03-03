/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abl/submissions/29824305
 * Submitted at: 2022-03-03 18:41:30
 * Problem URL: https://atcoder.jp/contests/abl/tasks/abl_a
 * Result: AC
 * Execution Time: 10 ms
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
    int k; cin >> k;
    string ans = "";
    rep(i,k)ans += "ACL";
    cout << ans << endl;
    return 0;
}