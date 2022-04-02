/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc140/submissions/30622788
 * Submitted at: 2022-04-02 18:46:32
 * Problem URL: https://atcoder.jp/contests/abc140/tasks/abc140_c
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
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> b(n,INT_MAX);
    rep(i,n-1)cin >> b[i];

    int ans = b[0];
    for(int i=1;i<n;i++){
        ans += min(b[i-1],b[i]);
    }
    cout << ans << endl;
    return 0;
}