/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc217/submissions/29139154
 * Submitted at: 2022-02-07 12:36:38
 * Problem URL: https://atcoder.jp/contests/abc217/tasks/abc217_c
 * Result: AC
 * Execution Time: 64 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> ans(n);
    for(int i=1;i<=n;i++){
        int tmp; cin >> tmp;
        ans[tmp-1] = i;
    }
    rep(i,n)cout << ans[i] << " ";
    cout << endl;
    return 0;
}