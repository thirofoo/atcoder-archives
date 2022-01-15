/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/28534672
 * Submitted at: 2022-01-15 21:07:02
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_b
 * Result: AC
 * Execution Time: 41 ms
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
    vector<int> height(n);
    rep(i,n)cin >> height[i];
    int ans = height[0];
    rep(i,n-1){
        if(height[i] >= height[i+1])break;
        else ans = height[i+1];
    }
    cout << ans << endl;
    return 0;
}