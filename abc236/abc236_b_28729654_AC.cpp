/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc236/submissions/28729654
 * Submitted at: 2022-01-23 21:07:33
 * Problem URL: https://atcoder.jp/contests/abc236/tasks/abc236_b
 * Result: AC
 * Execution Time: 83 ms
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
    vector<int> ans(n,0);
    rep(i,4*n-1){
        int a; cin >> a;
        ans[a-1]++;
    }
    cout << find(ans.begin(),ans.end(),3)-ans.begin() + 1 << endl;
    return 0;
}