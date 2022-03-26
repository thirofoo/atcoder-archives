/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc073/submissions/30410198
 * Submitted at: 2022-03-26 11:41:12
 * Problem URL: https://atcoder.jp/contests/abc073/tasks/abc073_b
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
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    int ans = 0;
    rep(i,n){
        int l,r; cin >> l >> r;
        ans += r-l+1;
    }
    cout << ans << endl;
    return 0;
}